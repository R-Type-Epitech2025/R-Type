#!/bin/bash

# color variables
RED='\033[0;31m'
GREEN='\033[0;32m'
WHITE='\033[0m'
YELLOW='\033[1;33m'

# boolean variables
INSTALLED=false

LOGFILE="install.log"

# check if user is root
if [ "$EUID" -ne 0 ]
  then echo -e "${RED}Please run as root${WHITE}"
  exit
fi

# check if user is connected to internet
if ! ping -c 1 google.com &> $LOGFILE
then
    echo -e "${RED}Please connect to internet${WHITE}"
    exit
fi

# check if apt installed
if ! [ -x "$(command -v apt-get)" ]; then
    echo -e "${RED}apt-get is not installed.${WHITE}" >&2
elif [ "$INSTALLED" = false ]; then
    # install automake
    echo -e "${GREEN}Installing automake by ${YELLOW}apt-get${GREEN}...${WHITE}"
    sudo apt-get install automake &> $LOGFILE
    echo -e "${GREEN}automake installed.${WHITE}"
    # install curl
    echo -e "${GREEN}Installing curl by ${YELLOW}apt-get${GREEN}...${WHITE}"
    sudo apt-get install curl &> $LOGFILE
    echo -e "${GREEN}curl installed.${WHITE}"
    # install doxygen
    echo -e "${GREEN}Installing doxygen by ${YELLOW}apt-get${GREEN}...${WHITE}"
    sudo apt-get install doxygen &> $LOGFILE
    echo -e "${GREEN}doxygen installed.${WHITE}"
    INSTALLED=true
fi

# check if brew installed
if ! [ -x "$(command -v brew)" ]; then
    echo -e "${RED}brew is not installed.${WHITE}" >&2
elif [ "$INSTALLED" = false ]; then
    # install automake
    echo -e "${GREEN}Installing automake by ${YELLOW}brew${GREEN}...${WHITE}"
    brew install automake &> $LOGFILE
    echo -e "${GREEN}automake installed.${WHITE}"
    # install curl
    echo -e "${GREEN}Installing curl by ${YELLOW}brew${GREEN}...${WHITE}"
    brew install curl &> $LOGFILE
    echo -e "${GREEN}curl installed.${WHITE}"
    # install doxygen
    echo -e "${GREEN}Installing doxygen by ${YELLOW}brew${GREEN}...${WHITE}"
    brew install doxygen &> $LOGFILE
    INSTALLED=true
fi

# check if pacman installed
if ! [ -x "$(command -v pacman)" ]; then
    echo -e "${RED}pacman is not installed.${WHITE}" >&2
elif [ "$INSTALLED" = false ]; then
    # install automake
    echo -e "${GREEN}Installing automake by ${YELLOW}pacman${GREEN}...${WHITE}"
    sudo pacman -S automake &> $LOGFILE
    echo -e "${GREEN}automake installed.${WHITE}"
    # install curl
    echo -e "${GREEN}Installing curl by ${YELLOW}pacman${GREEN}...${WHITE}"
    sudo pacman -S curl &> $LOGFILE
    echo -e "${GREEN}curl installed.${WHITE}"
    # install doxygen
    echo -e "${GREEN}Installing doxygen by ${YELLOW}pacman${GREEN}...${WHITE}"
    sudo pacman -S doxygen &> $LOGFILE
    INSTALLED=true
fi

# check if yum installed
if ! [ -x "$(command -v yum)" ]; then
    echo -e "${RED}yum is not installed.${WHITE}" >&2
elif [ "$INSTALLED" = false ]; then
    # install automake
    echo -e "${GREEN}Installing automake by ${YELLOW}yum${GREEN}...${WHITE}"
    sudo yum install automake &> $LOGFILE
    echo -e "${GREEN}automake installed.${WHITE}"
    # install curl
    echo -e "${GREEN}Installing curl by ${YELLOW}yum${GREEN}...${WHITE}"
    sudo yum install curl &> $LOGFILE
    echo -e "${GREEN}curl installed.${WHITE}"
    # install doxygen
    echo -e "${GREEN}Installing doxygen by ${YELLOW}yum${GREEN}...${WHITE}"
    sudo yum install doxygen &> $LOGFILE
    echo -e "${GREEN}doxygen installed.${WHITE}"
    INSTALLED=true
fi

