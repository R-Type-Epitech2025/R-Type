#!/bin/bash

# color variables
RED='\033[0;31m'
GREEN='\033[0;32m'
WHITE='\033[0m'
YELLOW='\033[1;33m'

# check if apt installed
if ! [ -x "$(command -v apt-get)" ]; then
    echo -e "${RED}apt-get is not installed.${WHITE}" >&2
else
    # install autoconf-archive
    echo -e "${GREEN}Installing autoconf-archive...${WHITE}"
    sudo apt-get install autoconf-archive
    echo -e "${GREEN}autoconf-archive installed.${WHITE}"
fi

# check if brew installed
if ! [ -x "$(command -v brew)" ]; then
    echo -e "${RED}brew is not installed.${WHITE}" >&2
else
    # install autoconf-archive
    echo -e "${GREEN}Installing autoconf-archive...${WHITE}"
    brew install autoconf-archive
    echo -e "${GREEN}autoconf-archive installed.${WHITE}"
fi

# check if pacman installed
if ! [ -x "$(command -v pacman)" ]; then
    echo -e "${RED}pacman is not installed.${WHITE}" >&2
else
    # install autoconf-archive
    echo -e "${GREEN}Installing autoconf-archive...${WHITE}"
    sudo pacman -S autoconf-archive
    echo -e "${GREEN}autoconf-archive installed.${WHITE}"
fi

# check if yum installed
if ! [ -x "$(command -v yum)" ]; then
    echo -e "${RED}yum is not installed.${WHITE}" >&2
else
    # install autoconf-archive
    echo -e "${GREEN}Installing autoconf-archive...${WHITE}"
    sudo yum install autoconf-archive
    echo -e "${GREEN}autoconf-archive installed.${WHITE}"
fi

# check if dnf installed
if ! [ -x "$(command -v dnf)" ]; then
    echo -e "${RED}dnf is not installed.${WHITE}" >&2
else
    # install autoconf-archive
    echo -e "${GREEN}Installing autoconf-archive...${WHITE}"
    sudo dnf install autoconf-archive
    echo -e "${GREEN}autoconf-archive installed.${WHITE}"
fi

# check if zypper installed
if ! [ -x "$(command -v zypper)" ]; then
    echo -e "${RED}zypper is not installed.${WHITE}" >&2
else
    # install autoconf-archive
    echo -e "${GREEN}Installing autoconf-archive...${WHITE}"
    sudo zypper install autoconf-archive
    echo -e "${GREEN}autoconf-archive installed.${WHITE}"
fi


cmake > /dev/null

if [ $? -ne 0 ]; then
    echo -e "${RED}CMake is not installed.${WHITE}" >&2
    echo -e "${GREEN}Installing CMake...${WHITE}"
    curl -L https://github.com/Kitware/CMake/releases/download/v3.25.1/cmake-3.25.1-linux-aarch64.sh -o cmake.sh
    chmod +x cmake.sh
    sudo ./cmake.sh --skip-license --prefix=/usr/local
    rm cmake.sh
    echo -e "${GREEN}CMake installed.${WHITE}"
else
    echo -e "${RED}CMake is already installed.${WHITE}"
fi

echo -e "${GREEN}Installing packages...${WHITE}"
if ! [ -x "$(command -v bison)" ]; then
    echo -e "${RED}bison is not installed." >&2
    echo -e "${GREEN}Installing bison...${WHITE}"
    wget http://ftp.gnu.org/gnu/bison/bison-2.3.tar.gz
    tar -xzf bison-2.3.tar.gz
    cd bison-2.3
    ./configure
    # --prefix=/usr/local/bison --with-libiconv-prefix=/usr/local/libiconv/
    make
    sudo make install
    if ! echo "$PATH" | grep -q "/usr/local/bin"; then
        echo "Ajout de /usr/local/bin au PATH..."
        sudo export PATH=$PATH:/usr/local/bin
    fi
    echo -e "${GREEN}bison installed.${WHITE}"
    cd ..
else
  echo -e "${RED}bison is already installed.${WHITE}"
fi

# check if vcpkg is installed
if [ ! -d "vcpkg" ]; then
    echo "vcpkg n'est pas installé. Installation en cours..."
    git clone https://github.com/Microsoft/vcpkg.git
    sudo ./vcpkg/bootstrap-vcpkg.sh -disableMetrics
    echo "vcpkg installed"
else
    echo "vcpkg est déjà installé."
fi

echo -e "${GREEN}Installing packages...${WHITE}"
echo -e "Installing ${YELLOW}SFML${WHITE}..."
sudo ./vcpkg/vcpkg install sfml
echo -e "${YELLOW}SFML${WHITE} installed."
echo -e "Installing ${YELLOW}Qt5${WHITE}..."
sudo ./vcpkg/vcpkg install qt5-base --recurse --keep-going
echo -e "${YELLOW}Qt5${WHITE} installed."