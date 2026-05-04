cmake_minimum_required(VERSION 3.10)
project(MicroNode)

add_executable(MicroNode src/main.c)
target_include_directories(MicroNode PRIVATE include)
target_compile_options(MicroNode PRIVATE -Wall -Werror -Wextra)
