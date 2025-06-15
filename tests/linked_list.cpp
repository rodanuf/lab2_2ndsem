#include <gtest/gtest.h>
#include "../headers/linked_list.hpp"
#include <string>
#include <limits>

TEST(linked_list_test, default_constructor)
{
    linked_list<int> list;
    EXPECT_EQ(list.get_length(), 0);
    EXPECT_THROW(list.get_first(), std::out_of_range);
}

TEST(linked_list_test, array_constructor)
{
    int arr[] = {1, 2, 3};
    linked_list<int> list(arr, 3);
    EXPECT_EQ(list.get_length(), 3);
    EXPECT_EQ(list.get_first(), 1);
    EXPECT_EQ(list.get_last(), 3);
}

TEST(linked_list_test, copy_constructor)
{
    int arr[] = {4, 5, 6};
    linked_list<int> list1(arr, 3);
    linked_list<int> list2(list1);
    EXPECT_EQ(list2.get_length(), 3);
    EXPECT_EQ(list2.get_element(1), 5);
}

TEST(linked_list_test, get_element)
{
    std::string arr[] = {"a", "b", "c"};
    linked_list<std::string> list(arr, 3);
    EXPECT_EQ(list.get_element(1), "b");
    EXPECT_EQ(list.get_element(-1), "c");
}

TEST(linked_list_test, invalid_access)
{
    linked_list<double> list;
    EXPECT_THROW(list.get_element(0), std::out_of_range);
    EXPECT_THROW(list.get_first(), std::out_of_range);
    EXPECT_THROW(list.get_last(), std::out_of_range);
}

TEST(linked_list_test, append_element)
{
    linked_list<int> list;
    list.append_element(10);
    list.append_element(20);
    EXPECT_EQ(list.get_length(), 2);
    EXPECT_EQ(list.get_last(), 20);
}

TEST(linked_list_test, prepend_element)
{
    linked_list<int> list;
    list.prepend_element(30);
    list.prepend_element(40);
    EXPECT_EQ(list.get_length(), 2);
    EXPECT_EQ(list.get_first(), 40);
}

TEST(linked_list_test, insert_element)
{
    int arr[] = {1, 3};
    linked_list<int> list(arr, 2);
    list.insert_element(2, 1);
    EXPECT_EQ(list.get_length(), 3);
    EXPECT_EQ(list.get_element(1), 2);
}

TEST(linked_list_test, get_subdata)
{
    int arr[] = {1, 2, 3, 4, 5};
    linked_list<int> list(arr, 5);
    linked_list<int> sub = list.get_subdata(1, 3);
    EXPECT_EQ(sub.get_length(), 3);
    EXPECT_EQ(sub.get_first(), 2);
    EXPECT_EQ(sub.get_last(), 4);
}

TEST(linked_list_test, iterator_operations)
{
    double arr[] = {1.5, 2.5, 3.5};
    linked_list<double> list(arr, 3);

    linked_list<double>::iterator it = list.begin();
    *it = 10.5;
    EXPECT_DOUBLE_EQ(list.get_first(), 10.5);

    const linked_list<double> &const_list = list;
    linked_list<double>::immutable_iterator cit = const_list.begin();
    EXPECT_DOUBLE_EQ(*cit, 10.5);
}

TEST(linked_list_test, empty_list_operations)
{
    linked_list<std::string> list;
    EXPECT_THROW(list.clear(), std::out_of_range);
    EXPECT_THROW(list.get_subdata(0, 1), std::out_of_range);
}

TEST(linked_list_test, boundary_conditions)
{
    linked_list<int> list;
    for (int i = 0; i < 1000; i++)
    {
        list.append_element(i);
    }
    EXPECT_EQ(list.get_length(), 1000);
    EXPECT_EQ(list.get_element(999), 999);
}

TEST(linked_list_test, different_types)
{
    linked_list<double> dlist;
    dlist.append_element(3.14);
    EXPECT_DOUBLE_EQ(dlist.get_last(), 3.14);

    linked_list<std::string> slist;
    slist.append_element("test");
    EXPECT_EQ(slist.get_last(), "test");

    struct LargeObject
    {
        int data[100];
    };
    linked_list<LargeObject> llist;
    LargeObject obj{};
    llist.append_element(obj);
    EXPECT_EQ(llist.get_length(), 1);
}

TEST(linked_list_test, clear_list)
{
    int arr[] = {1, 2, 3};
    linked_list<int> list(arr, 3);
    list.clear();
    EXPECT_EQ(list.get_length(), 3);
    EXPECT_EQ(list.get_element(0), 0);
}

TEST(linked_list_test, exception_handling)
{
    EXPECT_THROW(linked_list<int>(nullptr, 1), std::out_of_range);
    EXPECT_THROW(linked_list<int>(nullptr, -1), std::out_of_range);

    int arr[] = {1};
    linked_list<int> list(arr, 1);
    EXPECT_THROW(list.get_element(5), std::out_of_range);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}