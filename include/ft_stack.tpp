#ifndef FT_STACK_TPP
#define FT_STACK_TPP

namespace ft {

/*==============================================================================
===  MEMBER FUNCTIONS                                                        ===
==============================================================================*/

/*==============================================================================
===  CONSTRUCTION / DESTRUCTION                                              ===
==============================================================================*/

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