cmake_minimum_required(VERSION 3.10)
project(lab2_2ndsem LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file (GLOB SOURCES "sources/*.cpp")
file (GLOB HEADERS "headers/*.hpp")

include_directories(heades)

add_executable(lab2_2ndsem
    sources/lab2.cpp

)

