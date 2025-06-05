#pragma once

template <typename T>
class sequence
{
public:
    // не должно быть пустой реализации методов
    // virtual destructor
    virtual T &get_element(int index);
    virtual T &get_first() {};
    virtual T &get_last() {};
    virtual int get_length() {};
    virtual sequence<T> *get_subdata(int firs_index, int last_index) {};
    virtual sequence<T> *append_element(T element) {};
    virtual sequence<T> *prepend_element(T element) {};
    virtual sequence<T> *insert_element(T element, int index) {};
    virtual sequence<T> *concat(sequence<T> *container) {}; // const
    virtual sequence<T> *immutable_append_element(T element) {};
    virtual sequence<T> *immutable_prepend_element(T element) {};
    virtual sequence<T> *immutable_insert_element(T element, int index) {};
    virtual sequence<T> *immutable_concat(sequence<T> *container) {};
    virtual void print();
    virtual void clear();
};