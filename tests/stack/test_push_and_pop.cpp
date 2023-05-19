#include "stack_tests.hpp"

static void basic_test() {
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

// static void tests_against_std() {
//     ft::stack<double> ftStack;
//     std::stack<double> stdStack;

//     ftStack.pop();
//     stdStack.pop();
//     ftStack.pop();
//     stdStack.pop();
//     ftStack.pop();
//     stdStack.pop();
//     ftStack.pop();
//     stdStack.pop();
//     ftStack.pop();
//     stdStack.pop();
//     ftStack.pop();
//     stdStack.pop();
//     ftStack.pop();
//     stdStack.pop();
//     ftStack.pop();
//     stdStack.pop();
//     ftStack.pop();
//     stdStack.pop();
//     ftStack.pop();
//     stdStack.pop();

//     assert(ftStack.size() == stdStack.size() && ftStack.empty() == stdStack.empty(), "Testing size after many pops on empty stack against std stack");
// }

void test_push_and_pop(void) {
    std::cout << "\n=== Push and pop operations ===" << std::endl;
    basic_test();
    // tests_against_std();

}
