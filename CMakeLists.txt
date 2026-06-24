cmake_minimum_required(VERSION 4.3.0)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_compile_options(--Wall --Wextra --Wpedantic)

project(file-info C)


set(SOURCES main.c display.c file_info.c)

add_executable(file-info ${SOURCES})