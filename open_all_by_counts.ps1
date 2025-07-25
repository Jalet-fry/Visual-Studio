# Скрипт для открытия .sln файлов с паузами
$currentDir = "C:\from_github\Visual-Studio"
$slnFiles = Get-ChildItem -Path $currentDir -Recurse -Filter *.sln | Select-Object -ExpandProperty FullName

$batchSize = 4  # Можно изменить на 5 для открытия по 5 файлов
$index = 0

while ($index -lt $slnFiles.Count) {
    # Открываем следующую партию файлов
    for ($i = 0; $i -lt $batchSize -and $index -lt $slnFiles.Count; $i++) {
        $file = $slnFiles[$index]
        Write-Host "Открываю файл: $file"
        Start-Process $file
        $index++
    }
    
    if ($index -lt $slnFiles.Count) {
        # Ждем нажатия Enter перед продолжением
        Write-Host "Нажмите Enter для продолжения (осталось $($slnFiles.Count - $index) файлов)..."
        $null = Read-Host
    }
}

Write-Host "Все .sln файлы обработаны!"