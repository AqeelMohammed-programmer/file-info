cmake_minimum_required(VERSION 4.3.0)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra -Wpedantic)

project(file-info C)

set(SOURCES src/main.c src/display.c src/file_info.c)

add_executable(file-info ${SOURCES})

target_include_directories(file-info PRIVATE include)