#pragma once
#include "dynamic_array.hpp"
#include "sequence.hpp"

template <typename T>
class array_sequence : public sequence<T>
{
private:
    dynamic_array<T> array_s;

public:
    class array_sequence_iterator : public sequence<T>::iterator_s
    {
        T *current;
        T *end;

    public:
        array_sequence_iterator(T *begin, T *end) : current(begin), end(end) {}

        array_sequence_iterator &operator++() override
        {
            if (current != end)
                ++current;
            return *this;
        }

        array_sequence_iterator operator++(int) override
        {
            array_sequence_iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        T &operator*() const override
        {
            if (current == end)
                throw std::out_of_range("Iterator out of range");
            return *current;
        }

        bool operator==(const typename sequence<T>::iterator_s &other) const override
        {
            auto derived = dynamic_cast<const array_sequence_iterator *>(&other);
            return derived && current == derived->current;
        }

        bool operator!=(const typename sequence<T>::iterator_s &other) const override
        {
            return !(*this == other);
        }

        std::unique_ptr<typename sequence<T>::iterator_s> clone() const override
        {
            return std::make_unique<array_sequence_iterator>(*this);
        }
    };
    class i_array_sequence_iterator : public sequence<T>::immutable_iterator_s
    {
        const T *current;
        const T *end;

    public:
        i_array_sequence_iterator(const T *begin, const T *end) : current(begin), end(end) {}

        i_array_sequence_iterator &operator++() override
        {
            if (current != end)
                ++current;
            return *this;
        }

        i_array_sequence_iterator operator++(int) override
        {
            i_array_sequence_iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        const T &operator*() const override
        {
            if (current == end)
                throw std::out_of_range("Iterator out of range");
            return *current;
        }

        bool operator==(const typename sequence<T>::immutable_iterator_s &other) const override
        {
            auto derived = dynamic_cast<const i_array_sequence_iterator *>(&other);
            return derived && current == derived->current;
        }

        bool operator!=(const typename sequence<T>::immutable_iterator_s &other) const override
        {
            return !(*this == other);
        }

        std::unique_ptr<typename sequence<T>::immutable_iterator_s> clone() const override
        {
            return std::make_unique<i_array_sequence_iterator>(*this);
        }
    };
    array_sequence();
    array_sequence(T *elements, int count);
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
    std::unique_ptr<typename sequence<T>::iterator_s> begin() override
    {
        return std::make_unique<array_sequence_iterator>(array_s.get_data(), array_s.get_data() + array_s.get_size());
    }
    std::unique_ptr<typename sequence<T>::iterator_s> end() override
    {
        return std::make_unique<array_sequence_iterator>(array_s.get_data() + array_s.get_size(), array_s.get_data() + array_s.get_size());
    }
    std::unique_ptr<typename sequence<T>::immutable_iterator_s> cbegin() const override
    {
        return std::make_unique<i_array_sequence_iterator>(array_s.get_data(), array_s.get_data() + array_s.get_size());
    }
    std::unique_ptr<typename sequence<T>::immutable_iterator_s> cend() const override
    {
        return std::make_unique<i_array_sequence_iterator>(array_s.get_data() + array_s.get_size(), array_s.get_data() + array_s.get_size());
    }
    void print() const override;
    void clear() override;
};

#include "../templates/array_sequence.tpp"