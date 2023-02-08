cmake_minimum_required(VERSION 3.0)
project(rtype)

set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable(${PROJECT_NAME})

# Adding QT5 dependencies
find_package(Qt5 COMPONENTS Core Network REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core Qt5::Network)

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)


target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-network sfml-graphics sfml-window)

SET(LATEX_OUTPUT_PATH build)
INCLUDE(CMakeFiles/UseLATEX.cmake)

file(GLOB_RECURSE contents_files RELATIVE ${CMAKE_SOURCE_DIR} contents/*.tex)

ADD_LATEX_DOCUMENT(
    RFC.tex
    INPUTS ${contents_files}
    IMAGE_DIRS images
    USE_INDEX
    USE_GLOSSARY
    FILTER_OUTPUT
    )