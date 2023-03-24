cmake_minimum_required(VERSION 3.26.0)
project(main)
add_executable(main src/main.cpp)
add_compile_options(-Wall -Wextra)

add_library(SL SHARED src/lib.cpp)
target_link_libraries(main PRIVATE SL)
include_directories(include/)

set(LIBRARY_OUTPUT_PATH /Users/zh/Desktop/Git/sfu/lib/)
set(EXECUTABLE_OUTPUT_PATH /Users/zh/Desktop/Git/sfu/bin)