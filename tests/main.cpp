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
    return 0;
}