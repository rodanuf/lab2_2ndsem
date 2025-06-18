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
T array_sequence<T>::get_first() const
{
    return this->get_element(0);
}

template <typename T>
T array_sequence<T>::get_last() const
{
    return array_s.get_element(array_s.get_length() - 1);
}

template <typename T>
T array_sequence<T>::get_element(int index) const
{
    if (index > array_s.get_length() || (index < 0 && index < -array_s.get_length()))
    {
        throw std::out_of_range("Out of range");
    }
    return array_s.get_element(index);
}

template <typename T>
int array_sequence<T>::get_length() const
{
    return array_s.get_length();
}

template <typename T>
sequence<T> *array_sequence<T>::get_subsequence(int start_index, int end_index) const
{
    if (start_index > end_index)
    {
        start_index = start_index + end_index;
        end_index = start_index - end_index;
        start_index = start_index - end_index;
    }
    if (start_index < 0 || end_index < 0)
    {
        if (start_index > -array_s.get_length() && end_index > -array_s.get_length())
        {
            start_index = start_index + array_s.get_length();
            end_index = end_index + array_s.get_length();
        }
        else
        {
            throw std::out_of_range("Out of the range");
        }
    }
    if (end_index > array_s.get_length())
    {
        throw std::out_of_range("Out of the range");
    }
    array_sequence<T> *subsequence = new array_sequence<T>();
    for (int i = start_index; i < end_index; i++)
    {
        subsequence->append_element(array_s.get_element(i));
    }
    return subsequence;
}

template <typename T>
sequence<T> *array_sequence<T>::append_element(const T &element)
{
    array_s.append_element(element);
    return this;
}

template <typename T>
sequence<T> *array_sequence<T>::prepend_element(const T &element)
{
    array_s.prepend_element(element);
    return this;
}

template <typename T>
sequence<T> *array_sequence<T>::insert_element(const T &element, const int index)
{
    if (index > array_s.get_length())
    {
        throw std::out_of_range("Out of the range");
    }
    if (index < -array_s.get_length())
    {
        throw std::out_of_range("Out of the range");
    }
    array_s.insert_element(element, index);
    return this;
}

template <typename T>
sequence<T> *array_sequence<T>::concat(const sequence<T> &container)
{
    int buffer_length = array_s.get_length();
    array_s.resize(array_s.get_length() + container.get_length());
    for (int i = 0; i < container.get_length(); i++)
    {
        array_s.set_element(buffer_length + i, container.get_element(i));
    }
    return this;
}

template <typename T>
sequence<T> *array_sequence<T>::immutable_append_element(const T &element) const
{
    array_sequence<T> sequence(*this);
    sequence.append_element(element);
    return &sequence;
}

template <typename T>
sequence<T> *array_sequence<T>::immutable_prepend_element(const T &element) const
{
    array_sequence<T> sequence(*this);
    sequence.prepend_element(element);
    return &sequence;
}

template <typename T>
sequence<T> *array_sequence<T>::immutable_insert_element(const T &element, const int index) const
{
    array_sequence<T> sequence(*this);
    sequence.insert_element(element, index);
    return &sequence;
}

template <typename T>
sequence<T> *array_sequence<T>::immutable_concat(const sequence<T> &container) const
{
    array_sequence<T> sequence(*this);
    sequence.concat(container);
    return &sequence;
}

template <typename T>
void array_sequence<T>::print() const
{
    if (array_s.get_length() == 0)
    {
        throw std::out_of_range("Array doesn't exists");
    }
    array_s.print();
}

template <typename T>
void array_sequence<T>::clear()
{
    if (array_s.get_length() == 0)
    {
        throw std::out_of_range("Array doesn't exists");
    }
    array_s.clear();
}