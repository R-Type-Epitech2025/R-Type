@echo off


set OS=%(uname -s)%

set RED='\033[0;31m'
set GREEN='\033[0;32m'
set WHITE='\033[0m'
set YELLOW='\033[1;33m'
set COMPILED=false

set MYROOT= echo %cd%

rem Install NSIS if needed
if "%OS%" == "AMD64" (
    if not exist "%ProgramFiles(x86)%\NSIS\makensis.exe" (
        rem echo Installation de NSIS...
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
if [ %OS% == "MINGW64_NT-10.0" ] && [ $COMPILED == false ] (
    echo -e "%{GREEN}% Build du %{YELLOW}% client %{GREEN}% ...%{WHITE}%"
    cd build
    cpack -G NSIS
    echo -e "%{GREEN}%Build terminée.%{WHITE}%"
    COMPILED=true
)

rem CPack Build universal for Linux and MacOS on ZIP
if not %COMPILED%==true (
    echo Build du client...
    cd build
    cpack -G ZIP
    echo Build terminee.
)

cd %{MYROOT}%
echo %cd%
cd ../../
cd server
echo -e "%{GREEN}%Compilation du %{YELLOW}%server%{GREEN}%...%{WHITE}%"
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=../vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build build -v
echo -e "%{GREEN}%Compilation terminée.%{WHITE}%"
rem CPack Build for Windows on NSIS
if [ %OS% == "MINGW64_NT-10.0" ] && [ $COMPILED == false ] (
    echo -e "%{GREEN}%Build du %{YELLOW}%server%{GREEN}%...%{WHITE}%"
    cd build
    cpack -G NSIS
    echo "%{GREEN}%  Build terminée.%{WHITE}%"
    cd ../../
    )

