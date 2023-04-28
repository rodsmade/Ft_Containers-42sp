#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP

#include <iostream>     // printing, etc.
#include <memory>       // std::allocator
#include <stdexcept>    // std::out_of_range
#include <sstream>      // std::ostringstream
// #include <climits>      // LONG_MAX
#include <limits>      // numeric_limits<>

#include "colourise_my_prints.hpp"

namespace ft {

template < typename T, typename A = std::allocator<T> >
class vector {
   public:

    /*=============================================
    ===                ALIASES                  ===
    =============================================*/
    //  Aliases function as an interface for containers to be handled the same. They each will have their size_type, value_type, iterator and etc. const_iterator. This is called Generic Programming.
    typedef unsigned long size_type;
    typedef T value_type;
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef T& reference;
    typedef const T& const_reference;
    typedef std::reverse_iterator<iterator> reverse_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
    // template<typename C>
    // using Iterator = typename C::iterator;

    /*=============================================
    ===            MEMBER FUNCTIONS             ===
    =============================================*/
    reference               at(size_type i);
    const_reference         at(size_type i) const;
    reference               back();
    const_reference         back() const;
    size_type               capacity(void) const;
    void                    clear();
    value_type*             data();
    const value_type*       data() const;
    bool                    empty() const;
    reference               front();
    const_reference         front() const;
    size_type               max_size() const;
    void                    pop_back();
    void                    push_back(const_reference newElem);
    void                    reserve(size_type newCapacity);
    void                    resize(size_type newSize, value_type value = value_type());
    size_type               size(void) const;

    // TODO:
    void                    assign(size_type count, const_reference value);
    template<class InputIt>
    void                    assign(InputIt first, InputIt last);
    iterator                begin();
    const_iterator          begin() const;
    iterator                end();
    const_iterator          end() const;
    iterator                erase(iterator pos);
    iterator                erase(iterator first, iterator last);
    // allocator_type          get_allocator() const;
    iterator                insert(const_iterator pos, const_reference value);
    iterator                insert(const_iterator pos, size_type count, const_reference value);
    template< class InputIt >
    iterator                insert(const_iterator pos, InputIt first, InputIt last);
    reverse_iterator        rbegin();
    const_reverse_iterator  rbegin() const;
    reverse_iterator        rend();
    const_reverse_iterator  rend() const;
    void                    swap(vector& other);

    // TODO: remove before submission:
    static void test(void);
    void printAll(void);
    void fill(vector<T, A>& vector, const_reference value);

    /*=============================================
    ===      CONSTRUCTION / DESTRUCTION         ===
    =============================================*/
    vector();
    explicit vector(size_type size);
    //  the explicit keyword forbids implicit conversion of any type into a vector, which avoids bugs and makes code clearer and explicit.
    vector(const vector& other);
    ~vector();

    // TODO:
    // explicit vector(size_type count, const_reference value = T(), const Allocator& alloc = Allocator());
    // template<class InputIt>
    // vector(InputIt first, InputIt last, const Allocator& alloc = Allocator());


    /*=============================================
    ===           OPERATOR OVERLOADS            ===
    =============================================*/
    vector&         operator=(const vector& other);
    reference       operator[](size_type index);  // for non-const vectors
    //  returns a reference, i. e., the object itself, knowing this "address" won't possibly change or be changed, but its contents can.
    const_reference operator[](size_type index) const;  // for const vectors
    //  returns a *copy* of what is stored in the nth element. it is not the object itself, so its contents can't be assigned something else (not an l-value)

   private:
    A _allocator;
    value_type* _elements;
    size_type _size;
    size_type _capacity;

    std::string getOutOfRangeErrorMessage(size_type index) const;
};

/*=============================================
===          NON-MEMBER FUNCTIONS           ===
=============================================*/
// TODO:
// template< class T, class Alloc >
// bool operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);
// template< class T, class Alloc >
// bool operator!=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);
// template< class T, class Alloc >
// bool operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);
// template< class T, class Alloc >
// bool operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);
// template< class T, class Alloc >
// bool operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);
// template< class T, class Alloc >
// bool operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);

// template< class T, class Alloc >
// void swap(vector<T, Alloc>& lhs, vector<T, Alloc>& rhs);

};  // namespace ft

#include "ft_vector.tpp"

#endif
