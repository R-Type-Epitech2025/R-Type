#!/bin/bash

# check if apt installed
if ! [ -x "$(command -v apt-get)" ]; then
    echo "Error: apt-get is not installed." >&2
else
    # install autoconf-archive
    echo "Installing autoconf-archive..."
    sudo apt-get install autoconf-archive
    echo "autoconf-archive installed."
fi

# check if brew installed
if ! [ -x "$(command -v brew)" ]; then
    echo "Error: brew is not installed." >&2
else
    # install autoconf-archive
    echo "Installing autoconf-archive..."
    brew install autoconf-archive
    echo "autoconf-archive installed."
fi

# check if pacman installed
if ! [ -x "$(command -v pacman)" ]; then
    echo "Error: pacman is not installed." >&2
else
    # install autoconf-archive
    echo "Installing autoconf-archive..."
    sudo pacman -S autoconf-archive
    echo "autoconf-archive installed."
fi

# check if yum installed
if ! [ -x "$(command -v yum)" ]; then
    echo "Error: yum is not installed." >&2
else
    # install autoconf-archive
    echo "Installing autoconf-archive..."
    sudo yum install autoconf-archive
    echo "autoconf-archive installed."
fi

# check if dnf installed
if ! [ -x "$(command -v dnf)" ]; then
    echo "Error: dnf is not installed." >&2
else
    # install autoconf-archive
    echo "Installing autoconf-archive..."
    sudo dnf install autoconf-archive
    echo "autoconf-archive installed."
fi

# check if zypper installed
if ! [ -x "$(command -v zypper)" ]; then
    echo "Error: zypper is not installed." >&2
else
    # install autoconf-archive
    echo "Installing autoconf-archive..."
    sudo zypper install autoconf-archive
    echo "autoconf-archive installed."
fi


cmake > /dev/null

if [ $? -ne 0 ]; then
    echo "CMake is not installed.\n"
    echo "Insatlling CMake...\n"
    curl -L https://github.com/Kitware/CMake/releases/download/v3.25.1/cmake-3.25.1-linux-aarch64.sh -o cmake.sh
    chmod +x cmake.sh
    sudo ./cmake.sh --skip-license --prefix=/usr/local
    rm cmake.sh
    echo "CMake installed.\n"
else
    echo "CMake is already installed.\n"
fi

echo "Checking if bison is installed...\n"
if ! [ -x "$(command -v bison)" ]; then
    echo 'Error: bison is not installed.' >&2
    echo "Installing bison..."
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
    echo "bison installed."
    cd ..
else
  echo "bison is already installed."
fi

# check if autoconf is installed
echo "Checking if autoconf is installed...\n"
if ! [ -x "$(command -v autoconf)" ]; then
    echo 'Error: autoconf is not installed.' >&2
    echo "Installing autoconf..."
    sudo wget http://ftp.gnu.org/gnu/autoconf/autoconf-2.69.tar.gz
    sudo tar -xzf autoconf-2.69.tar.gz
    cd autoconf-2.69
    sudo ./configure
    sudo make
    sudo make install
    echo "autoconf installed."
    cd ..
else
  echo "autoconf is already installed."
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

echo "Installing packages..."
echo "Installing SFML..."
sudo ./vcpkg/vcpkg install sfml
echo "SFML installed."
echo "Installing Qt5..."
sudo ./vcpkg/vcpkg install qt5-base --recurse --keep-going
echo "Qt5 installed."