#ifndef TEST_STRUCTURES_HPP
#define TEST_STRUCTURES_HPP

#include <iostream>

#include "colourise_my_prints.hpp"

// A class that does not have a default constructor.
struct No_default {
    No_default(int arg) {
        (void)arg;
    };  // the only constructor for No_default
};

// Templated structs to test for types equality:
template <typename T, typename U>
struct is_same {
    static const bool value = false;
};

template <typename T>
struct is_same<T, T> {
    static const bool value = true;
};

// Test Output Strings
#define TEST_OK BOLD GREEN "OK " RESET
#define TEST_NOK BOLD RED "NOK" RESET

#endif
