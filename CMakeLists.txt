  cmake_minimum_required(VERSION 3.5)

project(Forradica LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2, -std:c++17")

set (CMAKE_SHARED_LINKER_FLAGS "-Wl,  -D_WIN32 -DWIN32")

file(GLOB_RECURSE all_files
     "*.h"
     "*.cpp"
)

link_directories(C:/SDL2/lib/x86 env(LIB))

add_executable(Forradica Main.cpp ${all_files})

target_link_libraries(Forradica SDL2 SDL2_image SDL2_ttf)

target_include_directories(Forradica PUBLIC . C:/SDL2/include)
target_link_options(Forradica PRIVATE /machine:x86 /verbose /DefaultLib:msvcprtd /FORCE /MT:Forradia.exe)
