#include "stack_tests.hpp"

static void test_operator_equal_to(void) {
    std::cout << "  operator==:" << std::endl;
    ft::stack<double> a;
    ft::stack<double> b;

    assert((a == b) == true, "Comparing empty stacks");
    
    for (int i = 1; i <= 42; i++) {
        a.push(i);
        b.push(i);
    }

    assert((a == b) == true, "Equal stacks comparison");

    b.pop();
    b.push(0);

    assert((a == b) == false, "Same size, different contents stacks comparison");

    b.pop();    // b now has 41 elements, all of them are the same as the first 41 elements of a

    assert((a == b) == false, "Same contents, different size stacks comparison");

    for (int i = 1; i <= 42; i++) 
        a.pop();

    assert((a == b) == false, "Totally different stacks comparison");
};

static void test_operator_not_equal_to(void) {
    std::cout << "  operator!=:" << std::endl;
    ft::stack<double> a;
    ft::stack<double> b;

    assert((a != b) == false, "Comparing empty stacks");

    for (int i = 1; i <= 42; i++) {
        a.push(i);
        b.push(i);
    }

    assert((a != b) == false, "Equal stacks comparison");

    b.pop();
    b.push(0);

    assert((a != b) == true, "Same size, different contents stacks comparison");

    b.pop();    // b now has 41 elements, all of them are the same as the first 41 elements of a

    assert((a != b) == true, "Same contents, different size stacks comparison");

    for (int i = 1; i <= 42; i++) 
        a.pop();

    assert((a != b) == true, "Totally different stacks comparison");
};

static void test_operator_less_than(void) {
    std::cout << "\n  operator<:" << std::endl;

    ft::stack<double> a;
    ft::stack<double> b;

    assert((a < b) == false, "Comparing empty stacks");

    for (int i = 1; i <= 42; i++) {
        a.push(i);
        b.push(i);
    }

    assert((a < b) == false, "Equal stacks comparison");

    a.pop();
    a.push(0);
    assert((a < b) == true, "Same size, one element in a is smaller than b");

    a.pop();
    assert((a < b) == true, "A is smaller in size than b");
    assert((b < a) == false, "B is not smaller in size than a");
};

// static void test_operator_less_than_or_equal_to(void) {
//     std::cout << "\n  operator<=:" << std::endl;
//     {
//         ft::stack<double> a;
//         ft::stack<double> b;

//         assert((a <= b) == true, "Comparing empty stacks");
//     }
//     ft::stack<double> a(42, 42.0);
//     ft::stack<double> b(42, 42.0);

//     assert((a <= b) == true, "Equal stacks comparison");

//     a.at(41) = 41;
//     assert((a <= b) == true, "Same size, one element in a is smaller than b");

//     a.resize(41);
//     assert((a <= b) == true, "A is smaller in size than b");
//     assert((b <= a) == false, "B is not smaller in size than a");
// }

// static void test_operator_greater_than(void) {
//     std::cout << "\n  operator>:" << std::endl;
//     {
//         ft::stack<double> a;
//         ft::stack<double> b;

//         assert((a > b) == false, "Comparing empty stacks");
//     }
//     ft::stack<double> a(42, 42.0);other
//     ft::stack<double> b(42, 42.0);

//     assert((a > b) == false, "Equal stacks comparison");

//     a.at(41) = 41;
//     assert((a > b) == false, "Same size, one element in a is smaller than b");

//     a.resize(41);
//     assert((a > b) == false, "A is smaller in size than b");
//     assert((b > a) == true, "B is not smaller in size than a");
// };

// static void test_operator_greater_than_or_equal_to(void) {
//     std::cout << "\n  operator>=:" << std::endl;
//     {
//         ft::stack<double> a;
//         ft::stack<double> b;

//         assert((a >= b) == true, "Comparing empty stacks");
//     }
//     ft::stack<double> a(42, 42.0);
//     ft::stack<double> b(42, 42.0);

//     assert((a >= b) == true, "Equal stacks comparison");

//     a.at(41) = 41;
//     assert((a >= b) == false, "Same size, one element in a is smaller than b");

//     a.resize(41);
//     assert((a >= b) == false, "A is smaller in size than b");
//     assert((b >= a) == true, "B is not smaller in size than a");
// };

void test_stack_operator_overloads(void) {
    std::cout << "\n=== Test operator overloads ===" << std::endl;
    test_operator_equal_to();
    test_operator_not_equal_to();
    test_operator_less_than();
    // test_operator_less_than_or_equal_to();
    // test_operator_greater_than();
    // test_operator_greater_than_or_equal_to();
}
