#!/bin/bash

# color variables
RED='\033[0;31m'
GREEN='\033[0;32m'
WHITE='\033[0m'
YELLOW='\033[1;33m'

OS=$(uname -s)
COMPILED=false

# CMake compilation
cd client
echo -e "${GREEN}Compilation du ${YELLOW}client${GREEN}...${WHITE}"
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=../vcpkg/scripts/buildsystems/vcpkg.cmake &> /dev/null
cmake --build build -v
echo -e "${GREEN}Compilation terminée.${WHITE}"

# CPack Build for Windows on NSIS
#if [ $OS == "MINGW64_NT-10.0" ] && [ $COMPILED == false ]; then
#    echo -e "${GREEN}Build du ${YELLOW}client${GREEN}...${WHITE}"
#    cd build
#    cpack -G NSIS &> /dev/null
#    echo -e "${GREEN}Build terminée.${WHITE}"
#    COMPILED=true
#fi

# CPack Build for Linux on DEB
#if [ $OS == "Linux" ] && [ $COMPILED == false ]; then
#    echo -e "${GREEN}Build du ${YELLOW}client${GREEN}...${WHITE}"
#    cd build
#    cpack -G DEB &> /dev/null
#    echo -e "${GREEN}Build terminée.${WHITE}"
#fi

# CPack Build for MacOS on DMG
#if [ $OS == "Darwin" ] && [ $COMPILED == false ]; then
#    echo -e "${GREEN}Build du ${YELLOW}client${GREEN}...${WHITE} pour ${YELLOW}MacOS${WHITE}"
#    cd build
#    cpack -G DragNDrop
#    hdiutil create -volname R-Type -srcfolder ${APP_NAME}.app -srcfolder assets -ov -format UDZO ${APP_NAME}.dmg
#    echo -e "${GREEN}Build terminée.${WHITE}"
#fi

# CPack Build for Linux on RPM
#if [ $OS == "Linux" ] && [ $COMPILED == false ]; then
#    echo -e "${GREEN}Build du ${YELLOW}client${GREEN}...${WHITE}"
#    cd build
#    cpack -G RPM &> /dev/null
#    echo -e "${GREEN}Build terminée.${WHITE}"
#fi

# CPack Build universal for Linux and MacOS on ZIP
#if [ COMPILED == false ]; then
#    echo -e "${GREEN}Build du ${YELLOW}client${GREEN}...${WHITE}"
#    cd build
#    cpack -G ZIP &> /dev/null
#    echo -e "${GREEN}Build terminée.${WHITE}"
#fi