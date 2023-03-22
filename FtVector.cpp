#include "FtVector.hpp"

unsigned int FtVector::size(void) const { return _size; };

double FtVector::get(int index) {
    return (_elements[index]);
};

void FtVector::set(int index, double value) {
    _elements[index] = value;
};


FtVector::FtVector(int size) : _size(size) {
    _elements = new double[_size];

    for (unsigned int i = 0; i < _size; i++)
        _elements[i] = 0;
};

FtVector::~FtVector(void) {
    delete[] _elements;
};

