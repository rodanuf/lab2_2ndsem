#include <gtest/gtest.h>
#include "../headers/list_sequence.hpp"
#include <string>
#include <limits>

TEST(list_sequence_test, default_constructor)
{
    list_sequence<int> seq;
    EXPECT_EQ(seq.get_length(), 0);
    EXPECT_THROW(seq.get_first(), std::out_of_range);
}

TEST(list_sequence_test, array_constructor)
{
    int arr[] = {1, 2, 3};
    list_sequence<int> seq(arr, 3);
    EXPECT_EQ(seq.get_length(), 3);
    EXPECT_EQ(seq.get_first(), 1);
    EXPECT_EQ(seq.get_last(), 3);
}

TEST(list_sequence_test, list_constructor)
{
    linked_list<std::string> list;
    list.append_element("a");
    list.append_element("b");
    list_sequence<std::string> seq(list);
    EXPECT_EQ(seq.get_length(), 2);
    EXPECT_EQ(seq.get_element(1), "b");
}

TEST(list_sequence_test, element_access)
{
    double arr[] = {1.1, 2.2, 3.3};
    list_sequence<double> seq(arr, 3);
    EXPECT_DOUBLE_EQ(seq.get_element(1), 2.2);
    EXPECT_DOUBLE_EQ(seq.get_element(-1), 3.3);
}

TEST(list_sequence_test, invalid_access)
{
    list_sequence<int> seq;
    EXPECT_THROW(seq.get_element(0), std::out_of_range);
    EXPECT_THROW(seq.get_first(), std::out_of_range);
    EXPECT_THROW(seq.get_last(), std::out_of_range);
}

TEST(list_sequence_test, append_prepend)
{
    list_sequence<int> seq;
    seq.append_element(10);
    seq.prepend_element(5);
    EXPECT_EQ(seq.get_length(), 2);
    EXPECT_EQ(seq.get_first(), 5);
    EXPECT_EQ(seq.get_last(), 10);
}

TEST(list_sequence_test, insert_element)
{
    int arr[] = {1, 3};
    list_sequence<int> seq(arr, 2);
    seq.insert_element(2, 1);
    EXPECT_EQ(seq.get_length(), 3);
    EXPECT_EQ(seq.get_element(1), 2);
}

TEST(list_sequence_test, get_subsequence)
{
    std::string arr[] = {"a", "b", "c", "d"};
    list_sequence<std::string> seq(arr, 4);
    sequence<std::string> *sub = seq.get_subsequence(1, 3);
    EXPECT_EQ(sub->get_length(), 2);
    EXPECT_EQ(sub->get_element(0), "b");
    delete sub;
}

TEST(list_sequence_test, concat_sequences)
{
    int arr1[] = {1, 2};
    int arr2[] = {3, 4};
    list_sequence<int> seq1(arr1, 2);
    list_sequence<int> seq2(arr2, 2);
    seq1.concat(seq2);
    EXPECT_EQ(seq1.get_length(), 4);
    EXPECT_EQ(seq1.get_element(3), 4);
}

TEST(list_sequence_test, immutable_operations)
{
    int arr[] = {1, 2};
    list_sequence<int> seq(arr, 2);

    sequence<int> *new_seq = seq.immutable_append_element(3);
    EXPECT_EQ(seq.get_length(), 2);
    EXPECT_EQ(new_seq->get_length(), 3);
    delete new_seq;
}

TEST(list_sequence_test, different_types)
{
    list_sequence<double> dseq;
    dseq.append_element(3.14);
    EXPECT_DOUBLE_EQ(dseq.get_last(), 3.14);

    list_sequence<std::string> sseq;
    sseq.append_element("test");
    EXPECT_EQ(sseq.get_last(), "test");

    struct LargeObject
    {
        int data[100];
    };
    list_sequence<LargeObject> lseq;
    LargeObject obj{};
    lseq.append_element(obj);
    EXPECT_EQ(lseq.get_length(), 1);
}

TEST(list_sequence_test, clear_sequence)
{
    int arr[] = {1, 2, 3};
    list_sequence<int> seq(arr, 3);
    seq.clear();
    EXPECT_EQ(seq.get_length(), 0);
    EXPECT_THROW(seq.get_first(), std::out_of_range);
}

TEST(list_sequence_test, exception_handling)
{
    EXPECT_THROW(list_sequence<int>(nullptr, 1), std::out_of_range);
    EXPECT_THROW(list_sequence<int>(nullptr, -1), std::out_of_range);

    int arr[] = {1};
    list_sequence<int> seq(arr, 1);
    EXPECT_THROW(seq.get_subsequence(0, 2), std::out_of_range);
}

TEST(list_sequence_test, boundary_conditions)
{
    list_sequence<int> seq;
    for (int i = 0; i < 1000; i++)
    {
        seq.append_element(i);
    }
    EXPECT_EQ(seq.get_length(), 1000);
    EXPECT_EQ(seq.get_element(999), 999);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}