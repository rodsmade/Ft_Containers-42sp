#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP

#include <cstddef>      // std::size_t, std::ptrdiff_t
#include <iostream>     // printing, etc.
#include <memory>       // std::allocator
#include <sstream>      // std::ostringstream
#include <stdexcept>    // std::out_of_range

namespace ft {

template < typename T, typename A = std::allocator<T> >
class vector {
   public:

    /*=============================================
    ===                ALIASES                  ===
    =============================================*/
    //  Aliases function as an interface for containers to be handled the same. They each will have their size_type, value_type, iterator and etc. const_iterator. This is called Generic Programming.
    typedef T value_type;
    typedef A allocator_type;
    typedef std::size_t size_type;
    typedef std::ptrdiff_t difference_type;
    typedef T& reference;
    typedef const T& const_reference;
    typedef typename allocator_type::pointer pointer;
    typedef typename allocator_type::const_pointer const_pointer;
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;
    typedef const reverse_iterator const_reverse_iterator;

    /*=============================================
    ===            MEMBER FUNCTIONS             ===
    =============================================*/
    // Iterators:
    iterator                begin();
    const_iterator          begin() const;
    iterator                end();
    const_iterator          end() const;
    reverse_iterator        rbegin();
    const_reverse_iterator  rbegin() const;
    reverse_iterator        rend();
    const_reverse_iterator  rend() const;

    // Capacity:
    size_type               capacity(void) const;
    bool                    empty() const;
    size_type               max_size() const;
    void                    reserve(size_type newCapacity);
    void                    resize(size_type newSize, value_type value = value_type());
    size_type               size(void) const;

    // Element Access:
    reference               at(size_type i);
    const_reference         at(size_type i) const;
    reference               back();
    const_reference         back() const;
    value_type*             data();
    const value_type*       data() const;
    reference               front();
    const_reference         front() const;

    // Modifiers:
    template <class InputIt>
    void                    assign(InputIt first, InputIt last);
    void                    assign(size_type count, const_reference value);
    void                    clear();
    iterator                erase(iterator pos);
    iterator                erase(iterator first, iterator last);
    iterator                insert(const_iterator pos, const_reference value);
    iterator                insert(const_iterator pos, size_type count, const_reference value);
    template < class InputIt >
    iterator                insert(const_iterator pos, InputIt first, InputIt last);
    void                    pop_back();
    void                    push_back(const_reference newElem);
    void                    swap(vector& other);

    // Allocator:
    allocator_type          get_allocator() const;

    /*=============================================
    ===      CONSTRUCTION / DESTRUCTION         ===
    =============================================*/
    // Default Constructor
    explicit vector(const allocator_type& alloc = allocator_type()); //  the explicit keyword forbids implicit conversion of any type into a vector, which avoids bugs and makes code clearer and explicit.
    // Fill Constructor
    explicit vector(size_type size, const_reference value = T(), const allocator_type& allocator = allocator_type());
    // Range Constructor
    template <class InputIt>
    vector(InputIt first, InputIt last, const allocator_type& allocator = allocator_type());
    // Copy Constructor
    vector(const vector& other);
    // Destructor
    ~vector();

    /*=============================================
    ===           OPERATOR OVERLOADS            ===
    =============================================*/
    vector&         operator=(const vector& other);
    // for non-const vectors:
    reference       operator[](size_type index);  //  returns a reference, i. e., the object itself, knowing this "address" won't possibly change or be changed, but its contents can.
    // for const vectors:
    const_reference operator[](size_type index) const;  //  returns a *copy* of what is stored in the nth element. it is not the object itself, so its contents can't be assigned something else (not an l-value)

   private:
    /*=============================================
    ===              ATTRIBUTES                 ===
    =============================================*/
    allocator_type  _allocator;
    value_type*     _elements;
    size_type       _size;
    size_type       _capacity;

    /*=============================================
    ===        PRIVATE MEMBER FUNCTIONS         ===
    =============================================*/
    std::string     getOutOfRangeErrorMessage(size_type index) const;
};

/*=============================================
===          NON-MEMBER FUNCTIONS           ===
=============================================*/
/*********************************************/
/*           OPERATOR OVERLOADS              */
/*********************************************/
template < class T, class Alloc >
bool operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);
template < class T, class Alloc >
bool operator!=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);
template < class T, class Alloc >
bool operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);
template < class T, class Alloc >
bool operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);
template < class T, class Alloc >
bool operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);
template < class T, class Alloc >
bool operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs);

/*********************************************/
/*                  OTHER                    */
/*********************************************/
template < class T, class Alloc >
void swap(vector<T, Alloc>& lhs, vector<T, Alloc>& rhs);

};  // namespace ft

#include "ft_vector.tpp"

#endif
