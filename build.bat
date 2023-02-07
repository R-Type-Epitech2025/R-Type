@echo off

echo install vcpkg
git clone https://github.com/Microsoft/vcpkg.git

echo config vcpkg
call .\vcpkg\bootstrap-vcpkg.bat

echo install sfml
.\\vcpkg\\vcpkg install sfml:x64-windows
.\\vcpkg\\vcpkg install qt5-base