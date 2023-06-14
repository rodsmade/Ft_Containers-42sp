#ifndef FT_MAP_HPP
#define FT_MAP_HPP

// #include <cstddef>      // std::size_t, std::ptrdiff_t
// #include <iostream>     // printing, etc.
// #include <sstream>      // std::ostringstream
// #include <stdexcept>    // std::out_of_range
#include <functional>   // std::less
#include <memory>       // std::allocator

#include "BinaryTree.hpp"
// #include "BinaryTreeIterator.hpp"

namespace ft {

// template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T> > >
template <class T, class Compare = std::less<T>, class Allocator = std::allocator<T> >
class map {
   public:
    /*=============================================
    ===                ALIASES                  ===
    =============================================*/
    // typedef T value_type;
    // typedef Key key_type;
    // typedef std::pair<const Key, T> value_type;
    typedef T value_type;
    typedef Compare key_compare;
    typedef T mapped_type;
    typedef std::size_t size_type;
    typedef std::ptrdiff_t difference_type;
    typedef Allocator allocator_type;
    // typedef [...] reference;
    // typedef [...] const_reference;
    // typedef [...] pointer;
    // typedef [...] const_pointer;
    // typedef BinaryTreeIterator<T> iterator;
    // typedef [...] const_iterator;
    // typedef [...] reverse_iterator;
    // typedef [...] const_reverse_iterator;

    /*=============================================
    ===            MEMBER FUNCTIONS             ===
    =============================================*/
    // Allocator:
    allocator_type                              get_allocator() const;

    // Element Access:
    // T& at( const Key& key );
    // const T& at( const Key& key ) const;
    // T& operator[]( const Key& key );

    // Iterators:
    // iterator                                    begin();
    // const_iterator                              begin() const;
    // iterator                                    end();
    // const_iterator                              end() const;
    // reverse_iterator                            rbegin();
    // const_reverse_iterator                      rbegin() const;
    // reverse_iterator                            rend();
    // const_reverse_iterator                      rend() const;

    // Capacity:
    bool                                        empty() const;
    size_type                                   max_size() const;
    size_type                                   size() const;

    // Modifiers:
    void                                        clear();
    // iterator                                    erase( iterator pos );
    // iterator                                    erase( iterator first, iterator last );
    // ATTENTION: TO IGNORANDO TUDO O QUE É KEY E TROCANDO PRA T, DEPOIS VOLTAR !!!!!!
    // size_type                                   erase( const Key& key );
    size_type                                   erase( const T& key );
    // std::pair<iterator, bool>                   insert(const value_type& value);
    // TODO: adequar o protótipo abaixo (devolve bool) pro de cima (devolve pair<iterator, bool>)
    bool                                        insert(const value_type& value);
    // iterator                                    insert( iterator pos, const value_type& value );
    template< class InputIt >
    void                                        insert( InputIt first, InputIt last );
    void                                        swap( map& other );

    // Lookup:
    // size_type                                   count( const Key& key ) const;
    // iterator                                    find( const Key& key );
    // const_iterator                              find( const Key& key ) const;
    // std::pair<iterator,iterator>                equal_range( const Key& key );
    // std::pair<const_iterator,const_iterator>    equal_range( const Key& key ) const;
    // iterator                                    lower_bound( const Key& key );
    // const_iterator                              lower_bound( const Key& key ) const;
    // iterator                                    upper_bound( const Key& key );
    // const_iterator                              upper_bound( const Key& key ) const;

    // Observers:
    key_compare                                 key_comp() const;
    // ft::map::value_compare                      value_comp() const;

    /*=============================================
    ===      CONSTRUCTION / DESTRUCTION         ===
    =============================================*/
    // Default:
    explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());

    // Range:
    template <class InputIterator>
    map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());

    // Copy:
    map(const map& other);

    // Destructor:
    ~map();

    /*=============================================
    ===           OPERATOR OVERLOADS            ===
    =============================================*/
    map& operator=(const map& other);

   private:
    /*=============================================
    ===              ATTRIBUTES                 ===
    =============================================*/
    BinaryTree<T, Compare, Allocator>   *_contents;
    allocator_type  _allocator;
    key_compare     _compare;
};

/*=============================================
===          NON-MEMBER FUNCTIONS           ===
=============================================*/
/*********************************************/
/*           OPERATOR OVERLOADS              */
/*********************************************/
template <class T, class Compare, class Allocator>
bool operator==(const map<T, Compare, Allocator>& lhs, const map<T, Compare, Allocator>& rhs);
template <class T, class Compare, class Allocator>
bool operator!=(const map<T, Compare, Allocator>& lhs, const map<T, Compare, Allocator>& rhs);
template <class T, class Compare, class Allocator>
bool operator<(const map<T, Compare, Allocator>& lhs, const map<T, Compare, Allocator>& rhs);
template <class T, class Compare, class Allocator>
bool operator<=(const map<T, Compare, Allocator>& lhs, const map<T, Compare, Allocator>& rhs);
template <class T, class Compare, class Allocator>
bool operator>(const map<T, Compare, Allocator>& lhs, const map<T, Compare, Allocator>& rhs);
template <class T, class Compare, class Allocator>
bool operator>=(const map<T, Compare, Allocator>& lhs, const map<T, Compare, Allocator>& rhs);

/*********************************************/
/*                  OTHER                    */
/*********************************************/
// template <class Key, class Compare, class Allocator>
// void swap(ft::map<Key, Compare, Allocator>& lhs, ft::map<Key, Compare, Allocator>& rhs );
template <class T, class Compare, class Allocator>
void swap(ft::map<T, Compare, Allocator>& lhs, ft::map<T, Compare, Allocator>& rhs );

};  // namespace ft

#include "ft_map.tpp"

#endif
