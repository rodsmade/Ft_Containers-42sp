#include "test_functions_header.hpp"
#include "vector_tests.hpp"

int main() {
    test_vector_typedefs();
    test_vector_construction();
    test_vector_max_size();
    test_vector_size_and_capacity();
    test_vector_resize();
    test_vector_reserve();
    test_vector_assignment_operator();
    test_vector_cleanup();
    test_vector_emptiness();
    test_vector_push_back();
    test_vector_access();
    test_vector_pop_back();
    test_vector_back();
    test_vector_front();
    test_vector_data();
    test_vector_swap();
    test_vector_assign();
    test_vector_allocator();
    test_vector_operator_overloads();
    test_vector_iterators();
    test_vector_erase();
    test_vector_insertion();
    return (0);
}