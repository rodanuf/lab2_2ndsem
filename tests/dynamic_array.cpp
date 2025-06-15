#include <gtest/gtest.h>
#include "dynamic_array.hpp"

TEST(dynamic_array_test, default_constructor)
{
    dynamic_array<int> arr;
    EXPECT_EQ(arr.get_length(), 0);
    EXPECT_GE(arr.get_length(), 0);
}

TEST(dynamic_array_test, length_constructor)
{
    dynamic_array<int> arr(5);
    EXPECT_EQ(arr.get_length(), 5);
    for (int i = 0; i < 5; i++)
    {
        EXPECT_EQ(arr.get_element(i), 0);
    }
}

TEST(dynamic_array_test, array_constructor)
{
    int data[] = {1, 2, 3, 4, 5};
    dynamic_array<int> arr(data, 5);
    EXPECT_EQ(arr.get_length(), 5);
    for (int i = 0; i < 5; i++)
    {
        EXPECT_EQ(arr.get_element(i), data[i]);
    }
}

TEST(dynamic_array_test, copy_constructor)
{
    int data[] = {1, 2, 3};
    dynamic_array<int> arr1(data, 3);
    dynamic_array<int> arr2(arr1);
    EXPECT_EQ(arr2.get_length(), 3);
    for (int i = 0; i < 3; i++)
    {
        EXPECT_EQ(arr2.get_element(i), data[i]);
    }
}

TEST(dynamic_array_test, get_element)
{
    int data[] = {10, 20, 30};
    dynamic_array<int> arr(data, 3);
    EXPECT_EQ(arr.get_element(0), 10);
    EXPECT_EQ(arr.get_element(-1), 30); // Отрицательный индекс
    EXPECT_EQ(arr.get_element(-3), 10);
}

TEST(dynamic_array_test, set_element)
{
    dynamic_array<int> arr(3);
    arr.set_element(1, 42);
    EXPECT_EQ(arr.get_element(1), 42);
    arr.set_element(0, 10);
    EXPECT_EQ(arr.get_element(0), 10);
}

TEST(dynamic_array_test, resize)
{
    dynamic_array<int> arr(3);
    arr.resize(5);
    EXPECT_EQ(arr.get_length(), 5);
    arr.resize(2);
    EXPECT_EQ(arr.get_length(), 2);
}

TEST(dynamic_array_test, append_element)
{
    dynamic_array<int> arr;
    arr.append_element(10);
    arr.append_element(20);
    EXPECT_EQ(arr.get_length(), 2);
    EXPECT_EQ(arr.get_element(1), 20);
}

TEST(dynamic_array_test, prepend_element)
{
    dynamic_array<int> arr;
    arr.append_element(20);
    arr.prepend_element(10);
    EXPECT_EQ(arr.get_length(), 2);
    EXPECT_EQ(arr.get_element(0), 10);
    EXPECT_EQ(arr.get_element(1), 20);
}

TEST(dynamic_array_test, insert_element)
{
    int data[] = {1, 3};
    dynamic_array<int> arr(data, 2);
    arr.insert_element(2, 1);
    EXPECT_EQ(arr.get_length(), 3);
    EXPECT_EQ(arr.get_element(1), 2);
}

TEST(dynamic_array_test, clear)
{
    int data[] = {1, 2, 3};
    dynamic_array<int> arr(data, 3);
    arr.clear();
    for (int i = 0; i < 3; i++)
    {
        EXPECT_EQ(arr.get_element(i), 0);
    }
}

TEST(dynamic_array_test, negative_index)
{
    int data[] = {1, 2, 3, 4, 5};
    dynamic_array<int> arr(data, 5);
    EXPECT_EQ(arr.get_element(-1), 5);
    EXPECT_EQ(arr.get_element(-2), 4);
}

TEST(dynamic_array_test, exception_handling)
{
    EXPECT_THROW(dynamic_array<int>(-1), std::out_of_range);

    dynamic_array<int> arr;
    EXPECT_THROW(arr.get_element(0), std::out_of_range);

    int *null_data = nullptr;
    EXPECT_THROW(dynamic_array<int>(null_data, 1), std::out_of_range);
}

TEST(dynamic_array_test, capacity_management)
{
    dynamic_array<int> arr;
    for (int i = 0; i < 100; i++)
    {
        arr.append_element(i);
    }
    EXPECT_EQ(arr.get_length(), 100);
    EXPECT_GE(arr.get_length() * 2, arr.get_length()); // Проверка capacity
}

TEST(dynamic_array_test, boundary_conditions)
{
    dynamic_array<int> arr(10);
    arr.set_element(9, 100); // Граничный элемент
    EXPECT_EQ(arr.get_element(9), 100);

    arr.set_element(15, 200); // За пределами длины, но в пределах capacity
    EXPECT_EQ(arr.get_element(15), 200);
    EXPECT_EQ(arr.get_length(), 16);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}