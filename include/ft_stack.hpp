#ifndef FT_STACK_HPP
#define FT_STACK_HPP

#include <deque>

namespace ft {

template <typename T, typename Container = std::deque<T> >
class stack {

   protected:
    /*=============================================
    ===           MEMBER OBJECTS                ===
    =============================================*/
    Container _container;

    /*=============================================
    ===          FRIEND FUNCTIONS               ===
    =============================================*/
    template <typename U, typename C>
    friend bool operator==(const stack<U, C>& lhs, const stack<U, C>& rhs);
    template <typename U, typename C>
    friend bool operator!=(const stack<U, C>& lhs, const stack<U, C>& rhs);
    template <typename U, typename C>
    friend bool operator<(const stack<U, C>& lhs, const stack<U, C>& rhs);
    template <typename U, typename C>
    friend bool operator<=(const stack<U, C>& lhs, const stack<U, C>& rhs);
    template <typename U, typename C>
    friend bool operator>(const stack<U, C>& lhs, const stack<U, C>& rhs);
    template <typename U, typename C>
    friend bool operator>=(const stack<U, C>& lhs, const stack<U, C>& rhs);

   public:
    /*=============================================
    ===                ALIASES                  ===
    =============================================*/
    typedef Container container_type;
    typedef typename Container::value_type value_type;
    typedef typename Container::size_type size_type;
    typedef typename Container::reference reference;
    typedef typename Container::const_reference const_reference;

    /*=============================================
    ===            MEMBER FUNCTIONS             ===
    =============================================*/
    // Element Access:
    reference       top();
    const_reference top() const;

    //Capacity:
    bool            empty() const;
    size_type       size() const;

    // Modifiers:
    void            push(const value_type& value);
    void            pop();

    /*=============================================
    ===      CONSTRUCTION / DESTRUCTION         ===
    =============================================*/
    explicit stack(const Container & cont = Container());
    stack(const stack& other);
    ~stack();

    /*=============================================
    ===           OPERATOR OVERLOADS            ===
    =============================================*/
    stack&         operator=(const stack& other);

};

/*=============================================
===          NON-MEMBER FUNCTIONS           ===
=============================================*/
/*********************************************/
/*           OPERATOR OVERLOADS              */
/*********************************************/
template< class T, class Container >
bool    operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs);
template< class T, class Container >
bool    operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs);
template< class T, class Container >
bool    operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs);
template< class T, class Container >
bool    operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs);
template< class T, class Container >
bool    operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs);
template< class T, class Container >
bool    operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs);

};  // namespace ft

#include "ft_stack.tpp"

#endif
