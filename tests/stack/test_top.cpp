#include "stack_tests.hpp"

static bool test_by_reference(const ft::stack<double> &ftStack, double expectedValue) {
    return (ftStack.top() == expectedValue);
}

void test_stack_top(void) {
    std::cout << "\n=== Top operation ===" << std::endl;

    ft::stack<double> ftStack;
    double dish;

    dish = 42;
    ftStack.push(dish);

    my_assert(ftStack.top() == dish, "Testing top after single insertion");
    my_assert(test_by_reference(ftStack, dish), "Testing top after single insertion, by reference");

    dish = 43;
    ftStack.push(dish);

    my_assert(ftStack.top() == dish, "Testing top after second insertion");
    my_assert(test_by_reference(ftStack, dish), "Testing top after second insertion, by reference");

    bool integrityCheck = true;
    bool integrityCheckByRef = true;

    for (int i = 0; i < 200; i++) {
        dish = 44 + i;
        ftStack.push(dish);
        integrityCheck = integrityCheck && (ftStack.top() == dish);
        integrityCheckByRef = integrityCheckByRef && (test_by_reference(ftStack, dish));
    }

    my_assert(integrityCheck, "Testing top after many insertions");
    my_assert(integrityCheckByRef, "Testing top after many insertions, by reference");

    ftStack.pop();

    my_assert(ftStack.top() == 242, "Testing top after single pop");
    my_assert(test_by_reference(ftStack, 242), "Testing top after single pop, by reference");

    ftStack.pop();

    my_assert(ftStack.top() == 241, "Testing top after second pop");
    my_assert(test_by_reference(ftStack, 241), "Testing top after second pop, by reference");

    integrityCheck = true;
    integrityCheckByRef = true;

    for (int i = 1; i < 200; i++) {
        ftStack.pop();
        integrityCheck = integrityCheck && (ftStack.top() == 241 - i);
        integrityCheckByRef = integrityCheckByRef && test_by_reference(ftStack, 241 - i);
    }

    my_assert(integrityCheck, "Testing top after many pops");
    my_assert(integrityCheckByRef, "Testing top after many pops, by reference");

}
