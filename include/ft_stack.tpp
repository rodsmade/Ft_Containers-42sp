#ifndef FT_STACK_TPP
#define FT_STACK_TPP

namespace ft {

/*==============================================================================
===  MEMBER FUNCTIONS                                                        ===
==============================================================================*/
// Element access:
template <typename T, typename Container>
typename stack<T, Container>::reference stack<T, Container>::top() {
    return (_container.front());
};

template <typename T, typename Container>
typename stack<T, Container>::const_reference stack<T, Container>::top() const {
    return (_container.front());
};

// Capacity:
template <typename T, typename Container>
typename stack<T, Container>::size_type stack<T, Container>::size() const {
    return _container.size();
};

template <typename T, typename Container>
bool stack<T, Container>::empty() const {
    return _container.empty();
};

// Modifiers:
template <typename T, typename Container>
void stack<T, Container>::push(const value_type& value) {
    _container.push_front(value);
    return;
};

template <typename T, typename Container>
void stack<T, Container>::pop(void) {
    _container.pop_front();
    return;
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