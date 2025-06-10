#pragma once
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
    T get_first() const override;
    T get_last() const override;
    T get_element(const int index) const override;
    int get_length() const override;
    sequence<T> *get_subsequence(int start_index, int end_index) const override;
    sequence<T> *append_element(const T &element) override;
    sequence<T> *prepend_element(const T &element) override;
    sequence<T> *insert_element(const T &element, const int index) override;
    sequence<T> *concat(const sequence<T> *list) override;
    sequence<T> *immutable_append_element(const T &element) const override;
    sequence<T> *immutable_prepend_element(const T &element) const override;
    sequence<T> *immutable_insert_element(const T &element, const int index) const override;
    sequence<T> *immutable_concat(const sequence<T> *container) const override;
    void print() const override;
    void clear() override;
};

#include "../templates/list_sequence.tpp"