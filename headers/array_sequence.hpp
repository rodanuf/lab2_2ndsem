#pragma once
#include "dynamic_array.hpp"
#include "sequence.hpp"

template <typename T>
class array_sequence : public sequence<T>
{
private:
    dynamic_array<T> array_s;

public:
    array_sequence();
    array_sequence(T *elements, int count);
    array_sequence(const dynamic_array<T> &array);
    ~array_sequence();
    T get_first() override;
    T get_last() override;
    T get_element(int index) override;
    T get_subdata(int first_index, int last_index) override;
    int get_length() override;
    sequence<T> *append_element(T element) override;
    sequence<T> *prepend_element(T element) override;
    sequence<T> *insert_element(T element, int index) override;
    sequence<T> *concat(sequence<T> *container) override;
    sequence<T> *immutable_append_element(T element) override;
    sequence<T> *immutable_prepend_element(T element) override;
    sequence<T> *immutable_insert_element(T element, int index) override;
    sequence<T> *immutable_concat(sequence<T> *container) override;
    void print() override;
    void clear() override;
};

#include "../templates/array_sequence.tpp"