cmake_minimum_required(VERSION 3.5)
project(u8 VERSION 0.1 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_library(u8 u8.c u8_rune.c u8_find.c u8_loop.c u8_compare.c)
add_executable(u8_cunit u8_cunit.c)
target_link_libraries(u8_cunit PRIVATE cunit u8)
