#pragma once
#include "linked_list.hpp"
#include "sequence.hpp"

template <typename T>
class list_sequence : public sequence<T>
{
private:
    linked_list<T> list_s;

public:
    class list_sequence_iterator : public sequence<T>::iterator_s
    {
        typename linked_list<T>::iterator current;

    public:
        list_sequence_iterator(typename linked_list<T>::iterator it);
        list_sequence_iterator &operator++() override;
        list_sequence_iterator operator++(int) override;
        T &operator*() const override;
        bool operator==(const iterator_s &other) const override;
        bool operator!=(const iterator_s &other) const override;
    };
    class i_list_sequence_iterator : public sequence<T>::immutable_iterator_s
    {
        typename linked_list<T>::const_iterator current;

    public:
        i_list_sequence_iterator(typename linked_list<T>::iterator it);
        i_list_sequence_iterator &operator++() override;
        i_list_sequence_iterator operator++(int) override;
        const T &operator*() const override;
        bool operator==(const immutable_iterator_s &other) const override;
        bool operator!=(const immutable_iterator_s &other) const override;
    };
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
    sequence<T> *concat(const sequence<T> &container) override;
    sequence<T> *immutable_append_element(const T &element) const override;
    sequence<T> *immutable_prepend_element(const T &element) const override;
    sequence<T> *immutable_insert_element(const T &element, const int index) const override;
    sequence<T> *immutable_concat(const sequence<T> &container) const override;
    iterator_s begin() { return iterator_s(list_s.begin()); }
    std::unique_ptr<typename sequence<T>::iterator_s> begin() override
    {
        return std::make_unique<list_sequence_iterator>(list_s.begin());
    }
    std::unique_ptr<typename sequence<T>::iterator_s> end() override
    {
        return std::make_unique<list_sequence_iterator>(list_s.end());
    }
    std::unique_ptr<typename sequence<T>::immutable_iterator_s> begin() const override
    {
        return std::make_unique<i_list_sequence_iterator>(list_s.begin());
    }

    std::unique_ptr<typename sequence<T>::immutable_iterator_s> end() const override
    {
        return std::make_unique<i_list_sequence_iterator>(list_s.end());
    }
    void print() const override;
    void clear() override;
};

#include "../templates/list_sequence.tpp"