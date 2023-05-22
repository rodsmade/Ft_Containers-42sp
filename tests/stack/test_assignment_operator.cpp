#include "stack_tests.hpp"

void test_stack_assignment_operator(void) {
    std::cout << "\n=== Assignment Operator ===" << std::endl;
    {
        ft::stack<double> testStack;

        for (int i = 1; i <= 42; i++)
            testStack.push(i);

        ft::stack<double> assignedStack = testStack;

        assert(assignedStack.size() == testStack.size()
                && assignedStack.top() == testStack.top()
                , "Size check");

        bool consistencyCheck = true;
        ft::stack<double>::size_type loopControl = assignedStack.size();
        for (unsigned int i = 0; i < loopControl; i++) {
            consistencyCheck = consistencyCheck && (testStack.top() == assignedStack.top());
            testStack.pop();
            assignedStack.pop();
        }

        assert(consistencyCheck, "Assigned elements assertion check");
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

        assert(testStack.size() != assignedStack.size()
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

        assert(assignedStack.size() == testStack.size()
                && assignedStack.top() == testStack.top()
                , "Size check for assignedStack previously smaller than testStack");

        bool consistencyCheck = true;
        ft::stack<double>::size_type loopControl = assignedStack.size();
        for (unsigned int i = 0; i < loopControl; i++) {
            consistencyCheck = consistencyCheck && (testStack.top() == assignedStack.top());
            testStack.pop();
            assignedStack.pop();
        }

        assert(consistencyCheck, "Assigned elements integrity check for assignedStack previously smaller than testStack");
    }
    {
        ft::stack<double> testStack;
        ft::stack<double> assignedStack;

        for (int i = 1; i <= 42; i++)
            testStack.push(i);

        for (int i = 1; i <= 420; i++)
            assignedStack.push(i);

        assignedStack = testStack;

        assert(assignedStack.size() == testStack.size()
                && assignedStack.top() == testStack.top()
                , "Size check for assignedStack previously greater than testStack");

        bool consistencyCheck = true;
        ft::stack<double>::size_type loopControl = assignedStack.size();
        for (unsigned int i = 0; i < loopControl; i++) {
            consistencyCheck = consistencyCheck && (testStack.top() == assignedStack.top());
            testStack.pop();
            assignedStack.pop();
        }

        assert(consistencyCheck, "Assigned elements integrity check for assignedStack previously greater than testStack");
    }
    // {
    //     ft::stack<double> testStack(42);
    //     ft::stack<double> assignedStack(21);
        
    //     assignedStack = testStack;
    //     assert(assignedStack.size() == testStack.size(), "Source stack greater than destination stack: Size check");
    //     assert(assignedStack.capacity() == testStack.capacity(), "Source stack greater than destination stack: Capacity check");

    //     bool consistencyCheck = true;
    //     for (unsigned int i = 0; i < assignedStack.size(); i++) {
    //         if (assignedStack[i] != testStack[i]) {
    //             consistencyCheck = false;
    //             break;
    //         }
    //     }
    //     assert(consistencyCheck, "Source stack greater than destination stack: Assigned elements assertion check");
    // }
    // {
    //     ft::stack<double> testStack(21);
    //     ft::stack<double> assignedStack(42);
        
    //     assignedStack = testStack;
    //     assert(assignedStack.size() == testStack.size(), "Source stack smaller than destination stack: Size check");
    //     assert(assignedStack.capacity() == testStack.capacity(), "Source stack smaller than destination stack: Capacity check");

    //     bool consistencyCheck = true;
    //     for (unsigned int i = 0; i < assignedStack.size(); i++) {
    //         if (assignedStack[i] != testStack[i]) {
    //             consistencyCheck = false;
    //             break;
    //         }
    //     }
    //     assert(consistencyCheck, "Source stack smaller than destination stack: Assigned elements assertion check");
    // }

    return;
}