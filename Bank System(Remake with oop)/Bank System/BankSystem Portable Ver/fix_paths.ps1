$files = Get-ChildItem -Recurse -Include *.h,*.cpp -Path .

foreach ($file in $files) {
    if ($file.Name -eq "fix_paths.py") { continue }
    if ($file.Name -eq "fix_paths.ps1") { continue }
    
    $content = Get-Content $file.FullName -Raw
    if ($null -eq $content) { continue }
    $originalContent = $content
    
    $content = $content.Replace("E:\projects\c++ course\10-OOP Concepts\Project 2\Project 2\clsString.h", "Lib/clsString.h")
    $content = $content.Replace("E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Utility Library\", "Lib/")
    $content = $content.Replace("E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Input&Validation Library\", "Lib/")
    $content = $content.Replace("E:\projects\c++ course\11 - OOP as it Should Be (Applications)\Bank System(Remake with oop)\Bank System\", "")
    $content = $content.Replace("E:\projects\my library\", "")

    $lines = $content -split "`r`n"
    $newLines = @()
    foreach ($line in $lines) {
        if ($line.Trim().StartsWith("#include")) {
            $line = $line.Replace("\", "/")
        }
        $newLines += $line
    }
    $content = $newLines -join "`r`n"

    if ($content -ne $originalContent) {
        Write-Host "Updating $($file.FullName)"
        Set-Content -Path $file.FullName -Value $content -NoNewline
    }
}
