#pragma once

template <typename T>
class linked_list
{
private:
    struct node
    {
        T element;
        node *next;
        node *prev;
        node(const T &n_element)
        {
            next = nullptr;
            prev = nullptr;
            element = n_element;
        }
    };
    node *head;
    node *tail;
    int length;

public:
    class iterator
    {
    public:
        node **current;

        iterator(node *node_p);
        iterator operator++(int);
        iterator &operator++();
        T &operator*() const;
        bool operator==(const iterator &other) const;
        bool operator!=(const iterator &other) const;
    };
    class immutable_iterator
    {
    private:
        node **current;

    public:
        immutable_iterator(node *node_p);
        immutable_iterator operator++(int);
        immutable_iterator &operator++();
        const T &operator*() const;
        bool operator==(const immutable_iterator &other) const;
        bool operator!=(const immutable_iterator &other) const;
    };
    linked_list();
    linked_list(const T *elements, int count);
    linked_list(const linked_list<T> &list);
    ~linked_list();
    T get_first() const;
    T get_last() const;
    T get_element(int index) const;
    int get_length() const;
    void append_element(const T &element);
    void prepend_element(const T &element);
    void insert_element(const T &element, int index);
    void print() const;
    void clear();
    linked_list<T> get_subdata(int first_index, int last_index) const;
    iterator begin() { return iterator(head); };
    iterator end() { return iterator(tail); };
    immutable_iterator begin() const { return immutable_iterator(head); };
    immutable_iterator end() const { return immutable_iterator(tail); };
};

#include "../templates/linked_list.tpp"