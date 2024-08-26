cmake_minimum_required(VERSION 3.5)
project(u8)
#set(CMAKE_C_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
add_compile_options(-std=c11)

add_library(u8 OBJECT u8.c)
add_library(u8_rune OBJECT u8_rune.c)
add_library(u8_find OBJECT u8_find.c)
add_library(u8_loop OBJECT u8_loop.c)
add_library(u8_compare OBJECT u8_compare.c)

add_library(u8_shared SHARED
	$<TARGET_OBJECTS:u8>
	$<TARGET_OBJECTS:u8_rune>
	$<TARGET_OBJECTS:u8_find>
	$<TARGET_OBJECTS:u8_loop>
	$<TARGET_OBJECTS:u8_compare>)
add_library(u8_static STATIC
	$<TARGET_OBJECTS:u8>
	$<TARGET_OBJECTS:u8_rune>
	$<TARGET_OBJECTS:u8_find>
	$<TARGET_OBJECTS:u8_loop>
	$<TARGET_OBJECTS:u8_compare>)
set_target_properties(u8_shared PROPERTIES OUTPUT_NAME u8)
set_target_properties(u8_static PROPERTIES OUTPUT_NAME u8)

add_executable(u8_cunit u8_cunit.c
	$<TARGET_OBJECTS:u8>
	$<TARGET_OBJECTS:u8_rune>
	$<TARGET_OBJECTS:u8_find>
	$<TARGET_OBJECTS:u8_loop>
	$<TARGET_OBJECTS:u8_compare>)
target_link_libraries(u8_cunit cunit)
