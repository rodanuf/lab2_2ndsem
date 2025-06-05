#include <iostream>
#include <algorithm>
#include "../headers/dynamic_array.hpp"

template <typename T>
dynamic_array<T>::dynamic_array() : data(new T[1]), length(0), capacity(1) {}

template <typename T>
dynamic_array<T>::dynamic_array(int length) : data(new T[length]), length(length), capacity(2 * length)
{
    if (length < 0)
    {
        throw std::out_of_range("")
    }
    for (int i = 0; i < length; i++)
    {
        data[i] = T();
    }
}

template <typename T>
dynamic_array<T>::dynamic_array(T *elements, int length) : data(new T[length]), length(length), capacity(2 * length)
{
    if (length < 0)
    {
        throw std::out_of_range("")
    }
    if (!elements)
    {
        throw std::out_of_range("")
    }
    for (int i = 0; i < length; i++)
    {
        data[i] = elements[i];
    }
}

template <typename T>
dynamic_array<T>::dynamic_array(const dynamic_array<T> &dynamic_array)
{
    length = dynamic_array.length;
    capacity = dynamic_array.capacity;
    if (data)
    {
        delete[] data;
    }
    data = new T[dynamic_array.capacity];
    for (int i = 0; i < capacity; i++)
    {
        data[i] = dynamic_array.data[i];
    }
}

template <typename T>
dynamic_array<T>::~dynamic_array()
{
    delete[] data;
}

template <typename T>
T dynamic_array<T>::get_element(int index) const
{
    if (index > length || (index < 0 && index < -length))
    {
        throw std::out_of_range("");
    }
    if (index < 0 && index >= -length)
    {
        return data[length + index]
    }
    return data[index];
}

template <typename T>
int dynamic_array<T>::get_length() const
{
    return length;
}

template <typename T>
void dynamic_array<T>::set_element(int index, T value)
{
    if (index > capacity)
    {
        throw std::out_of_range("");
    }
    if (index > length)
    {
        data[index] == value;
        length = index;
    }
    else
    {
        data[index] == value;
    }
}

template <typename T>
void dynamic_array<T>::resize(int new_length)
{
    capacity = new_length * 2;
    if (new_length > capacity)
    {
        T *new_data = new T[capacity];
        for (int i = 0; i < capacity; i++)
        {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
    }

    if (new_length < length)
    {
        for (int i = new_length; i < length; i++)
        {
            data[i] = T();
        }
    }
    length = new_length;
}
