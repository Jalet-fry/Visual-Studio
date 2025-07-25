# Скрипт для автоматической инициализации Git и создания публичных репозиториев на GitHub

# 1. Проверяем, что Git и GitHub CLI установлены
if (-not (Get-Command git -ErrorAction SilentlyContinue)) {
    Write-Host "Ошибка: Git не установлен!" -ForegroundColor Red
    exit
}

if (-not (Get-Command gh -ErrorAction SilentlyContinue)) {
    Write-Host "Ошибка: GitHub CLI (gh) не установлен!" -ForegroundColor Red
    Write-Host "Установите его с https://cli.github.com/" -ForegroundColor Yellow
    exit
}

# 2. Проверяем аутентификацию в GitHub CLI
try {
    $user = gh api user -q ".login" 2>$null
    if (-not $user) {
        Write-Host "Ошибка: Не выполнена аутентификация в GitHub CLI" -ForegroundColor Red
        Write-Host "Выполните сначала: gh auth login" -ForegroundColor Yellow
        exit
    }
} catch {
    Write-Host "Ошибка при проверке аутентификации GitHub" -ForegroundColor Red
    exit
}

# 3. Основной процесс
Get-ChildItem -Directory | ForEach-Object {
    $projectName = $_.Name
    Set-Location $_.FullName
    
    Write-Host "`nОбрабатываю проект: $projectName" -ForegroundColor Magenta
    
    # Инициализация Git
    if (Test-Path -Path ".git") {
        Write-Host "Git уже инициализирован в $projectName" -ForegroundColor Yellow
    } else {
        git init
        git add .
        git commit -m "Initial commit"
        Write-Host "Git инициализирован и создан первый коммит" -ForegroundColor Green
    }
    
    # Создание публичного репозитория на GitHub
    try {
        gh repo create $projectName --public --confirm --source=. --remote=origin
        git push -u origin main
        Write-Host "Публичный репозиторий $projectName создан на GitHub!" -ForegroundColor Green
        Write-Host "Ссылка: https://github.com/$user/$projectName" -ForegroundColor Cyan
    } catch {
        Write-Host "Ошибка при создании репозитория для $projectName" -ForegroundColor Red
        Write-Host $_.Exception.Message -ForegroundColor Red
    }
    
    Set-Location ..
}

Write-Host "`nГотово! Все проекты обработаны." -ForegroundColor Green