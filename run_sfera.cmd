@echo off
setlocal
py -3 -c "import iced_x86" >nul 2>nul
if errorlevel 1 (
    echo iced-x86 is missing. Run: py -3 -m pip install -r "%~dp0requirements.txt"
    exit /b 1
)
py -3 "%~dp0decompile.py" "%~dp0Sfera" --input sphereclient_patched.exe
if errorlevel 1 exit /b 1
echo Generated project: %~dp0Sfera\out
endlocal
