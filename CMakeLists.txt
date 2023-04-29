cmake_minimum_required(VERSION 3.25)
project(HangMan_C C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(HangMan_C
        main.c
        main.h)
