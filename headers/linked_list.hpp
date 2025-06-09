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
        node(const T &element)
        {
            next = nullptr;
            prev = nullptr;
            element = element;
        }
    };
    node *head;
    node *tail;
    int length;

public:
    class iterator
    {
    public:
        node *current;

        iterator(node *node_p = nullptr);
        iterator &operator++();
        T &operator*() const;
        bool operator==(const iterator &other) const;
        bool operator!=(const iterator &other) const;
    };
    class immutable_iterator
    {
    private:
        const node *current;

    public:
        immutable_iterator(const node *node_p = nullptr);
        immutable_iterator &operator++();
        const T &operator*() const;
        bool operator==(const iterator &other) const;
        bool operator!=(const iterator &other) const;
    };
    linked_list();
    linked_list(const T *elements, int count);
    linked_list(const linked_list<T> &list);
    ~linked_list();
    T get_first();
    T get_last();
    T get_element(int index);
    linked_list<T> get_subdata(int first_index, int last_index);
    int get_length();
    void append_element(const T &element);
    void prepend_element(const T &element);
    void insert_element(const T &element, int index);
    void print();
    linked_list<T> *concat(linked_list<T> *list);
    iterator begin() { return iterator(head); };
    iterator end() { return iterator(tail); };
    immutable_iterator begin() const { return immutable_iterator(head); };
    immutable_iterator end() const { return immutable_iterator(tail); };
};

#include "../templates/linked_list.tpp"