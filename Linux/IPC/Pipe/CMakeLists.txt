cmake_minimum_required(VERSION 3.22)
project(Pipe)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(producer producer.cpp)
add_executable(consumer consumer.cpp)
