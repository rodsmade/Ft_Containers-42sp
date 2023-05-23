#include "stack_tests.hpp"

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

static void test_copy_constructor() {
    std::cout << "\n  Copy Constructor\t==>\tstack(const stack& other):" << std::endl;
    {
        ft::stack<double> ftStack;

        // create stack
        for (int i = 0; i < 10; i++)
            ftStack.push(42 + i);

        ft::stack<double> copyStack(ftStack);

        bool consistencyCheck = true;

        for (int i = 0; i < 10; i++) {
            consistencyCheck = consistencyCheck && (ftStack.top() == copyStack.top());
            ftStack.pop();
            copyStack.pop();
        }

        assert(copyStack.size() == ftStack.size(), "Copy constructor size check");
        assert(consistencyCheck, "Copied elements integrity check");
    }
    {
        ft::stack<double> ftStack;

        // create stack
        for (int i = 0; i < 10; i++)
            ftStack.push(42 + i);

        ft::stack<double> copyStack(ftStack);

        ftStack.pop();
        ftStack.pop();
        ftStack.pop();
        ftStack.pop();
        ftStack.pop();

        assert(ftStack.size() != copyStack.size()
                && ftStack.top() != copyStack.top()
                , "Check for hard copy");

    }
};

static void test_default_constructor(void) {
    std::cout << "  Default Constructor\t==>\tstack<T, Container>(void):" << std::endl;
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
    std::cout << "\n=== Stack construction ===" << std::endl;

    test_default_constructor();
    test_copy_constructor();
    return ;
}
