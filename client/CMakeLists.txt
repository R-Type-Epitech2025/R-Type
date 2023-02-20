cmake_minimum_required(VERSION 3.0)
project(rtype)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable(${PROJECT_NAME})

# Adding QT5 dependencies

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)

target_sources(${PROJECT_NAME} 
    PRIVATE
    Archi/main.cpp
    Archi/components/Scene.cpp
    Archi/components/Entity.cpp
    Archi/components/GraphicComponent.cpp
    Archi/components/GameComponent.cpp
    Archi/components/MovementComponent.cpp
    Archi/systems/MovementSystem.cpp
    Archi/components/Scene.cpp
    Archi/Include/SceneManager.cpp
    Archi/systems/GraphicSystem.cpp
    Archi/components/EventComponent.cpp
    )

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-network sfml-graphics sfml-window)