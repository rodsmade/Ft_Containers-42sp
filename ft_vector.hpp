#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP

#include <iostream>  // printing, etc.
#include <memory>    // std::allocator

#include "colourise_my_prints.hpp"

namespace ft {

class Vector {
   public:
    unsigned int size(void) const;
    static void test(void);

    double get(int index);
    void set(int index, double value);

    Vector();
    explicit Vector(int size);
    Vector(const Vector& other);
    ~Vector();
    Vector& operator=(const Vector& other);

   private:
    double* _elements;
    unsigned int _size;
};

}  // namespace ft

#endif
