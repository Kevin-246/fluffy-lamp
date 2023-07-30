cmake_minimum_required(VERSION 3.26)
project(main)
add_executable(main src/main.cpp)
add_compile_options(-Wall -Wextra -Wpedantic -Wshadow -Wcast-qual -Wno-newline-eof)

set(CMAKE_OSX_ARCHITECTURES "x86_64;arm64")
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_BUILD_TYPE Release)

add_library(SL SHARED src/lib.cpp)
add_library(SL_STATIC STATIC src/lib.cpp)
set_target_properties(SL_STATIC PROPERTIES ARCHIVE_OUTPUT_NAME "SL")
target_link_libraries(main PRIVATE SL)
include_directories(include/)