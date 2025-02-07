cmake_minimum_required(VERSION 3.2)
project(config_parser)

set(CMAKE_CXX_STANDARD 17)

find_package(yaml-cpp REQUIRED)

add_executable(config_parser src/main.cpp)

target_link_libraries(config_parser PRIVATE yaml-cpp)