@echo off
cls

echo [93mcheck if chocolatey is installed[0m

where choco >nul

if %errorlevel% neq 0 (
    echo [101;93m choco is missing [0m
    echo [93mInstalling choco[0m
    powershell -NoProfile -ExecutionPolicy Bypass -Command "iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'))" && SET "PATH=%PATH%;%ALLUSERSPROFILE%\chocolatey\bin"
    echo [34;102mchoco just installed[0m
) else (
    echo [92mChocolatey already installed[0m
)

echo [93mInstalling Cmake[0m
choco install cmake --installargs 'ADD_CMAKE_TO_PATH=System'
echo [34;102mCmake just installed[0m

echo [93mCheck if vcpkg is installed[0m

if not exist ".\vcpkg" (
    echo [101;93m vcpkg is missing [0m
    echo [93mInstalling vcpkg[0m
    git clone https://github.com/Microsoft/vcpkg.git
    call .\vcpkg\bootstrap-vcpkg.bat
    echo [34;102mchoco just installed and configured[0m
) else (
    echo [92mvcpkg already installed[0m
)

echo [93mInstalling dependencies[0m
echo [93mInstalling Qt5[0m
.\vcpkg\vcpkg install qt5:x64-windows
echo [34;102mQt5 installed[0m
.\vcpkg\vcpkg install sfml:x64-windows
echo [34;102msfml installed[0m