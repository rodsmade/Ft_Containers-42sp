#include "stack_tests.hpp"

void test_push_and_pop(void) {
    std::cout << "\n=== Push and pop operations ===" << std::endl;

    ft::stack<double> ftStack;

    ft::stack<double>::size_type expectedSize = 1;
    ftStack.push(42);

    assert(ftStack.empty() == false, "Testing single push operation");
    assert(ftStack.size() == expectedSize, "Testing size after single push operation");

    for (int i = 1; i <= 100; i++) {
        ftStack.push(42 + i);
        expectedSize++;
    }

    assert(ftStack.size() == expectedSize, "Testing size after many pushes");

    ftStack.pop();
    expectedSize--;

    assert(ftStack.empty() == false, "Testing single pop operation");
    assert(ftStack.size() == expectedSize, "Testing size after single pop operation");

    for (int i = 1; i <= 100; i++) {
        ftStack.pop();
        expectedSize--;
    }

    assert(ftStack.size() == expectedSize && ftStack.empty() == true, "Testing size after many pops");
}
