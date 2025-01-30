cmake_minimum_required(VERSION 3.10)

project(Lab1)

add_subdirectory(lab1)

add_executable(main_program main_program/main.cc)

target_link_libraries(main_program lab1)
