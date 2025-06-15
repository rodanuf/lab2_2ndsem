#pragma once
#include "sequence.hpp"
#include "array_sequence.hpp"
#include "list_sequence.hpp"

void get_types_menu(int &sequence_type);
template <typename T>
void get_sequence_type(int &sequence_type);
template <typename T>
void sequence_menu(sequence<T> *sequence);