#ifndef TEST_FUNCTIONS_PROTOTYPES_HPP
#define TEST_FUNCTIONS_PROTOTYPES_HPP

#include <vector>

#include "ft_containers.hpp"
#include "tests_structures.hpp"

// Assertion function
void    assert(bool condition, const std::string& tagline = "");

void    test_cleanup(void);
void    test_emptiness(void);
void    test_typedefs(void);
void    test_vector_construction(void);

#endif