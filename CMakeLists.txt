cmake_minimum_required(VERSION 3.10)
project(lab2_2ndsem LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

file (GLOB SOURCES "sources/*.cpp")
file (GLOB HEADERS "headers/*.hpp")
file (GLOB TEMPLATES "templates/*.tpp")

include_directories(headers)
include_directories(templates)

add_executable(lab2_2ndsem
    sources/lab2.cpp
    sources/ui.cpp
    templates/array_sequence.tpp 
    templates/dynamic_array.tpp 
    templates/linked_list.tpp 
    templates/list_sequence.tpp 
)

