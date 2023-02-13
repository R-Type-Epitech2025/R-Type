#!/bin/bash

# color variables
RED='\033[0;31m'
GREEN='\033[0;32m'
WHITE='\033[0m'
YELLOW='\033[1;33m'

# check if user is root
if [ "$EUID" -ne 0 ]
  then echo -e "${RED}Please run as root${WHITE}"
  exit
fi

# check if user is connected to internet
if ! ping -c 1 google.com &> /dev/null
then
    echo -e "${RED}Please connect to internet${WHITE}"
    exit
fi

# check if apt installed
if ! [ -x "$(command -v apt-get)" ]; then
    echo -e "${RED}apt-get is not installed.${WHITE}" >&2
else
    # install automake
    echo -e "${GREEN}Installing automake by ${YELLOW}apt-get${GREEN}...${WHITE}"
    sudo apt-get install automake &> /dev/null
    echo -e "${GREEN}automake installed.${WHITE}"
fi

# check if brew installed
if ! [ -x "$(command -v brew)" ]; then
    echo -e "${RED}brew is not installed.${WHITE}" >&2
else
    # install automake
    echo -e "${GREEN}Installing automake by ${YELLOW}brew${GREEN}...${WHITE}"
    brew install automake &> /dev/null
    echo -e "${GREEN}automake installed.${WHITE}"
fi

# check if pacman installed
if ! [ -x "$(command -v pacman)" ]; then
    echo -e "${RED}pacman is not installed.${WHITE}" >&2
else
    # install automake
    echo -e "${GREEN}Installing automake by ${YELLOW}pacman${GREEN}...${WHITE}"
    sudo pacman -S automake &> /dev/null
    echo -e "${GREEN}automake installed.${WHITE}"
fi

# check if yum installed
if ! [ -x "$(command -v yum)" ]; then
    echo -e "${RED}yum is not installed.${WHITE}" >&2
else
    # install automake
    echo -e "${GREEN}Installing automake by ${YELLOW}yum${GREEN}...${WHITE}"
    sudo yum install automake &> /dev/null
    echo -e "${GREEN}automake installed.${WHITE}"
fi

# check if dnf installed
if ! [ -x "$(command -v dnf)" ]; then
    echo -e "${RED}dnf is not installed.${WHITE}" >&2
else
    # install automake
    echo -e "${GREEN}Installing automake by ${YELLOW}dnf${GREEN}...${WHITE}"
    sudo dnf install automake &> /dev/null
    echo -e "${GREEN}automake installed.${WHITE}"
fi

# check if zypper installed
if ! [ -x "$(command -v zypper)" ]; then
    echo -e "${RED}zypper is not installed.${WHITE}" >&2
else
    # install automake
    echo -e "${GREEN}Installing automake by ${YELLOW}zypper${GREEN}...${WHITE}"
    sudo zypper install automake &> /dev/null
    echo -e "${GREEN}automake installed.${WHITE}"
fi

if [ $? -ne 0 ]; then
    echo -e "${RED}CMake is not installed.${WHITE}" >&2
    echo -e "${GREEN}Installing CMake...${WHITE}"
    curl -L https://github.com/Kitware/CMake/releases/download/v3.25.1/cmake-3.25.1-linux-aarch64.sh -o cmake.sh &> /dev/null
    chmod +x cmake.sh &> /dev/null
    sudo ./cmake.sh --skip-license --prefix=/usr/local &> /dev/null
    rm cmake.sh &> /dev/null
    echo -e "${GREEN}CMake installed.${WHITE}"
else
    echo -e "${GREEN}CMake is already installed.${WHITE}"
fi

echo -e "${GREEN}Check if bison is installed...${WHITE}"
if ! [ -x "$(command -v bison)" ]; then
    echo -e "${RED}bison is not installed."
    echo -e "${GREEN}Installing bison...${WHITE}"
    wget http://ftp.gnu.org/gnu/bison/bison-2.3.tar.gz &> /dev/null
    tar -xzf bison-2.3.tar.gz &> /dev/null
    cd bison-2.3 &> /dev/null
    ./configure &> /dev/null
    # --prefix=/usr/local/bison --with-libiconv-prefix=/usr/local/libiconv/
    make &> /dev/null
    sudo make install &> /dev/null
    if ! echo "$PATH" | grep -q "/usr/local/bin"; then
        echo "Ajout de /usr/local/bin au PATH..."
        sudo export PATH=$PATH:/usr/local/bin
    fi
    echo -e "${GREEN}bison installed.${WHITE}"
    cd ..
else
  echo -e "${GREEN} bison est déjà installé.${WHITE}"
fi

# check if vcpkg is installed
if [ ! -d "vcpkg" ]; then
    echo -e "${RED}vcpkg n'est pas installé."
    echo -e "${GREEN}Installation en cours...${WHITE}"
    # clone vcpkg without logs
    git clone https://github.com/Microsoft/vcpkg.git &> /dev/null
    sudo ./vcpkg/bootstrap-vcpkg.sh -disableMetrics &> /dev/null
    echo -e "${GREEN}vcpkg installé.${WHITE}"
else
    echo -e "${GREEN}vcpkg est déjà installé.${WHITE}"
fi

echo -e "${GREEN}Installing packages...${WHITE}"
echo -e "Installing ${YELLOW}SFML${WHITE}..."
sudo ./vcpkg/vcpkg install sfml
echo -e "${YELLOW}SFML${WHITE} installed."
echo -e "Installing ${YELLOW}Qt5${WHITE}..."
sudo ./vcpkg/vcpkg install qt5-base --recurse --keep-going
echo -e "${YELLOW}Qt5${WHITE} installed."

sudo ./vcpkg/vcpkg integrate install

# CMake compilation
echo -e "${GREEN}Compilation en cours...${WHITE}"
cd ecs
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=../vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build build -v
echo -e "${GREEN}Compilation terminée.${WHITE}"