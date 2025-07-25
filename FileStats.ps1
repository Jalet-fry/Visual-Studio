<#
.SYNOPSIS
Анализирует и выводит статистику по расширениям файлов в указанной директории

.DESCRIPTION
Скрипт рекурсивно сканирует указанную папку, собирает статистику по типам файлов
и выводит отчет в удобном табличном формате с дополнительной аналитикой
#>

param (
    [string]$targetPath = "C:\Users\Vitos\source\repos"
)

# 1. Инициализация и проверка пути
if (-not (Test-Path -Path $targetPath)) {
    Write-Host "❌ Ошибка: Указанный путь не существует!" -ForegroundColor Red
    exit 1
}

# 2. Сбор данных с прогресс-баром
Write-Host "`n🔍 Сканирование файловой структуры в '$targetPath'..." -ForegroundColor Cyan

try {
    # Получаем файлы с обработкой ошибок
    $allFiles = @(Get-ChildItem -Path $targetPath -File -Recurse -Force -ErrorAction Stop)
    
    # Прогресс-бар
    $totalFiles = $allFiles.Count
    $counter = 0
    
    $extStats = $allFiles | ForEach-Object {
        $counter++
        if ($totalFiles -gt 1000 -and $counter % 100 -eq 0) {
            $percent = [math]::Min(100, [int]($counter/$totalFiles*100))
            Write-Progress -Activity "Анализ файлов" -Status "$counter из $totalFiles" -PercentComplete $percent
        }
        
        # Возвращаем объект для группировки
        $_
    } | Group-Object -Property { 
        if ($_.Extension) { $_.Extension.ToLower() } 
        else { "<без расширения>" } 
    } | Sort-Object -Property Count -Descending
}
catch {
    Write-Host "❌ Ошибка при сканировании: $_" -ForegroundColor Red
    exit 1
}

# 3. Формирование отчета
Clear-Host
Write-Host "📊 Файловая статистика для: '$targetPath'" -ForegroundColor Magenta
Write-Host ("═" * ($Host.UI.RawUI.BufferSize.Width - 1))

# Основная таблица
$report = $extStats | Select-Object @(
    @{Name="№"; Expression={$extStats.IndexOf($_)+1}},
    @{Name="Расширение"; Expression={$_.Name}},
    @{Name="Количество"; Expression={$_.Count}},
    @{Name="Доля"; Expression={"{0:P1}" -f ($_.Count/$totalFiles)}},
    @{Name="Примеры"; Expression={($_.Group | Select-Object -First 3).Name -join ", "}}
)

$report | Format-Table -AutoSize -Wrap -Property @(
    @{Label="№"; Expression={$_."№"}; Alignment="Right"; Width=4},
    @{Label="Расширение"; Expression={$_.Расширение}; Width=20},
    @{Label="Количество"; Expression={$_.Количество}; Alignment="Right"; Width=12},
    @{Label="Доля"; Expression={$_.Доля}; Alignment="Right"; Width=10},
    @{Label="Примеры файлов"; Expression={$_.Примеры}; Width=40}
)

# 4. Детальная статистика
Write-Host "`n📌 Детальная статистика:" -ForegroundColor Green
Write-Host "• Всего файлов: $totalFiles" -ForegroundColor Yellow
Write-Host "• Уникальных расширений: $($extStats.Count)" -ForegroundColor Yellow
Write-Host "• Файлов без расширения: $(($extStats | Where-Object { $_.Name -eq '<без расширения>' }).Count)" -ForegroundColor Yellow

$topExtensions = $extStats | Select-Object -First 5
Write-Host "`n🏆 Топ-5 расширений:" -ForegroundColor Cyan
$topExtensions | ForEach-Object {
    Write-Host ("  {0,-8} {1,6} файлов ({2:P1})" -f $_.Name, $_.Count, ($_.Count/$totalFiles))
}

# 5. Экспорт результатов (опционально)
$timestamp = Get-Date -Format "yyyyMMdd-HHmmss"
$report | Export-Csv -Path "FileStats_$timestamp.csv" -NoTypeInformation -Encoding UTF8 -Delimiter ";"
Write-Host "`n💾 Результаты сохранены в 'FileStats_$timestamp.csv'" -ForegroundColor DarkGray