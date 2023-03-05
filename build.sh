#!/bin/bash

# color variables
RED='\033[0;31m'
GREEN='\033[0;32m'
WHITE='\033[0m'
YELLOW='\033[1;33m'

OS=$(uname -s)
COMPILED=false
LOGFILE="build.log"

BASE_PWD=$(pwd)
CLIENT_PWD=$BASE_PWD/client
SERVER_PWD=$BASE_PWD/server
BUILD_PWD=$BASE_PWD/build
CLIENT_BUILD_PWD=$CLIENT_PWD/build
SERVER_BUILD_PWD=$SERVER_PWD/build
CLIENT_BIN_PWD=$CLIENT_PWD/bin
SERVER_BIN_PWD=$SERVER_PWD/bin
CLIENT_ASSETS_PWD=$CLIENT_PWD/assets

# CMake compilation
cd $SERVER_PWD
echo -e "${GREEN}Compilation du ${YELLOW}serveur${GREEN}...${WHITE}"
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=../vcpkg/scripts/buildsystems/vcpkg.cmake &> $LOGFILE
cmake --build build -v &> $LOGFILE
cd $SERVER_BUILD_PWD
make doc &> $LOGFILE
cd $CLIENT_PWD
echo -e "${GREEN}Compilation du ${YELLOW}client${GREEN}...${WHITE}"
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=../vcpkg/scripts/buildsystems/vcpkg.cmake &> $LOGFILE
cmake --build build -v &> $LOGFILE
cd $CLIENT_BUILD_PWD
make doc &> $LOGFILE
cd $BASE_PWD
cp $SERVER_BIN_PWD/R-Type_Server $BUILD_PWD/R-Type_Server
cp $CLIENT_BIN_PWD/R-Type_Client $BUILD_PWD/R-Type_Client
rm -rf $BUILD_PWD/assets
cp -r $CLIENT_ASSETS_PWD $BUILD_PWD/assets
echo -e "${GREEN}Compilation terminée.${WHITE}"

# CPack Build for Windows on NSIS
if [ $OS == "MINGW64_NT-10.0" ] && [ $COMPILED == false ]; then
    echo -e "${GREEN}Build du ${YELLOW}client${GREEN}...${WHITE}"
    cd $CLIENT_BUILD_PWD
    cpack -G NSIS &> $LOGFILE
    echo -e "${GREEN}Build du ${YELLOW}serveur${GREEN}...${WHITE}"
    cd $SERVER_BUILD_PWD
    cpack -G NSIS &> $LOGFILE
    echo -e "${GREEN}Build terminée.${WHITE}"
    COMPILED=true
fi

# CPack Build for Linux on DEB
if [ $OS == "Linux" ] && [ $COMPILED == false ]; then
    echo -e "${GREEN}Build du ${YELLOW}client${GREEN}...${WHITE}"
    cd $CLIENT_BUILD_PWD
    cpack -G DEB &> $LOGFILE
    echo -e "${GREEN}Build du ${YELLOW}serveur${GREEN}...${WHITE}"
    cd $SERVER_BUILD_PWD
    cpack -G DEB &> $LOGFILE
    echo -e "${GREEN}Build terminée.${WHITE}"
fi

# CPack Build for MacOS on DMG
if [ $OS == "Darwin" ] && [ $COMPILED == false ]; then
    echo -e "${GREEN}Build du ${YELLOW}client${GREEN}...${WHITE} pour ${YELLOW}MacOS${WHITE}"
    cd $CLIENT_BUILD_PWD
    cpack -G DragNDrop &> $LOGFILE
    echo -e "${GREEN}Build du ${YELLOW}serveur${GREEN}...${WHITE}"
    cd $SERVER_BUILD_PWD
    cpack -G DragNDrop &> $LOGFILE
    echo -e "${GREEN}Build terminée.${WHITE}"
fi

# CPack Build for Linux on RPM
if [ $OS == "Linux" ] && [ $COMPILED == false ]; then
    echo -e "${GREEN}Build du ${YELLOW}client${GREEN}...${WHITE}"
    cd $CLIENT_BUILD_PWD
    cpack -G RPM &> $LOGFILE
    echo -e "${GREEN}Build du ${YELLOW}serveur${GREEN}...${WHITE}"
    cd $SERVER_BUILD_PWD
    cpack -G RPM &> $LOGFILE
    echo -e "${GREEN}Build terminée.${WHITE}"
fi

# CPack Build universal for Linux and MacOS on ZIP
if [ COMPILED == false ]; then
    echo -e "${GREEN}Build du ${YELLOW}client${GREEN}...${WHITE}"
    cd $CLIENT_BUILD_PWD
    cpack -G ZIP &> $LOGFILE
    echo -e "${GREEN}Build du ${YELLOW}serveur${GREEN}...${WHITE}"
    cd $SERVER_BUILD_PWD
    cpack -G ZIP &> $LOGFILE
    echo -e "${GREEN}Build terminée.${WHITE}"
fi
