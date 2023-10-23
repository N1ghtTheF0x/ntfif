cmake_minimum_required(VERSION 3.22)

project(N1gthTheF0x)

# CMake Options

option(NTFIF_EXAMPLE "Compile example program")

set(NTFIF_EXAMPLE ON)

# Main Library

add_library(ntfif 
    source/header.cpp
    source/pixel.cpp
    source/file.cpp
)

target_include_directories(ntfif PRIVATE include)

# Include example program if requested
if(NTFIF_EXAMPLE)
    add_executable(ntfif_example example/main.cpp)
    target_link_libraries(ntfif_example PUBLIC ntfif)
    target_include_directories(ntfif_example PRIVATE include)
endif()