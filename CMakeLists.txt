#Specify minimum required version for CMake
cmake_minimum_required(VERSION 3.9.1 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_REQUIRED ON)

#Specify project and identify the language in use)
project(Advent-Of-Code-2017 LANGUAGES CXX VERSION 0.1.0)

file(GLOB SOURCES "src/*.cpp")

#Add program target main
add_executable(${PROJECT_NAME} ${SOURCES})

#
### Compiler related stuff ###
#

# Default flags
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(ERROR_FLAGS "-pedantic -Weverything")
    set(DIAG_IGNORE "-Wno-c++98-compat-pedantic -Wno-c++98-compat")
    set(CMAKE_CXX_FLAGS
        "${CMAKE_CXX_FLAGS} ${ERROR_FLAGS} ${DIAG_IGNORE}")
endif()

# Dealing with resources to be copied in binary dir
file(GLOB RESOURCES "resources/*")

foreach(RESOURCE ${RESOURCES})
    get_filename_component(RESOURCE_NAME ${RESOURCE} NAME)
    configure_file(${RESOURCE} resources/${RESOURCE_NAME} COPYONLY)
endforeach()

enable_testing()

add_subdirectory(inverse-captcha)
add_subdirectory(3rd-party/catch-lib)
add_subdirectory(tests)

target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/inverse-captcha/include
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
    inverse-captcha
)

add_test(aoc-tests tests/aoc-tests)
