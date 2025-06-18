#include <iostream>
#include <algorithm>
#include <stdexcept>
#include "../headers/dynamic_array.hpp"

template <typename T>
dynamic_array<T>::dynamic_array() : data(new T[1]()), length(0), capacity(1) {}

template <typename T>
dynamic_array<T>::dynamic_array(int length) : data(new T[length]()), length(length), capacity(2 * length)
{
    if (length < 0)
    {
        throw std::out_of_range("Incorrect length");
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
        throw std::out_of_range("Incorrect length");
    }
    if (!elements)
    {
        throw std::out_of_range("Incorrect length");
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
    if (index < 0 && index >= -length)
    {
        return data[length + index];
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
        resize(index);
        data[index] = value;
    }
    if (index > length)
    {
        data[index] = value;
        length = index;
    }
    else
    {
        data[index] = value;
    }
}

template <typename T>
void dynamic_array<T>::resize(int new_length)
{
    if (new_length > capacity)
    {
        capacity = new_length * 2;
        T *new_data = new T[capacity]();
        for (int i = 0; i < length; i++)
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

template <typename T>
void dynamic_array<T>::append_element(const T &element)
{
    if (length == capacity)
    {
        resize(get_length() + 1);
        set_element(get_length() - 1, element);
    }
    else
    {
        set_element(get_length(), element);
        length++;
    }
}

template <typename T>
void dynamic_array<T>::prepend_element(const T &element)
{
    if (length == capacity)
    {
        resize(length + 1);
    }
    else
    {
        length++;
    }
    T buffer_element = data[0];
    if (length != 1)
    {
        for (int i = 0; i <= length - 1; i += 2)
        {
            data[i] = buffer_element;
            buffer_element = data[i + 1];
            data[i + 1] = data[i];
        }
    }
    set_element(0, element);
}
template <typename T>
void dynamic_array<T>::insert_element(const T &value, const int index)
{
    if (length == capacity)
    {
        resize(length + 1);
    }
    length++;
    T buffer_element = data[index];
    for (int i = index; i <= length - 1; i += 2)
    {
        data[i] = data[i + 1];
        data[i + 1] = buffer_element;
        buffer_element = data[i];
    }
    set_element(index, value);
}
template <typename T>
void dynamic_array<T>::print() const
{
    std::cout << "[";
    for (int i = 0; i < length; i++)
    {
        if (i == length - 1)
        {
            std::cout << data[i];
            break;
        }
        std::cout << data[i] << ", ";
    }
    std::cout << "]";
    std::cout << std::endl;
}

template <typename T>
void dynamic_array<T>::clear()
{
    for (int i = 0; i < length; i++)
    {
        data[i] = T();
    }
}