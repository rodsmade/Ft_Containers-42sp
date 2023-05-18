#ifndef TEST_FUNCTIONS_PROTOTYPES_HPP
#define TEST_FUNCTIONS_PROTOTYPES_HPP

#include <vector>

#include "ft_containers.hpp"
#include "tests_props.hpp"

// Assertion function
void    assert(bool condition, const std::string& tagline = "");

// Vector tests
void    test_vector_access(void);
void    test_vector_allocator(void);
void    test_vector_assign(void);
void    test_vector_assignment_operator(void);
void    test_vector_back(void);
void    test_vector_cleanup(void);
void    test_vector_construction(void);
void    test_vector_data(void);
void    test_vector_emptiness(void);
void    test_vector_erase(void);
void    test_vector_front(void);
void    test_vector_iterators(void);
void    test_vector_insertion(void);
void    test_vector_max_size(void);
void    test_vector_operator_overloads(void);
void    test_vector_pop_back(void);
void    test_vector_push_back(void);
void    test_vector_reserve(void);
void    test_vector_resize(void);
void    test_vector_size_and_capacity(void);
void    test_vector_swap(void);
void    test_vector_typedefs(void);

#endif