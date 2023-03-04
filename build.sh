#!/bin/bash

# color variables
RED='\033[0;31m'
GREEN='\033[0;32m'
WHITE='\033[0m'
YELLOW='\033[1;33m'

OS=$(uname -s)
COMPILED=false
LOGFILE="build.log"

PWD=$(pwd)

# CMake compilation
cd server
echo -e "${GREEN}Compilation du ${YELLOW}serveur${GREEN}...${WHITE}"
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=../vcpkg/scripts/buildsystems/vcpkg.cmake &> $LOGFILE
cmake --build build -v &> $LOGFILE
cd build
make doc &> $LOGFILE
cd ../../client
echo -e "${GREEN}Compilation du ${YELLOW}client${GREEN}...${WHITE}"
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=../vcpkg/scripts/buildsystems/vcpkg.cmake &> $LOGFILE
cmake --build build -v &> $LOGFILE
cd build
make doc &> $LOGFILE
cd ../../
cp client/bin/R-Type_Server ./build/R-Type_Server
cp client/bin/R-Type_Client ./build/R-Type_Client
cp client/assets ./build/assets
echo -e "${GREEN}Compilation terminée.${WHITE}"

# CPack Build for Windows on NSIS
if [ $OS == "MINGW64_NT-10.0" ] && [ $COMPILED == false ]; then
    echo -e "${GREEN}Build du ${YELLOW}client${GREEN}...${WHITE}"
    cd client/build
    cpack -G NSIS &> $LOGFILE
    echo -e "${GREEN}Build du ${YELLOW}serveur${GREEN}...${WHITE}"
    cd ../../server/build
    cpack -G NSIS &> $LOGFILE
    echo -e "${GREEN}Build terminée.${WHITE}"
    COMPILED=true
fi

# CPack Build for Linux on DEB
if [ $OS == "Linux" ] && [ $COMPILED == false ]; then
    echo -e "${GREEN}Build du ${YELLOW}client${GREEN}...${WHITE}"
    cd client/build
    cpack -G DEB &> $LOGFILE
    echo -e "${GREEN}Build du ${YELLOW}serveur${GREEN}...${WHITE}"
    cd ../../server/build
    cpack -G DEB &> $LOGFILE
    echo -e "${GREEN}Build terminée.${WHITE}"
fi

# CPack Build for MacOS on DMG
if [ $OS == "Darwin" ] && [ $COMPILED == false ]; then
    echo -e "${GREEN}Build du ${YELLOW}client${GREEN}...${WHITE} pour ${YELLOW}MacOS${WHITE}"
    cd client/build
    cpack -G DragNDrop &> $LOGFILE
    echo -e "${GREEN}Build du ${YELLOW}serveur${GREEN}...${WHITE}"
    cd ../../server/build
    cpack -G DragNDrop &> $LOGFILE
    echo -e "${GREEN}Build terminée.${WHITE}"
fi

# CPack Build for Linux on RPM
if [ $OS == "Linux" ] && [ $COMPILED == false ]; then
    echo -e "${GREEN}Build du ${YELLOW}client${GREEN}...${WHITE}"
    cd client/build
    cpack -G RPM &> $LOGFILE
    echo -e "${GREEN}Build du ${YELLOW}serveur${GREEN}...${WHITE}"
    cd ../../server/build
    cpack -G RPM &> $LOGFILE
    echo -e "${GREEN}Build terminée.${WHITE}"
fi

# CPack Build universal for Linux and MacOS on ZIP
if [ COMPILED == false ]; then
    echo -e "${GREEN}Build du ${YELLOW}client${GREEN}...${WHITE}"
    cd client/build
    cpack -G ZIP &> $LOGFILE
    echo -e "${GREEN}Build du ${YELLOW}serveur${GREEN}...${WHITE}"
    cd ../../server/build
    cpack -G ZIP &> $LOGFILE
    echo -e "${GREEN}Build terminée.${WHITE}"
fi
