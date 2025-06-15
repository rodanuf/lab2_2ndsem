#include <stdexcept>
#include <iostream>
#include "../headers/linked_list.hpp"

template <typename T>
linked_list<T>::linked_list() : head(nullptr), tail(nullptr), length(0) {}

template <typename T>
linked_list<T>::linked_list(const T *elements, int count) : length(count), head(nullptr), tail(nullptr)
{
    if (count < 0 || !elements)
    {
        throw std::out_of_range("Incorrect input");
    }
    for (int i = 0; i < count; i++)
    {
        prepend_element(elements[i]);
    }
}

template <typename T>
linked_list<T>::linked_list(const linked_list<T> &list) : head(nullptr), tail(nullptr), length(list.length)
{
    node **node_pp = &head;
    for (immutable_iterator list_i = list.begin(); list_i != list.end(); list_i++)
    {
        *node_pp = new node(*list_i);
        node_pp = &((*node_pp)->next);
    }
    tail = *node_pp;
}

template <typename T>
linked_list<T>::~linked_list()
{
    while (head->next != nullptr)
    {
        node *buffer_pointer = head->next;
        head = head->next;
        delete (buffer_pointer);
    }
}

template <typename T>
T linked_list<T>::get_first() const
{
    if (!head)
    {
        std::out_of_range("List is not exists");
    }
    return head->element;
}

template <typename T>
T linked_list<T>::get_last() const
{
    if (!tail)
    {
        std::out_of_range("List is not exists");
    }
    return tail->element;
}

template <typename T>
T linked_list<T>::get_element(int index) const
{
    if (!head)
    {
        std::out_of_range("List is not exists");
    }
    if (index > length)
    {
        std::out_of_range("Out of range");
    }
    node *buffer_node = head;
    for (int i = 0; i < index; i++)
    {
        buffer_node++;
    }
    return buffer_node->element;
}

template <typename T>
int linked_list<T>::get_length() const
{
    if (!head)
    {
        throw std::out_of_range("List does not exists");
    }
    return length;
}

template <typename T>
void linked_list<T>::append_element(const T &element)
{
    node new_node = node(element);
    if (!tail)
    {
        head = tail = &new_node;
    }
    else
    {
        new_node.prev = tail;
        tail = &new_node;
    }
    length++;
}

template <typename T>
void linked_list<T>::prepend_element(const T &element)
{
    node new_node = node(element);
    if (!head)
    {
        head = tail = &new_node;
    }
    else
    {
        new_node.next = head;
        head = &new_node;
    }
    length++;
}

template <typename T>
void linked_list<T>::insert_element(const T &element, int index)
{
    node **node_pp = &head;
    for (int i = 0; i < index; i++)
    {
        node_pp = &((*node_pp)->next);
    }
    node new_node = node(element);
    new_node.next = *node_pp;
    new_node.prev = (*node_pp)->prev;
}

template <typename T>
void linked_list<T>::print() const
{
    for (int i = 0; i < length; i++)
    {
        std::cout << "| data=" << get_element(i) << " |  ";
    }
    std::cout << std::endl;
    for (int i = 0; i < length; i++)
    {
        if (i == length - 1)
        {
            std::cout << "| next   |";
            continue;
        }
        std::cout << "| next   |->";
    }
    std::cout << std::endl;
    for (int i = 0; i < length; i++)
    {
        if (i == length - 1)
        {
            std::cout << "| prev   |";
            continue;
        }
        std::cout << "| prev   |->";
    }
    std::cout << std::endl;
}

template <typename T>
void linked_list<T>::clear()
{
    for (iterator list_i = begin(); list_i != end(); list_i++)
    {
        *list_i = T();
    }
}

template <typename T>
linked_list<T> linked_list<T>::get_subdata(int first_index, int last_index) const
{
    if (!head)
    {
        throw std::out_of_range("List is not exists");
    }
    if (first_index < last_index)
    {
        throw std::out_of_range("Incorrect indexing");
    }
    linked_list<T> subdata = linked_list();
    node *buffer_node = head;
    for (int i = 0; i <= last_index; i++)
    {
        if (i == first_index)
        {
            subdata.head = buffer_node;
        }
        buffer_node = buffer_node->next;
    }
    subdata.tail = buffer_node;
}

template <typename T>
linked_list<T>::iterator::iterator(node *node_p) : current(&node_p) {}

template <typename T>
typename linked_list<T>::iterator linked_list<T>::iterator::operator++(int)
{
    if (!current)
    {
        throw std::out_of_range("Invalid iterator");
    }
    iterator temp = *this;
    ++(*this);
    return temp;
}

template <typename T>
typename linked_list<T>::iterator &linked_list<T>::iterator::operator++()
{
    if (!current)
    {
        throw std::out_of_range("Invalid iterator");
    }
    *current = (*current)->next;
    return *this;
}

template <typename T>
T &linked_list<T>::iterator::operator*() const
{
    if (!current)
    {
        throw std::out_of_range("Invalid iterator");
    }
    return (*current)->element;
}

template <typename T>
bool linked_list<T>::iterator::operator==(const iterator &other) const
{
    return *current == (*other.current);
}

template <typename T>
bool linked_list<T>::iterator::operator!=(const iterator &other) const
{
    return !(*this == other);
}

template <typename T>
linked_list<T>::immutable_iterator::immutable_iterator(node *node_p) : current(&node_p) {}

template <typename T>
typename linked_list<T>::immutable_iterator linked_list<T>::immutable_iterator::operator++(int)
{
    if (!current)
    {
        throw std::out_of_range("Invalid iterator");
    }
    immutable_iterator temp = *this;
    ++(*this);
    return temp;
}

template <typename T>
typename linked_list<T>::immutable_iterator &linked_list<T>::immutable_iterator::operator++()
{
    if (!current)
    {
        throw std::out_of_range("Invalid iterator");
    }
    *current = (*current)->next;
    return *this;
}

template <typename T>
const T &linked_list<T>::immutable_iterator::operator*() const
{
    if (!current)
    {
        throw std::out_of_range("Invalid iterator");
    }
    return (*current)->element;
}

template <typename T>
bool linked_list<T>::immutable_iterator::operator==(const immutable_iterator &other) const
{
    return *current == (*other.current);
}

template <typename T>
bool linked_list<T>::immutable_iterator::operator!=(const immutable_iterator &other) const
{
    return !(*this == other);
}
