#pragma once

template <typename T>
class sequence
{
public:
    virtual ~sequence() = default;
    virtual T get_element(const int index) const = 0;
    virtual T get_first() const = 0;
    virtual T get_last() const = 0;
    virtual int get_length() const = 0;
    virtual sequence<T> *get_subsequence(int firs_index, int last_index) const = 0;
    virtual sequence<T> *append_element(const T &element) = 0;
    virtual sequence<T> *prepend_element(const T &element) = 0;
    virtual sequence<T> *insert_element(const T &element, const int index) = 0;
    virtual sequence<T> *concat(const sequence<T> &container) = 0;
    virtual sequence<T> *immutable_append_element(const T &element) const = 0;
    virtual sequence<T> *immutable_prepend_element(const T &element) const = 0;
    virtual sequence<T> *immutable_insert_element(const T &element, int index) const = 0;
    virtual sequence<T> *immutable_concat(const sequence<T> &container) const = 0;
    virtual void clear() = 0;
};