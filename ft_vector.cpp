#include "ft_vector.hpp"

namespace ft {

// __ MEMBER FUNCTIONS ________________________________________________________
unsigned int Vector::size(void) const { return _size; };

void Vector::test(void) {
    std::cout << "calling Map member function, test " << BOLD LIGHT_GREEN "OK" RESET << std::endl;
};

// __ GETTERS/SETTERS _________________________________________________________
double Vector::get(int index) {
    return (_elements[index]);
};

void Vector::set(int index, double value) {
    _elements[index] = value;
};

// __ CONSTRUCTION/DESTRUCTION ________________________________________________
Vector::Vector(void) : _elements(nullptr), _size(0) {};

// TODO: e se size for < 0
Vector::Vector(int size) : _elements(new double[size]), _size(size) {
    for (unsigned int i = 0; i < _size; i++)
        _elements[i] = 0;
};

Vector::Vector(const Vector&other) : _elements(new double[other._size]), _size(other._size) {
    for (unsigned int i = 0; i < _size; i++)
        _elements[i] = other._elements[i];
};

Vector::~Vector(void) {
    delete[] _elements;
};

// __ OPERATOR OVERLOADS ______________________________________________________
Vector& Vector::operator=(const Vector& other) {
    if (this != &other) {
        double *tempElems = new double[other._size];
        for (unsigned int i = 0; i < other._size; i++) {
            tempElems[i] = other._elements[i];
        }

        delete[] _elements;
        _elements = tempElems;
        _size = other._size;
    }
    return (*this);
};

}  // namespace ft
