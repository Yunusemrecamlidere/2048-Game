cmake_minimum_required(VERSION 3.16)
project(oyun2048 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 3 COMPONENTS Graphics REQUIRED)

add_executable(oyun2048 main.cpp)

target_link_libraries(oyun2048 PRIVATE SFML::Graphics)