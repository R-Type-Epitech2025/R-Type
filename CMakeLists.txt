cmake_minimum_required(VERSION 3.0)
project(rtype)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# qt_wrap_cpp(MOC_FILES
# )

# Adding QT5 dependencies
add_executable(${PROJECT_NAME}
    # ${MOC_FILES}
    main.cpp
)

find_package(Qt5 COMPONENTS Core Network REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core Qt5::Network)