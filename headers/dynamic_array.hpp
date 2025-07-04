#pragma once

template <typename T>
class dynamic_array
{
private:
    T *data;
    int length;
    int capacity;

public:
    dynamic_array();
    dynamic_array(int length);
    dynamic_array(T *elements, int length);
    dynamic_array(const dynamic_array<T> &dynamic_array);
    ~dynamic_array();
    T get_element(int index) const;
    int get_length() const;
    void set_element(int index, T value);
    void resize(int new_length);
    void append_element(const T &element);
    void prepend_element(const T &element);
    void insert_element(const T &element, const int index);
    void clear();
};

#include "../templates/dynamic_array.tpp"