@echo off
cls

ping 8.8.8.8 -n 1 -w 5000 >nul

if errorlevel 1 (
    echo [101;93m No internet connection [0m
    echo [93mPlease connect to the internet and try again[0m
    exit /b 1
) else (
    echo [92mInternet connection is available[0m
)

git --version >nul

if %errorlevel% neq 0 (
    echo [101;93m git is missing [0m
    echo [93mInstalling git[0m
    
    echo [34;102mgit just installed[0m
) else (
    echo [92mgit already installed[0m
)

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

cmake --version >nul

if %errorlevel% neq 0 (
    echo [101;93m Cmake is missing [0m
    echo [93mInstalling Cmake[0m
    choco install cmake --installargs 'ADD_CMAKE_TO_PATH=System'
    echo [34;102mCmake just installed[0m
) else (
    echo [92mCmake already installed[0m
)

if not exist ".\vcpkg" (
    echo [101;93m vcpkg is missing [0m
    echo [93mInstalling vcpkg[0m
    git clone https://github.com/Microsoft/vcpkg.git
    call .\vcpkg\bootstrap-vcpkg.bat
    echo [34;102mvcpkg just installed and configured[0m
) else (
    echo [92mvcpkg already installed[0m
)

echo [93mInstalling dependencies[0m
echo [93mInstalling Qt5[0m
.\vcpkg\vcpkg install qt5-base
echo [34;102mQt5 installed[0m
.\vcpkg\vcpkg install sfml:x64-windows
.\vcpkg\vcpkg integrate install
echo [34;102msfml installed[0m

echo [93mCompilation en cours...[0m
cd src_build_test
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=..\vcpkg\scripts\buildsystems\vcpkg.cmake -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
echo [34;102mCompilation terminee.[0m