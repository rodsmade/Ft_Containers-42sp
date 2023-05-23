#ifndef FT_SET_HPP
#define FT_SET_HPP

// #include <cstddef>      // std::size_t, std::ptrdiff_t
// #include <iostream>     // printing, etc.
// #include <sstream>      // std::ostringstream
// #include <stdexcept>    // std::out_of_range
#include <functional>   // std::less
#include <memory>       // std::allocator

namespace ft {

template <class T>
class TreeNode {
   public:
    TreeNode    *_left;
    TreeNode    *_right;
    T           *content;
};

template <class T, class Compare = std::less<T>, class Allocator = std::allocator<T> >
class set {
   protected:
    TreeNode    *_tree;

   public:
    /*=============================================
    ===                ALIASES                  ===
    =============================================*/
    // typedef T value_type;
    typedef [...] key_type
    typedef [...] value_type
    typedef [...] key_compare
    typedef [...] value_compare
    typedef [...] allocator_type
    typedef [...] reference
    typedef [...] const_reference
    typedef [...] pointer
    typedef [...] const_pointer
    typedef [...] iterator
    typedef [...] const_iterator
    typedef [...] reverse_iterator
    typedef [...] const_reverse_iterator
    typedef [...] difference_type
    typedef [...] size_type

    /*=============================================
    ===            MEMBER FUNCTIONS             ===
    =============================================*/
    // Allocator:
    allocator_type                              get_allocator() const;

    // Iterators:
    iterator                                    begin();
    const_iterator                              begin() const;
    iterator                                    end();
    const_iterator                              end() const;
    reverse_iterator                            rbegin();
    const_reverse_iterator                      rbegin() const;
    reverse_iterator                            rend();
    const_reverse_iterator                      rend() const;

    // Capacity:
    bool                                        empty() const;
    size_type                                   max_size() const;
    size_type                                   size() const;

    // Modifiers:
    void                                        clear();
    iterator                                    erase( iterator pos );
    iterator                                    erase( iterator first, iterator last );
    size_type                                   erase( const Key& key );
    std::pair<iterator, bool>                   insert(const value_type& value);
    iterator                                    insert( iterator pos, const value_type& value );
    template< class InputIt >
    void                                        insert( InputIt first, InputIt last );
    void                                        swap( set& other );

    // Lookup:
    size_type                                   count( const Key& key ) const;
    iterator                                    find( const Key& key );
    const_iterator                              find( const Key& key ) const;
    std::pair<iterator,iterator>                equal_range( const Key& key );
    std::pair<const_iterator,const_iterator>    equal_range( const Key& key ) const;
    iterator                                    lower_bound( const Key& key );
    const_iterator                              lower_bound( const Key& key ) const;
    iterator                                    upper_bound( const Key& key );
    const_iterator                              upper_bound( const Key& key ) const;

    // Onservers:
    key_compare                                 key_comp() const;
    ft::set::value_compare                      value_comp() const;

    /*=============================================
    ===      CONSTRUCTION / DESTRUCTION         ===
    =============================================*/
    // Default:
    set();
    explicit set(const Compare& comp, const Allocator& alloc = Allocator());

    // Range:
    template< class InputIt >
    set( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() );

    // Copy:
    set( const set& other );

    // Destructor:
    ~set();

    // Get_allocator:

    /*=============================================
    ===           OPERATOR OVERLOADS            ===
    =============================================*/
    set& operator=(const set& other);

   private:
    /*=============================================
    ===              ATTRIBUTES                 ===
    =============================================*/
};

/*=============================================
===          NON-MEMBER FUNCTIONS           ===
=============================================*/
/*********************************************/
/*           OPERATOR OVERLOADS              */
/*********************************************/
template <class T, class Compare, class Allocator>
bool operator==(const set<T, Compare, Allocator>& lhs, const set<T, Compare, Allocator>& rhs);
template <class T, class Compare, class Allocator>
bool operator!=(const set<T, Compare, Allocator>& lhs, const set<T, Compare, Allocator>& rhs);
template <class T, class Compare, class Allocator>
bool operator<(const set<T, Compare, Allocator>& lhs, const set<T, Compare, Allocator>& rhs);
template <class T, class Compare, class Allocator>
bool operator<=(const set<T, Compare, Allocator>& lhs, const set<T, Compare, Allocator>& rhs);
template <class T, class Compare, class Allocator>
bool operator>(const set<T, Compare, Allocator>& lhs, const set<T, Compare, Allocator>& rhs);
template <class T, class Compare, class Allocator>
bool operator>=(const set<T, Compare, Allocator>& lhs, const set<T, Compare, Allocator>& rhs);

/*********************************************/
/*                  OTHER                    */
/*********************************************/
template <class Key, class Compare, class Allocator>
void swap(ft::set<Key, Compare, Allocator>& lhs, ft::set<Key, Compare, Allocator>& rhs );

};  // namespace ft

#include "ft_set.tpp"

#endif
