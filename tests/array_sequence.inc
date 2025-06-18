#include <gtest/gtest.h>
#include "../headers/array_sequence.hpp"

TEST(array_sequence_test, default_constructor)
{
    array_sequence<int> seq;
    EXPECT_EQ(seq.get_length(), 0);
}

TEST(array_sequence_test, array_constructor)
{
    int arr[] = {1, 2, 3};
    array_sequence<int> seq(arr, 3);
    EXPECT_EQ(seq.get_length(), 3);
    EXPECT_EQ(seq.get_element(0), 1);
    EXPECT_EQ(seq.get_element(1), 2);
    EXPECT_EQ(seq.get_element(2), 3);
}

TEST(array_sequence_test, copy_constructor)
{
    int arr[] = {4, 5, 6};
    array_sequence<int> seq1(arr, 3);
    array_sequence<int> seq2(seq1);
    EXPECT_EQ(seq2.get_length(), 3);
    EXPECT_EQ(seq2.get_element(0), 4);
}

TEST(array_sequence_test, get_first_last)
{
    int arr[] = {10, 20, 30};
    array_sequence<int> seq(arr, 3);
    EXPECT_EQ(seq.get_first(), 10);
    EXPECT_EQ(seq.get_last(), 30);
}

TEST(array_sequence_test, get_element)
{
    int arr[] = {1, 2, 3, 4, 5};
    array_sequence<int> seq(arr, 5);
    EXPECT_EQ(seq.get_element(2), 3);
    EXPECT_EQ(seq.get_element(-1), 5);
}

TEST(array_sequence_test, get_subsequence)
{
    int arr[] = {1, 2, 3, 4, 5};
    array_sequence<int> seq(arr, 5);
    sequence<int> *sub = seq.get_subsequence(1, 3);
    EXPECT_EQ(sub->get_length(), 2);
    EXPECT_EQ(sub->get_element(0), 2);
    EXPECT_EQ(sub->get_element(1), 3);
    delete sub;
}

TEST(array_sequence_test, append_element)
{
    array_sequence<int> seq;
    seq.append_element(10);
    seq.append_element(20);
    EXPECT_EQ(seq.get_length(), 2);
    EXPECT_EQ(seq.get_last(), 20);
}

TEST(array_sequence_test, prepend_element)
{
    array_sequence<int> seq;
    seq.prepend_element(30);
    seq.prepend_element(40);
    EXPECT_EQ(seq.get_length(), 2);
    EXPECT_EQ(seq.get_first(), 40);
}

TEST(array_sequence_test, insert_element)
{
    int arr[] = {1, 3};
    array_sequence<int> seq(arr, 2);
    seq.insert_element(2, 1);
    EXPECT_EQ(seq.get_length(), 3);
    EXPECT_EQ(seq.get_element(1), 2);
}

TEST(array_sequence_test, concat)
{
    int arr1[] = {1, 2};
    int arr2[] = {3, 4};
    array_sequence<int> seq1(arr1, 2);
    array_sequence<int> seq2(arr2, 2);
    seq1.concat(seq2);
    EXPECT_EQ(seq1.get_length(), 4);
    EXPECT_EQ(seq1.get_element(3), 4);
}

TEST(array_sequence_test, immutable_operations)
{
    int arr[] = {1, 2};
    array_sequence<int> seq(arr, 2);
    sequence<int> *new_seq = seq.immutable_append_element(3);
    EXPECT_EQ(seq.get_length(), 2);
    EXPECT_EQ(new_seq->get_length(), 3);
    delete new_seq;
}

TEST(array_sequence_test, clear)
{
    int arr[] = {1, 2, 3};
    array_sequence<int> seq(arr, 3);
    seq.clear();
    EXPECT_EQ(seq.get_first(), 0);
}

TEST(array_sequence_test, negative_index)
{
    int arr[] = {1, 2, 3, 4, 5};
    array_sequence<int> seq(arr, 5);
    EXPECT_EQ(seq.get_element(-1), 5);
    EXPECT_EQ(seq.get_element(-2), 4);
}
