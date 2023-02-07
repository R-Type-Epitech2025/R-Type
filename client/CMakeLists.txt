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

target_sources(${PROJECT_NAME} 
    PRIVATE
    src/ecs/components/MovementManager.cpp
     src/ecs/Entity.cpp
     src/ecs/main.cpp
     src/systems/EventSystem.cpp
     src/systems/GraphicSystem.cpp )


target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-network sfml-graphics sfml-window)