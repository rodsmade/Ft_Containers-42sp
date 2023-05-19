#ifndef FT_STACK_TPP
#define FT_STACK_TPP

namespace ft {

/*==============================================================================
===  MEMBER FUNCTIONS                                                        ===
==============================================================================*/
// Element access:
// Capacity:
template <typename T, typename Container>
typename stack<T, Container>::size_type stack<T, Container>::size() const {
    return _container.size();
};

template <typename T, typename Container>
bool stack<T, Container>::empty() const {
    return _container.empty();
};

/*==============================================================================
===  CONSTRUCTION / DESTRUCTION                                              ===
==============================================================================*/
template <typename T, typename Container>
stack<T, Container>::stack(const Container & container) : _container(container) {};

template <typename T, typename Container>
stack<T, Container>::stack(const stack& other) : _container(other._container) {};

template <typename T, typename Container>
stack<T, Container>::~stack(void) {};

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
template< class T, class Container >
bool operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
    // TODO
    // for (typename stack<T, Container>::size_type i = 0; i < lhs.size(); i++) {
    //     if (i == rhs.size())
    //         break ;
    //     if (lhs.at(i) != rhs.at(i))
    //         return (false);
    // }

    return (lhs.size() == rhs.size());
};

template< class T, class Container >
bool operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs){
    return (!(lhs == rhs));
};

template< class T, class Container >
bool operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
    // TODO:
    // for (typename stack<T, Container>::size_type i = 0; i < lhs.size(); i++) {
    //     if (i == rhs.size())
    //         break ;
    //     if (lhs.at(i) < rhs.at(i))
    //         return (true);
    //     else if (lhs.at(i) > rhs.at(i))
    //         return (false);
    // }

    return (lhs.size() < rhs.size());
};

template< class T, class Container >
bool operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
    // TODO:
    // for (typename stack<T, Container>::size_type i = 0; i < lhs.size(); i++) {
    //     if (i == rhs.size())
    //         break ;
    //     if (lhs.at(i) < rhs.at(i))
    //         return (true);
    //     else if (lhs.at(i) > rhs.at(i))
    //         return (false);
    // }

    return (lhs.size() <= rhs.size());
};

template< class T, class Container >
bool operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
    return (!(lhs <= rhs));
};

template< class T, class Container >
bool operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
    return (!(lhs < rhs));
};

}  // namespace ft

#endif