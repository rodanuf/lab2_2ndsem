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
    array_sequence(T *data, int count);
    array_sequence(const dynamic_array<T> &array);
    ~array_sequence();
    T get_first() const override;
    T get_last() const override;
    T get_element(const int index) const override;
    int get_length() const override;
    sequence<T> *get_subsequence(int first_index, int last_index) const override;
    sequence<T> *append_element(const T &element) override;
    sequence<T> *prepend_element(const T &element) override;
    sequence<T> *insert_element(const T &element, const int index) override;
    sequence<T> *concat(const sequence<T> &container) override;
    sequence<T> *immutable_append_element(const T &element) const override;
    sequence<T> *immutable_prepend_element(const T &element) const override;
    sequence<T> *immutable_insert_element(const T &element, const int index) const override;
    sequence<T> *immutable_concat(const sequence<T> &container) const override;
    void print() const override;
    void clear() override;
};

#include "../templates/array_sequence.tpp"