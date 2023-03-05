cmake_minimum_required(VERSION 3.0)
project(rtype)

set(PROJECT_NAME R-Type_Client)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# adding include directories
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include/ecs
    ${CMAKE_CURRENT_SOURCE_DIR}/include/ecs/components
    ${CMAKE_CURRENT_SOURCE_DIR}/include/game
    ${CMAKE_CURRENT_SOURCE_DIR}/include/systems
    ${CMAKE_CURRENT_SOURCE_DIR}/include/systems/network
    )

find_package(Qt5 COMPONENTS Core Network REQUIRED)
qt_wrap_cpp(
    MOC_FILES
    include/systems/network/NetworkSystem.hpp
    include/systems/network/UDPSocket.hpp
    include/systems/MovementSystem.hpp
    include/systems/GraphicSystem.hpp
    include/systems/SystemManager.hpp
    include/systems/EventSystem.hpp
)

set(RESOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/assets)

set(SRC_FILES
    src/main.cpp
    src/Core.cpp
    
    src/ecs/Entity.cpp
    src/ecs/SceneManager.cpp
    src/ecs/components/GraphicComponent.cpp
    src/ecs/components/MovementComponent.cpp
    src/ecs/Scene.cpp
    src/ecs/components/EventComponent.cpp
    
    src/systems/SystemManager.cpp
    src/systems/GraphicSystem.cpp
    src/systems/MovementSystem.cpp
    src/systems/EventSystem.cpp
    src/game/ConnectMenu.cpp
    src/game/GameScene.cpp
    src/game/MainMenu.cpp
    src/game/OptionMenu.cpp
    # src/systems/AudioSystem.cpp
    src/systems/network/NetworkSystem.cpp
    src/systems/network/UDPSocket.cpp
    src/systems/network/Message.cpp
)

# add_custom_target(RFC
#     COMMAND pdflatex -output-directory=${CMAKE_CURRENT_SOURCE_DIR}/doc ${CMAKE_CURRENT_SOURCE_DIR}/doc/src/RFC.tex
#     WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/doc
#     COMMENT "Building RFC.pdf"
#     SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/doc/src/RFC.tex
# )

add_executable(${PROJECT_NAME} ${SRC_FILES} ${MOC_FILES})
# add_dependencies(${PROJECT_NAME} RFC)

# Adding QT5 dependencies
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core Qt5::Network)

# Adding SFML dependencies
find_package(SFML COMPONENTS system window graphics REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-window sfml-graphics)

# Ajouter les includes pour SFML
target_include_directories(${PROJECT_NAME} 
    PRIVATE
    ${SFML_INCLUDE_DIRS})

# add doxygen with Doxyfile.in
find_package(Doxygen)
if(DOXYGEN_FOUND)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
    add_custom_target(doc
        ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen" VERBATIM
    )
    add_dependencies(doc HelloWorld)
endif(DOXYGEN_FOUND)

# Setting up CPack
set(CPACK_PACKAGE_NAME "r-type")
set(CPACK_PACKAGE_FILE_NAME "rtype_install")

# Setting up the CPack generator for Windows
if(WIN32)
    set(CPACK_GENERATOR NSIS)
    set(CPACK_NSIS_INSTALLED_ICON_NAME "bin\\\\rtype.exe")
    set(CPACK_NSIS_HELP_LINK "https://github.com/r-type")
    set(CPACK_NSIS_URL_INFO_ABOUT "https://github.com/r-type")
    set(CPACK_NSIS_CONTACT "r-type@github.com")
    set(CPACK_NSIS_ENABLE_UNINSTALL_BEFORE_INSTALL ON)
    set(CPACK_NSIS_MENU_LINKS "bin\\\\rtype.exe" "RType 0.1.1")
elseif(APPLE)
    # Setting up the CPack generator for MacOS
    set(CPACK_GENERATOR DragNDrop)
    set(CPACK_PROJECT_NAME "R-Type")
    set(CPACK_PACKAGE_ICON ${CMAKE_CURRENT_SOURCE_DIR}/icon.icns)
elseif(UNIX AND NOT APPLE)
    # Setting up the CPack generator for Debian
    set(CPACK_GENERATOR DEB)
    set(CPACK_DEBIAN_PACKAGE_MAINTAINER "RType Team")
elseif(UNIX)
    # Setting up the CPack generator for RPM
    set(CPACK_GENERATOR RPM)
    set(CPACK_RPM_PACKAGE_MAINTAINER "RType Team")
endif()

set(CPACK_PACKAGE_VERSION_MAJOR ${VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${VERSION_MINOR})
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "RType installer")
include(CPack)

# Setting up the install targets
install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin)

# Adding -g3 if in debug mode
if(CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_options(${PROJECT_NAME} PRIVATE -g3)
endif()