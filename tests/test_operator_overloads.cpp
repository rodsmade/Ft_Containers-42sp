#include "test_functions_header.hpp"

void test_operator_overloads(void) {
    std::cout << "\n=== Test operator overloads ===" << std::endl;

    std::cout << "\n  operator==:" << std::endl;
    ft::vector<double> vector1(42, 42.0);
    ft::vector<double> vector2(42, 42.0);

    assert(vector1 == vector2, "Vector comparison");
}
