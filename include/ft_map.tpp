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
typename map<T, Compare, Allocator>::size_type map<T, Compare, Allocator>::max_size() const {
    return (_allocator.max_size());
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
    _allocator = alloc;
    _compare = comp;
    _contents = new BinaryTree<T>;
};

template <typename T, typename Compare, typename Allocator>
map<T, Compare, Allocator>::map(const map& other) {
    _allocator = other._allocator;
    _compare = other._compare;
    _contents = new BinaryTree<T, Compare, Allocator>;
    *_contents = BinaryTree<T, Compare, Allocator>(*other._contents);
}

template <typename T, typename Compare, typename Allocator>
map<T, Compare, Allocator>::~map() {
    delete _contents;
};

/*==============================================================================
===  OPERATOR OVERLOADS                                                      ===
==============================================================================*/
// template <typename T, typename Compare, typename Allocator>
// map<T, Compare, Allocator> &map<T, Compare, Allocator>::operator=(const map& other) {
//     if (*this != other) {
//         _allocator = other._allocator;
//         _compare = other._compare;
//         delete _contents;
//         _contents = new BinaryTree<T, Compare, Allocator>(other._contents);
//     }
//     return (*this);
// };

/*==============================================================================
===  PRIVATE FUNCTIONS                                                       ===
==============================================================================*/

/*==============================================================================
===  NON-MEMBER FUNCTIONS                                                    ===
==============================================================================*/
/******************************************************************************/
/*   OPERATOR OVERLOADS                                                       */
/******************************************************************************/

/******************************************************************************/
/*                  OTHER                                                     */
/******************************************************************************/

}  // namespace ft

#endif