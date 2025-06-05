#include <iostream>
#include <stdexcept>
#include "../headers/list_sequence.hpp"

template <typename T>
list_sequence<T>::list_sequence() : list_s() {}

template <typename T>
list_sequence<T>::list_sequence(T *items, int count) : list_s(items, count) {}

template <typename T>
list_sequence<T>::list_sequence(const linked_list<T> &list) : list_s(list) {}

template <typename T>
list_sequence<T>::~list_sequence() {}

template <typename T>
T list_sequence<T>::get_first()
{
    return list_s.get_first();
}

template <typename T>
T list_sequence<T>::get_last()
{
    return list_s.get_last();
}

template <typename T>
T list_sequence<T>::get_element(int index)
{
    return list_s.get_element(index);
}

template <typename T>
sequence<T> *list_sequence<T>::append_element(T element)
{
    list_s.append_element(element);
    return this;
}

template <typename T>
sequence<T> *list_sequence<T>::prepend_element(T element)
{
    list_s.prepend_element(element);
    return this;
}

template <typename T>
sequence<T> *list_sequence<T>::insert_element(T element, int index)
{
    list_s.insert_element(element, index);
    return this;
}

template <typename T>
sequence<T> *list_sequence<T>::concat(sequence<T> *list)
{
    list_s.concat(list);
    return this;
}

template <typename T>
sequence<T> *list_sequence<T>::immutable_append_element(T element)
{
    list_sequence<T> list(this);
    list.append_element(element);
    return *list;
}

template <typename T>
sequence<T> *list_sequence<T>::immutable_prepend_element(T element)
{
    list_sequence<T> list(this);
    list.prepend_element(element);
    return *list;
}

template <typename T>
sequence<T> *list_sequence<T>::immutable_insert_element(T element, int index)
{
    list_sequence<T> list(this);
    list.insert_element(element, index);
    return *list;
}

template <typename T>
sequence<T> *list_sequence<T>::immutable_concat(sequence<T> *container)
{
    list_sequence<T> list(this);
    list.concat(container);
    return *list;
}

template <typename T>
void list_sequence<T>::print()
{
    for (int i = 0; i < list_s.length; i++)
    {
        std::cout << "| data=" << list_s.get_element(i) << " |  ";
    }
    std::cout << std::endl;
    for (int i = 0; i < list_s.length; i++)
    {
        if (i == list_s.length - 1)
        {
            std::cout << "| next   |";
            continue;
        }
        std::cout << "| next   |->";
    }
    std::cout << std::endl;
    for (int i = 0; i < list_s.length; i++)
    {
        if (i == list_s.length - 1)
        {
            std::cout << "| prev   |";
            continue;
        }
        std::cout << "| prev   |->";
    }
    std::cout << std::endl;
}