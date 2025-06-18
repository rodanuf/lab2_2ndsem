#include <stdexcept>
#include <iostream>
#include "../headers/linked_list.hpp"

template <typename T>
linked_list<T>::linked_list() : head(nullptr), tail(nullptr), length(0) {}

template <typename T>
linked_list<T>::linked_list(const T *elements, int count) : length(0), head(nullptr), tail(nullptr)
{
    if (count < 0 || !elements)
    {
        throw std::out_of_range("Incorrect input");
    }
    for (int i = 0; i < count; i++)
    {
        append_element(elements[i]);
    }
}

template <typename T>
linked_list<T>::linked_list(const linked_list<T> &list) : head(nullptr), tail(nullptr), length(list.length)
{
    if (list.head == nullptr)
    {
        return;
    }

    head = new node(list.head->element);
    node *current = head;
    node *src_current = list.head->next;

    while (src_current != nullptr)
    {
        current->next = new node(src_current->element);
        current->next->prev = current;
        current = current->next;
        src_current = src_current->next;
    }

    tail = current;
}

template <typename T>
linked_list<T>::~linked_list()
{
    while (head)
    {
        node *buffer_pointer = head;
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
        std::out_of_range("List does not exists");
    }
    if (index > length)
    {
        std::out_of_range("Out of range");
    }
    node *buffer_node = head;
    for (int i = 0; i < index; i++)
    {
        buffer_node = buffer_node->next;
    }
    return buffer_node->element;
}

template <typename T>
int linked_list<T>::get_length() const
{
    return length;
}

template <typename T>
void linked_list<T>::append_element(const T &element)
{
    node *new_node = new node(element);
    if (!tail)
    {
        head = tail = new_node;
    }
    else
    {
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
    }
    length++;
}

template <typename T>
void linked_list<T>::prepend_element(const T &element)
{
    node *new_node = new node(element);
    if (!head)
    {
        head = tail = new_node;
    }
    else
    {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
    length++;
}

template <typename T>
void linked_list<T>::insert_element(const T &element, int index)
{
    if (index < 0 || index > length)
    {
        throw std::out_of_range("Index out of range");
    }
    if (index == 0)
    {
        prepend_element(element);
        return;
    }
    if (index == length)
    {
        append_element(element);
        return;
    }
    node **node_pp = &head;
    for (int i = 0; i < index; i++)
    {
        node_pp = &((*node_pp)->next);
    }
    node *new_node = new node(element);
    new_node->next = *node_pp;
    new_node->prev = (*node_pp)->prev;
    if ((*node_pp)->prev)
    {
        (*node_pp)->prev->next = new_node;
    }
    (*node_pp)->prev = new_node;
    length++;
}

template <typename T>
void linked_list<T>::print() const
{
    node *current = head;
    while (current)
    {
        std::cout << "| data=" << current->element;
        if (current->next)
        {
            std::cout << " |->";
        }
        else
        {
            std::cout << " |";
        }
        current = current->next;
    }
    std::cout << std::endl;
}

template <typename T>
void linked_list<T>::clear()
{
    node *current = head;
    while (current)
    {
        current->element = T();
        current = current->next;
    }
}

template <typename T>
linked_list<T> linked_list<T>::get_subdata(int first_index, int last_index) const
{
    if (!head)
    {
        throw std::out_of_range("List is empty");
    }
    if (first_index < 0 || last_index >= length)
    {
        throw std::out_of_range("Index out of range");
    }
    if (first_index > last_index)
    {
        throw std::out_of_range("Invalid index range");
    }
    linked_list<T> subdata;
    node *start_node = head;
    for (int i = 0; i < first_index; ++i)
    {
        start_node = start_node->next;
    }
    subdata.length = last_index - first_index + 1;
    node **current = &subdata.head;
    node **prev_node = nullptr;
    for (int i = first_index; i <= last_index; ++i)
    {
        *current = new node(start_node->element);
        (*current)->prev = (current == &subdata.head) ? nullptr : *(current - 1);
        prev_node = current;
        current = &((*current)->next);
        start_node = start_node->next;
    }

    subdata.tail = *(current);
    return subdata;
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
