#include "test_functions_header.hpp"
#include "stack_tests.hpp"

int main() {
    test_stack_construction();
    test_stack_assignment_operator();
    test_stack_push_and_pop();
    test_stack_top();
    test_stack_operator_overloads();
    return (0);
}