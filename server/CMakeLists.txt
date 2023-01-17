cmake_minimum_required(VERSION 3.1.0)

project(R-Type VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_AUTOMOC ON)

set(CMAKE_PREFIX_PATH $ENV{HOME}/Qt/5.15.2/gcc_64)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Core REQUIRED)
find_package(Qt5 COMPONENTS Network REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(server
    src/server.cpp
)

target_link_libraries(server Qt5::Core Qt5::Network)

add_executable(client
    src/client.cpp
)

target_link_libraries(client Qt5::Widgets Qt5::Core Qt5::Network)