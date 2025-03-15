cmake_minimum_required(VERSION 3.15)
project(Call)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED)

add_subdirectory(src)

include(CTest)
add_subdirectory(tests)
