#pragma once
#include <iostream>
#include "sequence.hpp"
#include "array_sequence.hpp"
#include "list_sequence.hpp"

template <typename T>
void print(sequence<T> *container);
void check_input(int &choice);
void get_types_menu(int &sequence_type);
template <typename T>
void get_sequence_type(int &sequence_type);
template <typename T>
void sequence_menu(sequence<T> *sequence);