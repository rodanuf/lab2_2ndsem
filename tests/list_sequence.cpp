#include <gtest/gtest.h>
#include "../headers/list_sequence.hpp"

TEST(list_sequence_test, default_constructor)
{
    list_sequence<int> seq;
    EXPECT_EQ(seq.get_length(), 0);
    EXPECT_THROW(seq.get_first(), std::out_of_range);
    EXPECT_THROW(seq.get_last(), std::out_of_range);
}

TEST(list_sequence_test, array_constructor)
{
    int data[] = {1, 2, 3, 4, 5};
    list_sequence<int> seq(data, 5);
    EXPECT_EQ(seq.get_length(), 5);
    for (int i = 0; i < 5; i++)
    {
        EXPECT_EQ(seq.get_element(i), data[i]);
    }
    EXPECT_THROW(list_sequence<int>(nullptr, 5), std::out_of_range);
    EXPECT_THROW(list_sequence<int>(data, -1), std::out_of_range);
}

TEST(list_sequence_test, copy_constructor)
{
    int data[] = {1, 2, 3};
    list_sequence<int> seq1(data, 3);
    list_sequence<int> seq2(seq1);
    EXPECT_EQ(seq2.get_length(), 3);
    for (int i = 0; i < 3; i++)
    {
        EXPECT_EQ(seq2.get_element(i), data[i]);
    }
}

TEST(list_sequence_test, get_element)
{
    int data[] = {10, 20, 30};
    list_sequence<int> seq(data, 3);
    EXPECT_EQ(seq.get_element(0), 10);
    EXPECT_EQ(seq.get_element(1), 20);
    EXPECT_EQ(seq.get_element(2), 30);
    EXPECT_THROW(seq.get_element(-1), std::out_of_range);
    EXPECT_THROW(seq.get_element(3), std::out_of_range);
}

TEST(list_sequence_test, get_first_last)
{
    list_sequence<int> seq;
    EXPECT_THROW(seq.get_first(), std::out_of_range);
    EXPECT_THROW(seq.get_last(), std::out_of_range);

    int data[] = {10, 20, 30};
    seq = list_sequence<int>(data, 3);
    EXPECT_EQ(seq.get_first(), 10);
    EXPECT_EQ(seq.get_last(), 30);
}

TEST(list_sequence_test, append_prepend_insert)
{
    list_sequence<int> seq;
    seq.append_element(10);
    seq.prepend_element(5);
    seq.insert_element(7, 1);

    EXPECT_EQ(seq.get_length(), 3);
    EXPECT_EQ(seq.get_element(0), 5);
    EXPECT_EQ(seq.get_element(1), 7);
    EXPECT_EQ(seq.get_element(2), 10);
    EXPECT_THROW(seq.insert_element(0, 5), std::out_of_range);
    EXPECT_THROW(seq.insert_element(0, -1), std::out_of_range);
}

TEST(list_sequence_test, get_subsequence)
{
    int data[] = {1, 2, 3, 4, 5};
    list_sequence<int> seq(data, 5);

    sequence<int> *subseq = seq.get_subsequence(1, 3);
    EXPECT_EQ(subseq->get_length(), 3);
    EXPECT_EQ(subseq->get_element(0), 2);
    EXPECT_EQ(subseq->get_element(2), 4);
    EXPECT_THROW(seq.get_subsequence(-1, 3), std::out_of_range);
    EXPECT_THROW(seq.get_subsequence(1, 5), std::out_of_range);
    EXPECT_THROW(seq.get_subsequence(3, 1), std::out_of_range);
}

TEST(list_sequence_test, concat)
{
    int data1[] = {1, 2, 3};
    int data2[] = {4, 5, 6};
    list_sequence<int> seq1(data1, 3);
    list_sequence<int> seq2(data2, 3);

    seq1.concat(seq2);
    EXPECT_EQ(seq1.get_length(), 6);
    EXPECT_EQ(seq1.get_element(5), 6);
}

TEST(list_sequence_test, immutable_operations)
{
    int data[] = {1, 2, 3};
    list_sequence<int> seq(data, 3);

    sequence<int> *new_seq = seq.immutable_append_element(4);
    EXPECT_EQ(new_seq->get_length(), 4);
    EXPECT_EQ(new_seq->get_element(3), 4);
    EXPECT_EQ(seq.get_length(), 3);

    new_seq = seq.immutable_prepend_element(0);
    EXPECT_EQ(new_seq->get_length(), 4);
    EXPECT_EQ(new_seq->get_element(0), 0);

    new_seq = seq.immutable_insert_element(10, 1);
    EXPECT_EQ(new_seq->get_length(), 4);
    EXPECT_EQ(new_seq->get_element(1), 10);
}

TEST(list_sequence_test, clear)
{
    int data[] = {1, 2, 3};
    list_sequence<int> seq(data, 3);
    seq.clear();
    EXPECT_EQ(seq.get_length(), 0);
    EXPECT_THROW(seq.clear(), std::out_of_range);
}

TEST(list_sequence_test, iterator)
{
    int data[] = {1, 2, 3};
    list_sequence<int> seq(data, 3);
    auto it = seq.begin();
    EXPECT_EQ(*it, 1);
    ++it;
    EXPECT_EQ(*it, 2);
    it++;
    EXPECT_EQ(*it, 3);
    ++it;
    EXPECT_THROW(*it, std::out_of_range);
    int sum = 0;
    for (int val : seq)
    {
        sum += val;
    }
    EXPECT_EQ(sum, 6);
}

TEST(list_sequence_test, immutable_iterator)
{
    int data[] = {1, 2, 3};
    const list_sequence<int> seq(data, 3);
    auto it = seq.begin();
    EXPECT_EQ(*it, 1);
    ++it;
    EXPECT_EQ(*it, 2);
    int sum = 0;
    for (int val : seq)
    {
        sum += val;
    }
    EXPECT_EQ(sum, 6);
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

    seq.prepend_element(-1);
    seq.append_element(1000);
    EXPECT_EQ(seq.get_first(), -1);
    EXPECT_EQ(seq.get_last(), 1000);
}