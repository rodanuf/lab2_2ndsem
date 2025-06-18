#pragma once
#include <memory>

template <typename T>
class sequence
{
public:
    class iterator_s
    {
    public:
        virtual ~iterator_s() = default;
        virtual iterator_s operator++(int) = 0;
        virtual iterator_s &operator++() = 0;
        virtual T &operator*() const = 0;
        virtual bool operator==(const iterator_s &other) const = 0;
        virtual bool operator!=(const iterator_s &other) const = 0;
        virtual std::unique_ptr<iterator_s> clone() const = 0;
    };
    class immutable_iterator_s
    {
    public:
        virtual ~immutable_iterator_s() = default;
        virtual immutable_iterator_s operator++(int) = 0;
        virtual immutable_iterator_s &operator++() = 0;
        virtual const T &operator*() const = 0;
        virtual bool operator==(const immutable_iterator_s &other) const = 0;
        virtual bool operator!=(const immutable_iterator_s &other) const = 0;
        virtual std::unique_ptr<immutable_iterator_s> clone() const = 0;
    };
    virtual std::unique_ptr<iterator_s> begin() = 0;
    virtual std::unique_ptr<iterator_s> end() = 0;
    virtual std::unique_ptr<immutable_iterator_s> cbegin() const = 0;
    virtual std::unique_ptr<immutable_iterator_s> cend() const = 0;
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
    virtual void print() const = 0;
    virtual void clear() = 0;
};