# check if dnf installed
if ! [ -x "$(command -v dnf)" ]; then
    echo -e "${RED}dnf is not installed.${WHITE}" >&2
elif [ "$INSTALLED" = false ]; then
    # install automake
    echo -e "${GREEN}Installing automake by ${YELLOW}dnf${GREEN}...${WHITE}"
    sudo dnf install automake &> $LOGFILE
    echo -e "${GREEN}automake installed.${WHITE}"
    # install curl
    echo -e "${GREEN}Installing curl by ${YELLOW}dnf${GREEN}...${WHITE}"
    sudo dnf install curl &> $LOGFILE
    echo -e "${GREEN}curl installed.${WHITE}"
    # install doxygen
    echo -e "${GREEN}Installing doxygen by ${YELLOW}dnf${GREEN}...${WHITE}"
    sudo dnf install doxygen &> $LOGFILE
    echo -e "${GREEN}doxygen installed.${WHITE}"
    INSTALLED=true
fi

# check if zypper installed
if ! [ -x "$(command -v zypper)" ]; then
    echo -e "${RED}zypper is not installed.${WHITE}" >&2
elif [ "$INSTALLED" = false ]; then
    # install automake
    echo -e "${GREEN}Installing automake by ${YELLOW}zypper${GREEN}...${WHITE}"
    sudo zypper install automake &> $LOGFILE
    echo -e "${GREEN}automake installed.${WHITE}"
    # install curl
    echo -e "${GREEN}Installing curl by ${YELLOW}zypper${GREEN}...${WHITE}"
    sudo zypper install curl &> $LOGFILE
    echo -e "${GREEN}curl installed.${WHITE}"
    # install doxygen
    echo -e "${GREEN}Installing doxygen by ${YELLOW}zypper${GREEN}...${WHITE}"
    sudo zypper install doxygen &> $LOGFILE
    INSTALLED=true
fi

if [ $? -ne 0 ]; then
    echo -e "${RED}CMake is not installed.${WHITE}" >&2
    echo -e "${GREEN}Installing CMake...${WHITE}"
    curl -L https://github.com/Kitware/CMake/releases/download/v3.25.1/cmake-3.25.1-linux-aarch64.sh -o cmake.sh &> $LOGFILE
    chmod +x cmake.sh &> $LOGFILE
    sudo ./cmake.sh --skip-license --prefix=/usr/local &> $LOGFILE
    rm cmake.sh &> $LOGFILE
    echo -e "${GREEN}CMake installed.${WHITE}"
else
    echo -e "${GREEN}CMake is already installed.${WHITE}"
fi

echo -e "${GREEN}Check if bison is installed...${WHITE}"
if ! [ -x "$(command -v bison)" ]; then
    echo -e "${RED}bison is not installed."
    echo -e "${GREEN}Installing bison...${WHITE}"
    wget http://ftp.gnu.org/gnu/bison/bison-2.3.tar.gz &> $LOGFILE
    tar -xzf bison-2.3.tar.gz &> $LOGFILE
    cd bison-2.3 &> $LOGFILE
    ./configure &> $LOGFILE
    # --prefix=/usr/local/bison --with-libiconv-prefix=/usr/local/libiconv/
    make &> $LOGFILE
    sudo make install &> $LOGFILE
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
    # create vcpkg directory if not exists
    if [ ! -d "~/.vcpkg" ]; then
        mkdir ~/.vcpkg
    fi
    # clone vcpkg without logs
    git clone https://github.com/Microsoft/vcpkg.git &> $LOGFILE
    sudo ./vcpkg/bootstrap-vcpkg.sh -disableMetrics &> $LOGFILE
    echo -e "${GREEN}vcpkg installé.${WHITE}"
    # add vcpkg to PATH
    export PATH=$PATH:$PWD/vcpkg
else
    echo -e "${GREEN}vcpkg est déjà installé.${WHITE}"
    # add vcpkg to PATH
    export PATH=$PATH:$PWD/vcpkg
fi

echo -e "${GREEN}Installing packages...${WHITE}"
echo -e "Installing ${YELLOW}SFML${WHITE}..."
vcpkg install sfml &> $LOGFILE
echo -e "${YELLOW}SFML${WHITE} installed."
echo -e "Installing ${YELLOW}Qt5${WHITE}..."
vcpkg install qt5-base --recurse --keep-going &> $LOGFILE
echo -e "${YELLOW}Qt5${WHITE} installed."

vcpkg integrate install