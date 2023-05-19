#include "stack_tests_header.hpp"

template <typename T>
static void test_empty_stack_creation(std::string typeName) {
    try {
        ft::stack<T> ftStack;

        assert(true, "Empty ft::stack<" + typeName + "> creation");
    } catch (const std::exception& e) {
        std::cerr << TEST_NOK << e.what() << std::endl;
    }
}

template <typename T>
static void test_against_std_empty_stack_creation(std::string typeName) {
    try {
        ft::stack<T> ftStack;
        std::stack<T> stdStack;

        assert(ftStack.size() == stdStack.size() && ftStack.empty() == stdStack.empty(), "Empty ft::stack<" + typeName + "> against empty std::stack<" + typeName + "> creation");
    } catch (const std::exception& e) {
        std::cerr << TEST_NOK << e.what() << std::endl;
    }
}

// static void test_copy_constructor() {

    // ATTENTION: não tem como testar copy constructor sem antes implementar os push e pop

//     std::cout << "\n  Copy Constructor ==>\tstack(const stack& other):" << std::endl;

//     ft::stack<double>::size_type intendedSize = 42;
//     ft::stack<double> testStack(intendedSize);
//     ft::stack<double> copyStack(testStack);

//     bool elementsTest = true;

//     assert(copyStack.size() == testStack.size(), "Copy constructor size check");
//     assert(copyStack.capacity() == testStack.capacity(), "Copy constructor capacity check");

//     for (unsigned int i = 0; i < copyStack.size(); i++) {
//         if (copyStack[i] != testStack[i]) {
//             elementsTest = false;
//             break;
//         }
//     }
//     assert(elementsTest, "Copied elements assertion check");

//     testStack[0] = 42.0;
//     copyStack[1] = 1.0;

//     assert(testStack[0] != copyStack[0] && testStack[1] != copyStack[1], "Test for hard copy");
// };

static void test_default_constructor(void) {
    std::cout << "  Default Constructor ==>\tstack<T, Container>(void):" << std::endl;
    test_empty_stack_creation<double>("double");
    test_empty_stack_creation<float>("float");
    test_empty_stack_creation<std::string>("std::string");
    test_empty_stack_creation<ft::stack<double> >("ft::stack<double>");
    test_empty_stack_creation<Has_default>("Has_default");
    test_empty_stack_creation<No_default>("No_default");
    test_against_std_empty_stack_creation<double>("double");
    test_against_std_empty_stack_creation<float>("float");
    test_against_std_empty_stack_creation<std::string>("std::string");
    test_against_std_empty_stack_creation<ft::stack<double> >("ft::stack<double>");
    test_against_std_empty_stack_creation<Has_default>("Has_default");
    test_against_std_empty_stack_creation<No_default>("No_default");
}

void test_stack_construction(void) {
    test_default_constructor();
    return ;
}
