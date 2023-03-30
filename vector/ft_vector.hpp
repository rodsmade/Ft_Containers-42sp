#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP

#include <iostream>  // printing, etc.
#include <memory>    // std::allocator

#include "colourise_my_prints.hpp"

namespace ft {

template <typename T>
class Vector {
   public:
    unsigned int size(void) const;
    unsigned int capacity(void) const;
    void reserve(unsigned int newCapacity);
    void resize(unsigned int newSize);
    void push_back(T newElem);

    // TODO: remove before submission:
    static void test(void);
    void printAll(void);

    Vector();
    explicit Vector(int size);
    Vector(const Vector& other);
    ~Vector();
    Vector& operator=(const Vector& other);
    T &operator[](int index); // returns a reference, i. e., the object itself, knowing this "address" won't possibly change or be changed.
    const T &operator[](int index) const; // returns a *copy* of what is stored in the nth element. it is not the object itself, so it can't be assigned something else (not an l-value)

   private:
    T* _elements;
    unsigned int _size;
    unsigned int _capacity;
};

};  // namespace ft

#include "ft_vector.tpp"

#endif
