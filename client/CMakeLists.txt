cmake_minimum_required(VERSION 3.0)
project(rtype)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable(${PROJECT_NAME})

# Adding QT5 dependencies
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)

target_sources(${PROJECT_NAME} 
    PRIVATE
    src/main.cpp
    src/ecs/components/Scene.cpp
    src/ecs/Entity.cpp
    src/ecs/components/GraphicComponent.cpp
    src/ecs/components/GameComponent.cpp
    src/ecs/components/MovementComponent.cpp
    src/systems/MovementSystem.cpp
    src/ecs/components/Scene.cpp
    src/SceneManager.cpp
    src/systems/GraphicSystem.cpp
    src/ecs/components/EventComponent.cpp
    )

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-network sfml-graphics sfml-window)




