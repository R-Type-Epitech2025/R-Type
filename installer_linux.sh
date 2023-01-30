#!/bin/bash



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


wget https://xcb.freedesktop.org/dist/libxcb-1.14.tar.gz

# Extract the downloaded archive
tar xvf libxcb-1.14.tar.gz
cd libxcb-1.14

# Compile and install the library
./configure
make
sudo make install

# Clean up
cd ..
rm -rf libxcb-1.14
rm libxcb-1.14.tar.gz

#wget https://github.com/unicode-org/icu/releases/download/release-72-1/icu4c-72_1-src.tgz
# tar -xzf icu4c-72_1-src.tgz
# cd icu/source
# ./configure --prefix=/usr/local/icu
# make
# sudo make install
echo "Checking if vcpkg is installed...\n"

if [ ! -d "vcpkg" ]; then
    echo "vcpkg n'est pas installé. Installation en cours..."
    git clone https://github.com/Microsoft/vcpkg.git
    sudo ./vcpkg/bootstrap-vcpkg.sh -disableMetrics
    echo "vcpkg installed"
    echo "Installing packages..."
    echo "Installing SFML..."
    sudo ./vcpkg/vcpkg install libxkbcommon
    sudo ./vcpkg/vcpkg install libxrender
    sudo ./vcpkg/vcpkg install libxi
    sudo ./vcpkg/vcpkg install libxext
    sudo ./vcpkg/vcpkg install freetype
    sudo ./vcpkg/vcpkg install icu
    sudo ./vcpkg/vcpkg install fontconfig
    sudo ./vcpkg/vcpkg install sfml
    echo "SFML installed."
    echo "Installing Qt5..."
    sudo ./vcpkg/vcpkg install qt5-base --recurse
    echo "Qt5 installed."
else
    echo "vcpkg est déjà installé."
    echo "Installing packages..."
    echo "Installing SFML..."
    echo "SFML installed."
    echo "Installing Qt5..."
    ./vcpkg/vcpkg install qt5
    ./vcpkg/vcpkg install sfml
    echo "Qt5 installed."
fi