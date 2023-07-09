#include "stack_tests.hpp"

void test_stack_assignment_operator(void) {
    std::cout << "\n=== Assignment Operator ===" << std::endl;
    {
        ft::stack<double> testStack;

        for (int i = 1; i <= 42; i++)
            testStack.push(i);

        ft::stack<double> assignedStack = testStack;

        my_assert(assignedStack.size() == testStack.size()
                && assignedStack.top() == testStack.top()
                , "Size check");

        bool consistencyCheck = true;
        ft::stack<double>::size_type loopControl = assignedStack.size();
        for (unsigned int i = 0; i < loopControl; i++) {
            consistencyCheck = consistencyCheck && (testStack.top() == assignedStack.top());
            testStack.pop();
            assignedStack.pop();
        }

        my_assert(consistencyCheck, "Assigned elements assertion check");
    }
    {
        ft::stack<double> testStack;

        for (int i = 1; i <= 42; i++)
            testStack.push(i);

        ft::stack<double> assignedStack = testStack;

        testStack.pop();
        testStack.pop();
        testStack.pop();
        testStack.pop();
        testStack.pop();

        my_assert(testStack.size() != assignedStack.size()
                && testStack.top() != assignedStack.top()
                , "Test for hard copy");
    }
    {
        ft::stack<double> testStack;
        ft::stack<double> assignedStack;

        for (int i = 1; i <= 42; i++)
            testStack.push(i);

        for (int i = 1; i <= 21; i++)
            assignedStack.push(i);

        assignedStack = testStack;

        my_assert(assignedStack.size() == testStack.size()
                && assignedStack.top() == testStack.top()
                , "Size check for assignedStack previously smaller than testStack");

        bool consistencyCheck = true;
        ft::stack<double>::size_type loopControl = assignedStack.size();
        for (unsigned int i = 0; i < loopControl; i++) {
            consistencyCheck = consistencyCheck && (testStack.top() == assignedStack.top());
            testStack.pop();
            assignedStack.pop();
        }

        my_assert(consistencyCheck, "Assigned elements integrity check for assignedStack previously smaller than testStack");
    }
    {
        ft::stack<double> testStack;
        ft::stack<double> assignedStack;

        for (int i = 1; i <= 42; i++)
            testStack.push(i);

        for (int i = 1; i <= 420; i++)
            assignedStack.push(i);

        assignedStack = testStack;

        my_assert(assignedStack.size() == testStack.size()
                && assignedStack.top() == testStack.top()
                , "Size check for assignedStack previously greater than testStack");

        bool consistencyCheck = true;
        ft::stack<double>::size_type loopControl = assignedStack.size();
        for (unsigned int i = 0; i < loopControl; i++) {
            consistencyCheck = consistencyCheck && (testStack.top() == assignedStack.top());
            testStack.pop();
            assignedStack.pop();
        }

        my_assert(consistencyCheck, "Assigned elements integrity check for assignedStack previously greater than testStack");
    }
    {
        ft::stack<double> testStack;
        for (int i = 0; i < 42; i++)
            testStack.push(1.0 + i);

        ft::stack<double> assignedStack;
        for (int i = 0; i < 21; i++)
            testStack.push(1.0 + i);

        assignedStack = testStack;
        my_assert(assignedStack.size() == testStack.size(), "Source stack greater than destination stack: Size check");

        bool consistencyCheck = true;
        while (!assignedStack.empty()) {
            consistencyCheck = consistencyCheck && (assignedStack.top() == testStack.top());
            assignedStack.pop();
            testStack.pop();
        }

        my_assert(consistencyCheck, "Source stack greater than destination stack: Assigned elements assertion check");
    }
    {
        ft::stack<double> testStack;
        for (int i = 0; i < 42; i++)
            testStack.push(1.0 + i);

        ft::stack<double> assignedStack;
        for (int i = 0; i < 21; i++)
            testStack.push(1.0 + i);

        assignedStack = testStack;
        my_assert(assignedStack.size() == testStack.size(), "Source stack smaller than destination stack: Size check");

        bool consistencyCheck = true;
        while (!assignedStack.empty()) {
            consistencyCheck = consistencyCheck && (assignedStack.top() == testStack.top());
            assignedStack.pop();
            testStack.pop();
        }

        my_assert(consistencyCheck, "Source stack smaller than destination stack: Assigned elements assertion check");
    }

    return;
}