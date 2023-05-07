#include "test_functions_header.hpp"

int main() {
    test_typedefs();
    test_vector_construction();
    test_max_size();
    test_size_and_capacity();
    test_resize();
    test_reserve();
    test_assignment_operator();
    test_cleanup();
    test_emptiness();
    test_push_back();
    test_access();
    test_pop_back();
    test_back();
    test_front();
    test_data();
    test_swap();
    test_assign();
    test_allocator();
    test_operator_overloads();
    test_iterators();
    test_erase();
    test_insertion();
    return 0;
}