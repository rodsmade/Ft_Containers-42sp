#include "FtVector.hpp"

FtVector::FtVector(int size) : _size(size) {
    _elements = new double[_size];

    for (int i = 0; i < _size; i++)
        _elements[i] = 0;
};

unsigned int FtVector::getSize(void) const { return _size; };
