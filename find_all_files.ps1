# Укажите путь к корневой папке
$targetPath = "C:\Users\Vitos\source\repos"

# Укажите путь к анализируемой папке
# $targetPath = "C:\Your\Folder\Path"

# 1. Сбор всех файлов (с обработкой ошибок и прогресс-баром)
Write-Host "`n🔍 Сканирование файловой структуры..." -ForegroundColor Cyan
$allFiles = Get-ChildItem -Path $targetPath -File -Recurse -Force -ErrorAction SilentlyContinue | 
            ForEach-Object -Begin { $i = 0; $total = (Get-ChildItem -Path $targetPath -File -Recurse | Measure-Object).Count } -Process {
                $i++
                Write-Progress -Activity "Обработка файлов" -Status "$i из ~$total" -PercentComplete ($i/$total*100)
                $_
            }

# 2. Группировка по расширениям
$extStats = $allFiles | Group-Object -Property { if ($_.Extension) { $_.Extension.ToLower() } else { "<без расширения>" } } |
            Sort-Object -Property Count -Descending |
            Select-Object @{Name="Расширение"; Expression={$_.Name}}, 
                         @{Name="Количество"; Expression={$_.Count}},
                         @{Name="Примеры"; Expression={($_.Group | Select-Object -First 3 | ForEach-Object Name) -join ", "}}

# 3. Вывод полной таблицы
Clear-Host
Write-Host "📊 Полный список расширений файлов в: '$targetPath'" -ForegroundColor Magenta
Write-Host "Всего файлов: $($allFiles.Count)" -ForegroundColor Yellow
Write-Host "Уникальных расширений: $($extStats.Count)`n" -ForegroundColor Yellow

# Форматированная таблица с разбивкой на колонки
$extStats | Format-Table -AutoSize -Wrap @(
    @{Label="№"; Expression={($extStats.IndexOf($_)+1)}; Alignment="Right"},
    @{Label="Расширение"; Expression={$_.Расширение}; Width=20},
    @{Label="Количество"; Expression={$_.Количество}; Alignment="Right"},
    @{Label="Примеры файлов"; Expression={$_.Примеры}; Width=50}
)

# 4. Дополнительная статистика
Write-Host "`n📌 Дополнительная статистика:" -ForegroundColor Green
Write-Host "• Файлов без расширения: $(($extStats | Where-Object { $_.Расширение -eq '<без расширения>' }).Количество)"
Write-Host "• Самые частые расширения: $($extStats[0].Расширение) ($($extStats[0].Количество)), $($extStats[1].Расширение) ($($extStats[1].Количество))"
Write-Host "• Самые редкие расширения: $($extStats[-1].Расширение) ($($extStats[-1].Количество)), $($extStats[-2].Расширение) ($($extStats[-2].Количество))"