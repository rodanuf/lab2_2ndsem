#include <iostream>
#include <stdexcept>
#include "../headers/array_sequence.hpp"

template <typename T>
array_sequence<T>::array_sequence() : array_s() {}

template <typename T>
array_sequence<T>::array_sequence(T *elements, int count)
{
    if (elements == nullptr && count > 0)
    {
        throw std::out_of_range("Icorrect input");
    }
    if (count < 0)
    {
        throw std::out_of_range("Incorrect input");
    }
    else
    {
        array_s(elements, count);
    }
}

template <typename T>
array_sequence<T>::array_sequence(const dynamic_array<T> &array) : array_s(array) {}

template <typename T>
array_sequence<T>::~array_sequence() {}

template <typename T>
T array_sequence<T>::get_first()
{
    return dynamic_array.get_element(0);
}

template <typename T>
T array_sequence<T>::get_last()
{
    return array_s.get_element(array.length - 1);
}

template <typename T>
T array_sequence<T>::get_element(int index)
{
    if (index > array_s.length)
    {
        throw std::out_of_range("Out of the range");
    }
    return array_s.get_element(index);
}

template <typename T>
int array_sequence<T>::get_length()
{
    return array_s.length;
}

template <typename T>
sequence<T> *array_sequence<T>::append_element(T element)
{
    if (array_s.length == array_s.capacity)
    {
        array_s.resize(array_s.length + 1);
    }
    array_s.set_element(array_s.length, element);
    array_s.length++;
    return this;
}

template <typename T>
sequence<T> *array_sequence<T>::prepend_element(T element)
{
    if (array_s.length == array_s.capacity)
    {
        array_s.resize(array_s.length + 1);
    }
    array_s.length++;
    T buffer_element = array_s[0];
    for (int i = 0; i < array_s.length - 1; i++)
    {
        array_s[i] = buffer_element;
        buffer_element = array_s[i + 1];
        array_s[i + 1] = array_s[i];
    }
    array_s.set_element(0, element);
    return this;
}

template <typename T>
sequence<T> *array_sequence<T>::insert_element(T element, int index)
{
    if (index > array_s.length)
    {
        throw std::out_of_range("Out of the range");
    }
    if (index < -array_s.length)
    {
        throw std::out_of_range("Out of the range");
    }
    array_s.set_element(index, element);
    return this;
}

template <typename T>
sequence<T> *array_sequence<T>::concat(sequence<T> *container) // что если передадим nullptr
{
    int buffer_length = array_s.length;
    array_s.length += container->length;
    array_s.resize(array_s.length);
    for (int i = 0; i < container->length; i++)
    {
        array_s.set_element(buffer_length + i, container->data[i]);
    }
    return this;
}

template <typename T>
sequence<T> *array_sequence<T>::immutable_append_element(T element)
{
    array_sequence<T> sequence(this);
    sequence.append_element(element);
    return *sequence;
}

template <typename T>
sequence<T> *array_sequence<T>::immutable_prepend_element(T element)
{
    array_sequence<T> sequence(this);
    sequence.prepend_element(element);
    return *sequence;
}

template <typename T>
sequence<T> *array_sequence<T>::immutable_insert_element(T element, int index)
{
    array_sequence<T> sequence(this);
    sequence.insert_element(element, index);
    return *sequence;
}

template <typename T>
sequence<T> *array_sequence<T>::immutable_concat(sequence<T> *container)
{
    array_sequence<T> sequence(this);
    sequence.concat(container);
    return *sequence;
}

template <typename T>
void array_sequence<T>::print()
{
    std::cout << "[";
    for (int i = 0; i < array_s.length; i++)
    {
        if (i == array_s.length - 1)
        {
            std::cout << array_s.data[i];
            continue;
        }
        std::cout << array_s.data[i] << ", ";
    }
    std::cout << "]";
    std::cout << std::endl;
}

template <typename T>
void array_sequence<T>::clear()
{
    for (int i = 0; i < array_s.length; i++)
    {
        array_s.data[i] = T();
    }
}