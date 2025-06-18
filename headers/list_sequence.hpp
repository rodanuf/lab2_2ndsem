#pragma once
#include "linked_list.hpp"
#include "sequence.hpp"
#include <memory>
#include <typeinfo.h>

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
        list_sequence_iterator(typename linked_list<T>::iterator it) : current(it) {}
        list_sequence_iterator &operator++() override
        {
            if (current)
                current = current->next;
            return *this;
        }
        list_sequence_iterator operator++(int) override
        {
            list_sequence_iterator old = *this;
            ++current;
            return old;
        }
        T &operator*() const override
        {
            if (!current)
                throw std::out_of_range("Invalid iterator");
            return current->element;
        }
        bool operator==(const typename sequence<T>::iterator_s &other) const override
        {
            auto derived = dynamic_cast<const list_sequence_iterator *>(&other);
            return derived && current == derived->current;
        }

        bool operator!=(const typename sequence<T>::iterator_s &other) const override
        {
            return !(*this == other);
        }
        std::unique_ptr<typename sequence<T>::iterator_s> clone() const override
        {
            return std::make_unique<list_sequence_iterator>(current);
        }
    };
    class i_list_sequence_iterator : public sequence<T>::immutable_iterator_s
    {
        typename linked_list<T>::const_iterator current;

    public:
        i_list_sequence_iterator(typename linked_list<T>::iterator it) : current(it) {};
        i_list_sequence_iterator &operator++() override
        {
            if (current)
                current = current->next;
            return *this;
        }
        i_list_sequence_iterator operator++(int) override
        {
            i_list_sequence_iterator old = *this;
            ++current;
            return old;
        }
        const T &operator*() const override
        {
            if (!current)
                throw std::out_of_range("Invalid iterator");
            return current->element;
        }
        bool operator==(const typename sequence<T>::immutable_iterator_s &other) const override
        {
            auto derived = dynamic_cast<const i_list_sequence_iterator *>(&other);
            return derived && current == derived->current;
        }
        bool operator!=(const typename sequence<T>::immutable_iterator_s &other) const override
        {
            return !(*this == other);
        }
        std::unique_ptr<typename sequence<T>::immutable_iterator_s> clone() const override
        {
            return std::make_unique<i_list_sequence_iterator>(current);
        }
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
    std::unique_ptr<typename sequence<T>::iterator_s> begin() override
    {
        return std::make_unique<list_sequence_iterator>(list_s.begin());
    }
    std::unique_ptr<typename sequence<T>::iterator_s> end() override
    {
        return std::make_unique<list_sequence_iterator>(list_s.end());
    }
    std::unique_ptr<typename sequence<T>::immutable_iterator_s> cbegin() const override
    {
        return std::make_unique<i_list_sequence_iterator>(list_s.begin());
    }
    std::unique_ptr<typename sequence<T>::immutable_iterator_s> cend() const override
    {
        return std::make_unique<i_list_sequence_iterator>(list_s.end());
    }
    void print() const override;
    void clear() override;
};

#include "../templates/list_sequence.tpp"