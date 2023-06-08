#ifndef FT_MAP_TPP
#define FT_MAP_TPP

#include "BinaryTree.hpp"

namespace ft {

/*==============================================================================
===  MEMBER FUNCTIONS                                                        ===
==============================================================================*/

// Capacity:
template <typename T, typename Compare, typename Allocator>
bool map<T, Compare, Allocator>::empty() const {
    if (this->size() == 0)
        return (true);
    return (false);
};

template <typename T, typename Compare, typename Allocator>
 typename map<T, Compare, Allocator>::size_type map<T, Compare, Allocator>::size() const {
    return (_contents->getSize());
};

// Modifiers:
template <typename T, typename Compare, typename Allocator>
bool map<T, Compare, Allocator>::insert(const value_type& value) {
    _contents->insert(value);
    return (true);
};

/*==============================================================================
===  CONSTRUCTION / DESTRUCTION                                              ===
==============================================================================*/
template <typename T, typename Compare, typename Allocator>
map<T, Compare, Allocator>::map(const key_compare& comp, const allocator_type& alloc) {
    _contents = new BinaryTree<T>;
    (void) comp;
    (void) alloc;
};

template <typename T, typename Compare, typename Allocator>
map<T, Compare, Allocator>::~map() {
    delete _contents;
};

/*==============================================================================
===  OPERATOR OVERLOADS                                                      ===
==============================================================================*/

/*==============================================================================
===  PRIVATE FUNCTIONS                                                       ===
==============================================================================*/

/*=============================================================================
===  NON-MEMBER FUNCTIONS                                                   ===
=============================================================================*/
/*****************************************************************************/
/*   OPERATOR OVERLOADS                                                      */
/*****************************************************************************/

/*********************************************/
/*                  OTHER                    */
/*********************************************/

}  // namespace ft

#endif