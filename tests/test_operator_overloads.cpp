#include "test_functions_header.hpp"

void test_operator_equal_to(void) {
    std::cout << "  operator==:" << std::endl;
    {
        ft::vector<double> a;
        ft::vector<double> b;

        assert((a == b) == true, "Comparing empty vectors");
    }
    ft::vector<double> a(42, 42.0);
    ft::vector<double> b(42, 42.0);

    assert((a == b) == true, "Equal vectors comparison");

    b.at(41) = 42.1;

    assert((a == b) == false, "Same size and capacity, different contents vectors comparison");

    b.at(41) = 42.0;
    b.resize(40);

    assert((a == b) == false, "Same capacity and contents, different size vectors comparison");

    b.push_back(42.0);
    b.push_back(42.0);
    b.push_back(42.0);  // here capacity should double to 84

    b.clear();  // here size goes to 0, capacity stays the same
    b.assign(42, 42.0);  // here vector goes back to having 42 42.0s

    assert((a == b) == true, "Same size and contents, different capacity vectors comparison");

    b.clear();

    assert((a == b) == false, "Totally different vectors comparison");
};

void test_operator_not_equal_to(void) {
    std::cout << "\n  operator!=:" << std::endl;
    {
        ft::vector<double> a;
        ft::vector<double> b;

        assert((a != b) == false, "Comparing empty vectors");
    }
    ft::vector<double> a(42, 42.0);
    ft::vector<double> b(42, 42.0);

    assert((a != b) == false, "Equal vectors comparison");

    b.at(41) = 42.1;

    assert((a != b) == true, "Same size and capacity, different contents vectors comparison");

    b.at(41) = 42.0;
    b.resize(40);

    assert((a != b) == true, "Same capacity and contents, different size vectors comparison");

    b.push_back(42.0);
    b.push_back(42.0);
    b.push_back(42.0);  // here capacity should double to 84

    b.clear();  // here size goes to 0, capacity stays the same
    b.assign(42, 42.0);  // here vector goes back to having 42 42.0s

    assert((a != b) == false, "Same size and contents, different capacity vectors comparison");

    b.clear();
    assert((a != b) == true, "Totally different vectors comparison");
};

void test_operator_overloads(void) {
    std::cout << "\n=== Test operator overloads ===" << std::endl;
    test_operator_equal_to();
    test_operator_not_equal_to();

}
