#include <gtest/gtest.h>
#include "../headers/linked_list.hpp"

TEST(linked_list_test, default_constructor) {
    linked_list<int> list;
    EXPECT_EQ(list.get_length(), 0);
    EXPECT_THROW(list.get_first(), std::out_of_range);
    EXPECT_THROW(list.get_last(), std::out_of_range);
}

TEST(linked_list_test, array_constructor) {
    int data[] = {1, 2, 3, 4, 5};
    linked_list<int> list(data, 5);
    EXPECT_EQ(list.get_length(), 5);
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(list.get_element(i), data[i]);
    }
    EXPECT_THROW(linked_list<int>(nullptr, 5), std::out_of_range);
    EXPECT_THROW(linked_list<int>(data, -1), std::out_of_range);
}

TEST(linked_list_test, copy_constructor) {
    int data[] = {1, 2, 3};
    linked_list<int> list1(data, 3);
    linked_list<int> list2(list1);
    EXPECT_EQ(list2.get_length(), 3);
    for (int i = 0; i < 3; i++) {
        EXPECT_EQ(list2.get_element(i), data[i]);
    }
}

TEST(linked_list_test, get_element) {
    int data[] = {10, 20, 30};
    linked_list<int> list(data, 3);
    EXPECT_EQ(list.get_element(0), 10);
    EXPECT_EQ(list.get_element(1), 20);
    EXPECT_EQ(list.get_element(2), 30);

    EXPECT_THROW(list.get_element(-1), std::out_of_range);
    EXPECT_THROW(list.get_element(3), std::out_of_range);
}

TEST(linked_list_test, get_first_last) {
    linked_list<int> list;
    EXPECT_THROW(list.get_first(), std::out_of_range);
    EXPECT_THROW(list.get_last(), std::out_of_range);

    int data[] = {10, 20, 30};
    list = linked_list<int>(data, 3);
    EXPECT_EQ(list.get_first(), 10);
    EXPECT_EQ(list.get_last(), 30);
}

TEST(linked_list_test, append_prepend_insert) {
    linked_list<int> list;
    list.append_element(10);
    list.prepend_element(5);
    list.insert_element(7, 1);

    EXPECT_EQ(list.get_length(), 3);
    EXPECT_EQ(list.get_element(0), 5);
    EXPECT_EQ(list.get_element(1), 7);
    EXPECT_EQ(list.get_element(2), 10);

    EXPECT_THROW(list.insert_element(0, 5), std::out_of_range);
    EXPECT_THROW(list.insert_element(0, -1), std::out_of_range);
}

TEST(linked_list_test, get_subdata) {
    int data[] = {1, 2, 3, 4, 5};
    linked_list<int> list(data, 5);

    linked_list<int> sublist = list.get_subdata(1, 3);
    EXPECT_EQ(sublist.get_length(), 3);
    EXPECT_EQ(sublist.get_element(0), 2);
    EXPECT_EQ(sublist.get_element(2), 4);

    EXPECT_THROW(list.get_subdata(-1, 3), std::out_of_range);
    EXPECT_THROW(list.get_subdata(1, 5), std::out_of_range);
    EXPECT_THROW(list.get_subdata(3, 1), std::out_of_range);
}

TEST(linked_list_test, clear) {
    int data[] = {1, 2, 3};
    linked_list<int> list(data, 3);
    list.clear();
    EXPECT_EQ(list.get_length(), 3);

    for (int i = 0; i < 3; i++) {
        EXPECT_EQ(list.get_element(i), 0);
    }
}

TEST(linked_list_test, iterator) {
    int data[] = {1, 2, 3};
    linked_list<int> list(data, 3);

    auto it = list.begin();
    EXPECT_EQ(*it, 1);
    ++it;
    EXPECT_EQ(*it, 2);
    it++;
    EXPECT_EQ(*it, 3);
    ++it;
    EXPECT_THROW(*it, std::out_of_range);

    int sum = 0;
    for (int val : list) {
        sum += val;
    }
    EXPECT_EQ(sum, 6);
}

TEST(linked_list_test, immutable_iterator) {
    int data[] = {1, 2, 3};
    const linked_list<int> list(data, 3);

    auto it = list.begin();
    EXPECT_EQ(*it, 1);
    ++it;
    EXPECT_EQ(*it, 2);

    int sum = 0;
    for (int val : list) {
        sum += val;
    }
    EXPECT_EQ(sum, 6);
}

TEST(linked_list_test, boundary_conditions) {
    linked_list<int> list;
    for (int i = 0; i < 1000; i++) {
        list.append_element(i);
    }
    EXPECT_EQ(list.get_length(), 1000);
    EXPECT_EQ(list.get_element(999), 999);

    list.prepend_element(-1);
    list.append_element(1000);
    EXPECT_EQ(list.get_first(), -1);
    EXPECT_EQ(list.get_last(), 1000);
}