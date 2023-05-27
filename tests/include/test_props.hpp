#ifndef TEST_STRUCTURES_HPP
# define TEST_STRUCTURES_HPP

# include <iostream>

# include "colourise_my_prints.hpp"

// Test Output Strings
# define TEST_OK "[ " BOLD GREEN "OK " RESET " ]\t"
# define TEST_NOK "[ " BOLD RED "NOK" RESET " ]\t"

// A class that does not have a default constructor.
class No_default {
   private:
    int _value;
   public:
    No_default(int arg) : _value(arg) {};  // the only constructor for No_default
    const No_default &operator=(const No_default &other) {
        if (*this != other)
            this->_value = other._value;
        return (*this);
    };
    bool operator==(const No_default &other) const { return (_value == other._value); };
    bool operator!=(const No_default &other) const { return (!(_value == other._value)); };
    bool operator<(const No_default &other) const { return (_value < other._value); };
    bool operator<=(const No_default &other) const { return (_value < other._value || _value == other._value); };
    bool operator>(const No_default &other) const { return (!(_value <= other._value)); };
    bool operator>=(const No_default &other) const { return (!(_value < other._value)); };
};

// A class that does have a default constructor.
struct Has_default {
   private:
    int _value;
   public:
    Has_default() : _value(42) {};
    const Has_default &operator=(const Has_default &other) {
        if (*this != other)
            this->_value = other._value;
        return (*this);
    };
    bool operator==(const Has_default &other) const { return (_value == other._value); };
    bool operator!=(const Has_default &other) const { return (!(_value == other._value)); };
    bool operator<(const Has_default &other) const { return (_value < other._value); };
    bool operator<=(const Has_default &other) const { return (_value < other._value || _value == other._value); };
    bool operator>(const Has_default &other) const { return (!(_value <= other._value)); };
    bool operator>=(const Has_default &other) const { return (!(_value < other._value)); };
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

// Testing Functions
void    assert(bool condition, const std::string& tagline = "");

#endif
