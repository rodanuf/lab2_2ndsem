#include <gtest/gtest.h>
#include "../headers/array_sequence.hpp"
#include "../headers/list_sequence.hpp"
#include "../headers/linked_list.hpp"
#include "../headers/dynamic_array.hpp"

#include "test_array_sequence.cpp"
#include "test_list_sequence.cpp"
#include "test_linked_list.cpp"
#include "test_dynamic_array.cpp"

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}