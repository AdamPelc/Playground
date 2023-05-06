cmake_minimum_required(VERSION 3.22)
project(Pipe)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(producer producer.cpp)
add_executable(consumer consumer.cpp)
add_executable(pipe pipe.cpp)
