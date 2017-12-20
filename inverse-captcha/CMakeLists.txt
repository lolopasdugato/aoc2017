#Specify minimum required version for CMake
cmake_minimum_required(VERSION 3.9.1 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_REQUIRED ON)

#Specify project and identify the language in use)
project(inverse-captcha LANGUAGES CXX VERSION 0.1.0)

file(GLOB SOURCES "src/*.cpp")

#Add program target main
add_library(${PROJECT_NAME} SHARED ${SOURCES})

target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

add_subdirectory(tests)

add_test(inverse-captcha tests/inverse-captcha-tests)
