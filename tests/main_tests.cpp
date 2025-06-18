#include <gtest/gtest.h>
#include "../headers/array_sequence.hpp"
#include "../headers/list_sequence.hpp"
#include "../headers/linked_list.hpp"
#include "../headers/dynamic_array.hpp"

#include "array_sequence.inc"
#include "list_sequence.inc"
#include "linked_list.inc"
#include "dynamic_array.inc"

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}