# Скрипт для рекурсивного обхода папок и вывода их содержимого

# Получаем все подпапки (рекурсивно) в текущей директории
$allFolders = Get-ChildItem -Directory -Recurse

# Добавляем текущую папку в начало списка
$allFolders = @( (Get-Item .) ) + $allFolders

Write-Host "`nНачинаем рекурсивный обход папок...`n" -ForegroundColor Green

foreach ($folder in $allFolders) {
    # Вычисляем отступ для визуального отображения вложенности
    $depth = ($folder.FullName.Split('\').Count - 1) - (Get-Location).Path.Split('\').Count
    $indent = '  ' * $depth
    
    Write-Host "${indent}Папка: $($folder.FullName)" -ForegroundColor Yellow
    
    # Выводим содержимое папки
    $items = Get-ChildItem -Path $folder.FullName
    if ($items) {
        foreach ($item in $items) {
            Write-Host "${indent}  $($item.Name)" -ForegroundColor Cyan
        }
    } else {
        Write-Host "${indent}  [папка пуста]" -ForegroundColor Gray
    }
    
    Write-Host ""
}

Write-Host "Обход завершен. Всего папок: $($allFolders.Count)" -ForegroundColor Green