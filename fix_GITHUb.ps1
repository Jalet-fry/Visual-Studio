# Скрипт для исправления репозиториев без коммитов

# 1. Проверяем Git и GitHub CLI
if (-not (Get-Command git -ErrorAction SilentlyContinue)) {
    Write-Host "Git не установлен!" -ForegroundColor Red
    exit
}

if (-not (Get-Command gh -ErrorAction SilentlyContinue)) {
    Write-Host "GitHub CLI (gh) не установлен!" -ForegroundColor Red
    exit
}

# 2. Проверяем аутентификацию
try {
    $user = gh api user -q ".login" 2>$null
    if (-not $user) {
        Write-Host "Сначала выполните: gh auth login" -ForegroundColor Yellow
        exit
    }
} catch {
    Write-Host "Ошибка аутентификации GitHub" -ForegroundColor Red
    exit
}

# 3. Основной процесс
Get-ChildItem -Directory | ForEach-Object {
    $projectName = $_.Name
    Set-Location $_.FullName
    
    Write-Host "`nПроверяем проект: $projectName" -ForegroundColor Magenta

    # Проверяем, есть ли .git
    if (-not (Test-Path -Path ".git")) {
        Write-Host "Не Git-репозиторий" -ForegroundColor Yellow
        Set-Location ..
        return
    }

    # Проверяем коммиты
    $hasCommits = git rev-list --count HEAD 2>$null
    if ($hasCommits -eq 0) {
        Write-Host "Нет коммитов" -ForegroundColor Red
        
        # Создаём README, если папка пуста
        if (-not (Get-ChildItem -Force | Where-Object { $_.Name -notmatch '^\.git$' })) {
            "# $projectName" | Out-File "README.md" -Encoding utf8
            Write-Host "Создан README.md" -ForegroundColor Cyan
        }

        git add .
        git commit -m "Initial commit" 2>$null
        Write-Host "Создан первый коммит" -ForegroundColor Green
    }

    # Работа с ветками
    $currentBranch = git branch --show-current
    if ($currentBranch -eq "master") {
        git branch -m main 2>$null
        Write-Host "Переименовано master → main" -ForegroundColor Cyan
    }

    # Пуш на GitHub
    try {
        $remote = git remote get-url origin 2>$null
        if (-not $remote) {
            gh repo create $projectName --public --confirm --source=. --remote=origin
        }
        
        git push -u origin main --force
        Write-Host "Код загружен на GitHub" -ForegroundColor Green
    } catch {
        Write-Host "Ошибка: $_" -ForegroundColor Red
    }

    Set-Location ..
}

Write-Host "`nГотово! Все репозитории проверены." -ForegroundColor Green