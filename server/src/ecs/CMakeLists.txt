cmake_minimum_required(VERSION 3.0)
project(rtype)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable(${PROJECT_NAME})

# Adding QT5 dependencies
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core Qt5::Widgets)

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)

target_sources(${PROJECT_NAME} 
    PRIVATE
    systems/GraphicSystem.cpp
    systems/EventSystem.cpp
    components/MovementManager.cpp
    Entity.cpp

    main.cpp )


target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-network sfml-graphics sfml-window)