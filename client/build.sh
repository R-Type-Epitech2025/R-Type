#!/bin/bash

# color variables
RED='\033[0;31m'
GREEN='\033[0;32m'
WHITE='\033[0m'
YELLOW='\033[1;33m'


# CMake compilation
cd client
echo -e "${GREEN}Compilation du ${YELLOW}client${GREEN}...${WHITE}"
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=../vcpkg/scripts/buildsystems/vcpkg.cmake &> /dev/null
cmake --build build -v &> /dev/null
echo -e "${GREEN}Compilation terminée.${WHITE}"

# CPack compilation
echo -e "${GREEN}Compilation du ${YELLOW}client${GREEN}...${WHITE}"
cd build
cpack -G ZIP
echo -e "${GREEN}Compilation terminée.${WHITE}"