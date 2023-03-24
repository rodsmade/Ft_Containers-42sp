#include "ft_vector.hpp"

#include <iostream>

namespace ft {

unsigned int Vector::size(void) const { return _size; };

void Vector::test(void) {
    std::cout << "calling Map member function, test OK!" << std::endl;
};


double Vector::get(int index) {
    return (_elements[index]);
};

void Vector::set(int index, double value) {
    _elements[index] = value;
};

Vector::Vector(int size) : _elements(new double[size]), _size(size) {
    for (unsigned int i = 0; i < _size; i++)
        _elements[i] = 0;
};

Vector::~Vector(void) {
    delete[] _elements;
};

}  // namespace ft
