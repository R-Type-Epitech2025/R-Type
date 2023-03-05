@echo off

set OS=%PROCESSOR_ARCHITECTURE%

set COMPILED=false

rem Install NSIS if needed
if "%OS%"=="AMD64" (
    if not exist "%ProgramFiles(x86)%\NSIS\makensis.exe" (
        echo Installation de NSIS...
        curl -Lo nsis-3.06.1-setup.exe "https://sourceforge.net/projects/nsis/files/latest/download"
        start /wait nsis-3.06.1-setup.exe /S
        echo Installation de NSIS terminee.
    )
)

rem CMake compilation
cd client
echo Compilation du client...
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=../vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build build -v
echo Compilation terminee.

rem CPack Build for Windows on NSIS
if "%OS%"=="AMD64" (
    if not %COMPILED%==true (
        echo Build du client...
        cd build
        cpack -G NSIS
        echo Build terminee.
        set COMPILED=true
    )
)

rem CPack Build universal for Linux and MacOS on ZIP
if not %COMPILED%==true (
    echo Build du client...
    cd build
    cpack -G ZIP
    echo Build terminee.
)