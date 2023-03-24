#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP

#include <iostream> // printing, etc.
#include <memory> // std::allocator

namespace ft {

class Vector {
   public:
    unsigned int size(void) const;
    static void test(void);

    double get(int index);
    void set(int index, double value);

    Vector(int size);
    Vector(const Vector& other);
    ~Vector();

   private:
    double *_elements;
    unsigned int _size;
};

}  // namespace ft

#endif
