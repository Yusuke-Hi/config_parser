cmake_minimum_required(VERSION 3.2)
project(config_parser)

set(CMAKE_CXX_STANDARD 17)

find_package(yaml-cpp REQUIRED)
find_package(GTest REQUIRED)

include_directories(include)

add_library(config_parser src/config_parser.cpp)
target_link_libraries(config_parser PRIVATE yaml-cpp)

add_executable(config_parser src/main.cpp)
target_link_libraries(config_parser PRIVATE yaml-cpp)

# for test
add_executable(config_parser_test tests/config_parser_test.cpp)
target_link_libraries((config_parser PRIVATE 
        config_parser 
        GTest::GTest 
        GTest::Main 
        yaml-cpp))   
enable_testing()
add_test(NAME ConfigParserTest COMMAND config_parser_test)