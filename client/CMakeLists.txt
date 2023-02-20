cmake_minimum_required(VERSION 3.0)
project(rtype)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# adding include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(RESOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/resources)

add_executable(${PROJECT_NAME} src/ecs/main.cpp)

# Adding QT5 dependencies
find_package(Qt5 COMPONENTS Core Network REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core)

# Adding SFML dependencies
find_package(SFML COMPONENTS system window graphics REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-window sfml-graphics)

# Ajouter les includes pour SFML
target_include_directories(${PROJECT_NAME} 
    PRIVATE
    ${SFML_INCLUDE_DIRS})

# Setting up the CPack generator for Windows
if(WIN32)
    set(CPACK_GENERATOR NSIS)
    set(CPACK_PACKAGE_NAME "RType")
elseif(APPLE)
    # Setting up the CPack generator for MacOS
    set(CPACK_GENERATOR DragNDrop)
    set(CPACK_PACKAGE_NAME "RType")
    set(CPACK_PACKAGE_ICON ${CMAKE_CURRENT_SOURCE_DIR}/icon.icns)
elseif(UNIX AND NOT APPLE)
    # Setting up the CPack generator for Debian
    set(CPACK_GENERATOR DEB)
    set(CPACK_PACKAGE_NAME "r-type")
    set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Your Name")
elseif(UNIX)
    # Setting up the CPack generator for RPM
    set(CPACK_GENERATOR RPM)
    set(CPACK_PACKAGE_NAME "r-type")
    set(CPACK_RPM_PACKAGE_MAINTAINER "Your Name")
endif()

set(CPACK_PACKAGE_VERSION_MAJOR ${VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${VERSION_MINOR})
set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "RType installer")
include(CPack)

# Setting up the install targets
install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin)
install(FILES README.md
        DESTINATION .)
install(PROGRAMS ${CMAKE_CURRENT_SOURCE_DIR}/build.sh
        DESTINATION .)
