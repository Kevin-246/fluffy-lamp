cmake_minimum_required(VERSION 3.26.1)
project(main)
add_executable(main src/main.cpp)
add_compile_options(-Wall -Wextra)

set(CMAKE_OSX_ARCHITECTURES "x86_64;arm64")
set(LIBRARY_OUTPUT_PATH /Users/zh/Desktop/Git/sfu/lib/)
set(CMAKE_BUILD_TYPE Release)

add_library(SL SHARED src/lib.cpp)
target_link_libraries(main PRIVATE SL)
include_directories(include/)