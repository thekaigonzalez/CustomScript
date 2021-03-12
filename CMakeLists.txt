cmake_minimum_required(VERSION 3.17)
project(CustomScript)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../bin")

add_executable(cs8
        source.cpp)

add_executable(api
        api.cpp)