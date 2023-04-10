#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP

#include <iostream>  // printing, etc.
#include <memory>    // std::allocator
#include <stdexcept>

#include "colourise_my_prints.hpp"

namespace ft {

template <typename T>
class vector {
   public:

    // Aliases pra abstrair ao máximo pra cada container o que vale seu size_type, value_type, iterator e const_iterator. Generic Programming beb
    using size_type = unsigned long;
    using value_type = T;
    using iterator = T*;
    using const_iterator = const T*;

    size_type size(void) const;
    size_type capacity(void) const;
    void reserve(size_type newCapacity);
    void resize(size_type newSize);
    void push_back(T newElem);
    T& at(size_type i);
    const T& at(size_type i) const;

    // TODO: remove before submission:
    static void test(void);
    void printAll(void);
    void fill(vector<T>& vector, const T& value);

    vector();
    // the explicit keyword forbids implicit conversion of any type into a vector, which avoids bugs and makes code clearer and explicit.
    explicit vector(size_type size);
    vector(const vector& other);
    ~vector();
    vector& operator=(const vector& other);
    T& operator[](size_type index);              // returns a reference, i. e., the object itself, knowing this "address" won't possibly change or be changed, but its contents can.
    const T& operator[](size_type index) const;  // returns a *copy* of what is stored in the nth element. it is not the object itself, so its contents can't be assigned something else (not an l-value)

   private:
    T* _elements;
    size_type _size;
    size_type _capacity;

    std::string getOutOfRangeErrorMessage(size_type index) const;
};

};  // namespace ft

#include "ft_vector.tpp"

#endif
