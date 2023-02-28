cmake_minimum_required(VERSION 3.0)
project(rtype)

set(PROJECT_NAME R-Type)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# adding include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(RESOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/assets)

set(SRC_FILES
    src/main.cpp
    src/ecs/components/Scene.cpp
    src/ecs/Entity.cpp
    src/ecs/components/GraphicComponent.cpp
    src/ecs/components/GameComponent.cpp
    src/ecs/components/MovementComponent.cpp
    src/systems/MovementSystem.cpp
    src/ecs/components/Scene.cpp
    src/ecs/SceneManager.cpp
    src/systems/GraphicSystem.cpp
    src/ecs/components/EventComponent.cpp
)

add_executable(${PROJECT_NAME} ${SRC_FILES})

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
    set(CPACK_PACKAGE_NAME "r-type")
    set(CPACK_PACKAGE_FILE_NAME "rtype_install")
    set(CPACK_NSIS_INSTALLED_ICON_NAME "bin\\\\rtype.exe")
    set(CPACK_NSIS_HELP_LINK "https://github.com/r-type")
    set(CPACK_NSIS_URL_INFO_ABOUT "https://github.com/r-type")
    set(CPACK_NSIS_CONTACT "r-type@github.com")
    set(CPACK_NSIS_ENABLE_UNINSTALL_BEFORE_INSTALL ON)
    set(CPACK_NSIS_MENU_LINKS "bin\\\\rtype.exe" "RType 0.1.1")
elseif(APPLE)
    # Setting up the CPack generator for MacOS
    set(CPACK_GENERATOR DragNDrop)
    set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
    set(CPACK_PROJECT_NAME "R-Type")
    set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}")
    set(CPACK_PACKAGE_ICON ${CMAKE_CURRENT_SOURCE_DIR}/icon.icns)
elseif(UNIX AND NOT APPLE)
    # Setting up the CPack generator for Debian
    set(CPACK_GENERATOR DEB)
    set(CPACK_PACKAGE_NAME "r-type")
    set(CPACK_DEBIAN_PACKAGE_MAINTAINER "RType Team")
elseif(UNIX)
    # Setting up the CPack generator for RPM
    set(CPACK_GENERATOR RPM)
    set(CPACK_PACKAGE_NAME "r-type")
    set(CPACK_RPM_PACKAGE_MAINTAINER "RType Team")
endif()

set(CPACK_PACKAGE_VERSION_MAJOR ${VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${VERSION_MINOR})
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "RType installer")
include(CPack)

# Setting up the install targets
install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin)
install(FILES README.md
        DESTINATION .)
install(PROGRAMS ${CMAKE_CURRENT_SOURCE_DIR}/build.sh
        DESTINATION .)
# Adding assets to the install target
install(DIRECTORY ${RESOURCES_DIR}
        DESTINATION .)

# Adding -g3 if in debug mode
if(CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_options(${PROJECT_NAME} PRIVATE -g3)
endif()