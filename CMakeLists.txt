cmake_minimum_required(VERSION 3.10)
project(lab2_2ndsem LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

file(GLOB SOURCES "sources/*.cpp")
file(GLOB HEADERS "headers/*.hpp")
file(GLOB TEMPLATES "templates/*.tpp")
file(GLOB TESTS_SOURCES "tests/*.cpp")

add_executable(lab2_2ndsem
    sources/lab2.cpp
    sources/ui.cpp
    ${HEADERS}
    ${TEMPLATES}
)

option(BUILD_GMOCK "Build gmock" OFF)
add_subdirectory(googletest EXCLUDE_FROM_ALL)

add_executable(tests
    tests/main_tests.cpp 
    tests/array_sequence.inc
    tests/dynamic_array.inc
    tests/linked_list.inc
    tests/list_sequence.inc
    ${HEADERS}
    ${TEMPLATES}
)

target_link_libraries(tests
    PRIVATE
    gtest_main
)

enable_testing()
add_test(NAME AllTests COMMAND tests)