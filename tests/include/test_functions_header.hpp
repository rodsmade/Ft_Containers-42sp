#ifndef TEST_FUNCTIONS_PROTOTYPES_HPP
#define TEST_FUNCTIONS_PROTOTYPES_HPP

#include <vector>

#include "ft_containers.hpp"
#include "tests_props.hpp"

// Assertion function
void    assert(bool condition, const std::string& tagline = "");

void    test_cleanup(void);
void    test_emptiness(void);
void    test_typedefs(void);
void    test_vector_construction(void);
void    test_assignment_operator(void);
void    test_max_size(void);
void    test_resize(void);
void    test_reserve(void);
void    test_size_and_capacity(void);

#endif