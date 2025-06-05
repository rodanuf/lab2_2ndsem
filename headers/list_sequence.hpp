#pragma once
#include <iostream>
#include "linked_list.hpp"
#include "sequence.hpp"

template <typename T>
class list_sequence : public sequence<T>
{
private:
    linked_list<T> list_s;

public:
    list_sequence();
    list_sequence(T *items, int count);
    list_sequence(const linked_list<T> &list);
    ~list_sequence();
    T get_first() override;
    T get_last() override;
    T get_element(int index) override;
    int get_length() override;
    sequence<T> *append_element(T element) override;
    sequence<T> *prepend_element(T element) override;
    sequence<T> *insert_element(T element, int index) override;
    sequence<T> *concat(sequence<T> *list) override;
    sequence<T> *immutable_append_element(T element) override;
    sequence<T> *immutable_prepend_element(T element) override;
    sequence<T> *immutable_insert_element(T element, int index) override;
    sequence<T> *immutable_concat(sequence<T> *container) override;
    void print() override;
    void clear() override;
};

#include "../templates/list_sequence.tpp"