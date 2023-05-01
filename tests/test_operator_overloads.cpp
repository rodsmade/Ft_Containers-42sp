#include "test_functions_header.hpp"

void test_operator_equal_to(void) {
    std::cout << "  operator==:" << std::endl;
    ft::vector<double> vector1(42, 42.0);
    ft::vector<double> vector2(42, 42.0);

    assert((vector1 == vector2) == true, "Equal vectors comparison");

    vector2.at(41) = 42.1;

    assert((vector1 == vector2) == false, "Same size and capacity, different contents vectors comparison");

    vector2.at(41) = 42.0;
    vector2.resize(40);

    assert((vector1 == vector2) == false, "Same capacity and contents, different size vectors comparison");

    vector2.push_back(42.0);
    vector2.push_back(42.0);
    vector2.push_back(42.0);  // here capacity should double to 84

    vector2.clear();  // here size goes to 0, capacity stays the same
    vector2.assign(42, 42.0);  // here vector goes back to having 42 42.0's

    assert((vector1 == vector2) == false, "Same size and contents, different capacity vectors comparison");

    vector2.clear();

    assert((vector1 == vector2) == false, "Totally different vectors comparison");
};

void test_operator_overloads(void) {
    std::cout << "\n=== Test operator overloads ===" << std::endl;
    test_operator_equal_to();

}
