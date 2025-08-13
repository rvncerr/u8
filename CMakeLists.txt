cmake_minimum_required(VERSION 3.10)
project(u8 VERSION 0.1 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include_directories(include)

set(U8_SOURCES
    src/length.c
    src/rune.c
    src/find.c
    src/loop.c
    src/compare.c
    src/sanitize.c
)

add_library(u8 ${U8_SOURCES})

find_package(cunit)
if(cunit_FOUND)
    add_executable(u8_cunit tests/u8_cunit.c)
    target_link_libraries(u8_cunit PRIVATE cunit::cunit u8)
    message(STATUS "Building test executable with CUnit")
else()
    message(STATUS "CUnit not found - run 'conan install' to get dependencies")
endif()
