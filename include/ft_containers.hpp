#ifndef FT_CONTAINERS_HPP
#define FT_CONTAINERS_HPP

#include "ft_stack.hpp"
#include "ft_vector.hpp"

namespace ft {

// === std::iterator_traits ================================================
template< class Iter >
struct iterator_traits;

template< class T >
struct iterator_traits<T*>;

// === std::reverse_iterator ===============================================
template< class Iter >
class reverse_iterator;

// === std::enable_if ======================================================
template< bool B, class T = void >
struct enable_if;

// === std::is_integral ====================================================
class is_integral;

// === std::equal ==========================================================
// TODO: confirnar se são essas duas só
template <class InputIt1, class InputIt2>
bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2);

template <class InputIt1, class InputIt2, class BinaryPredicate>
bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2,
           BinaryPredicate p);

// === std::lexicographical_compare ========================================
template <class InputIt1, class InputIt2>
bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
                             InputIt2 first2, InputIt2 last2);

template <class InputIt1, class InputIt2, class Compare>
bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
                             InputIt2 first2, InputIt2 last2, Compare comp);

// === std::pair ===========================================================
template <
    class T1,
    class T2>
struct pair;

// === std::pair ===========================================================
template <class T1, class T2>
ft::pair<T1, T2> make_pair(T1 t, T2 u);

}  // namespace ft

#endif