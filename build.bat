    @echo off

rem Install Chocolatey

echo check if chocolatey is installed

powershell Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))

. $profile
choco -version

choco install cmake --installargs 'ADD_CMAKE_TO_PATH=System'

git clone https://github.com/Microsoft/vcpkg.git

.\vcpkg\bootstrap-vcpkg.bat

.\vcpkg\vcpkg install sfml:x64-windows
.\vcpkg\vcpkg install qt5-base