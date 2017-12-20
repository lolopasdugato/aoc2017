#Specify minimum required version for CMake
cmake_minimum_required(VERSION 3.9.1 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_REQUIRED ON)

#Specify project and identify the language in use)
project(aoc-tests LANGUAGES CXX VERSION 0.1.0)

file(GLOB SOURCES "*.cpp")

#Add program target main
add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
    PUBLIC
    Catch::Test
)
