#ifndef TEST_FUNCTIONS_PROTOTYPES_HPP
#define TEST_FUNCTIONS_PROTOTYPES_HPP

#include <vector>

#include "ft_containers.hpp"
#include "tests_props.hpp"

// Assertion function
void    assert(bool condition, const std::string& tagline = "");

void    test_access(void);
void    test_allocator(void);
void    test_assign(void);
void    test_assignment_operator(void);
void    test_back(void);
void    test_cleanup(void);
void    test_data(void);
void    test_emptiness(void);
void    test_erase(void);
void    test_front(void);
void    test_iterators(void);
void    test_insertion(void);
void    test_max_size(void);
void    test_operator_overloads(void);
void    test_pop_back(void);
void    test_push_back(void);
void    test_reserve(void);
void    test_resize(void);
void    test_size_and_capacity(void);
void    test_swap(void);
void    test_typedefs(void);
void    test_vector_construction(void);

#endif