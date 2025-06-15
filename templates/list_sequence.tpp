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
T list_sequence<T>::get_first() const
{
    return list_s.get_first();
}

template <typename T>
T list_sequence<T>::get_last() const
{
    return list_s.get_last();
}

template <typename T>
T list_sequence<T>::get_element(int index) const
{
    return list_s.get_element(index);
}

template <typename T>
int list_sequence<T>::get_length() const
{
    return list_s.get_length();
}

template <typename T>
sequence<T> *list_sequence<T>::get_subsequence(int start_index, int end_index) const
{
    list_sequence<T> *list = new list_sequence<T>(list_s.get_subdata(start_index, end_index));
    return list;
}

template <typename T>
sequence<T> *list_sequence<T>::append_element(const T &element)
{
    list_s.append_element(element);
    return this;
}

template <typename T>
sequence<T> *list_sequence<T>::prepend_element(const T &element)
{
    list_s.prepend_element(element);
    return this;
}

template <typename T>
sequence<T> *list_sequence<T>::insert_element(const T &element, const int index)
{
    list_s.insert_element(element, index);
    return this;
}

template <typename T>
sequence<T> *list_sequence<T>::concat(const sequence<T> &container)
{
    for (int i = 0; i < container.get_length(); i++)
    {
        list_s.append_element(container.get_element(i));
    }
    return this;
}

template <typename T>
sequence<T> *list_sequence<T>::immutable_append_element(const T &element) const
{
    list_sequence<T> *new_list = new list_sequence<T>(*this);
    new_list->append_element(element);
    return new_list;
}

template <typename T>
sequence<T> *list_sequence<T>::immutable_prepend_element(const T &element) const
{
    list_sequence<T> list(*this);
    list.prepend_element(element);
    return &list;
}

template <typename T>
sequence<T> *list_sequence<T>::immutable_insert_element(const T &element, const int index) const
{
    list_sequence<T> list(*this);
    list.insert_element(element, index);
    return &list;
}

template <typename T>
sequence<T> *list_sequence<T>::immutable_concat(const sequence<T> &container) const
{
    list_sequence<T> list(*this);
    list.concat(container);
    return &list;
}

template <typename T>
void list_sequence<T>::print() const
{
    list_s.print();
}

template <typename T>
void list_sequence<T>::clear()
{
    list_s.clear();
}