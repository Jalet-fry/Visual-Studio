# Скрипт для удаления папок .git в подпапках

Write-Host "`nПоиск и удаление папок .git...`n" -ForegroundColor Green

# Получаем все папки .git (рекурсивно)
$gitFolders = Get-ChildItem -Directory -Recurse -Force -Hidden -Filter ".git" | Select-Object -ExpandProperty FullName

if ($gitFolders.Count -eq 0) {
    Write-Host "Папки .git не найдены." -ForegroundColor Yellow
    exit
}

foreach ($folder in $gitFolders) {
    try {
        Write-Host "Удаление: $folder" -ForegroundColor Cyan
        Remove-Item -Path $folder -Recurse -Force -ErrorAction Stop
        Write-Host "Успешно удалено" -ForegroundColor Green
    }
    catch {
        Write-Host "Ошибка при удалении $folder : $_" -ForegroundColor Red
    }
}

Write-Host "`nГотово! Удалено $($gitFolders.Count) папок .git." -ForegroundColor Green