#include "vector_tests.hpp"

void test_vector_assignment_operator(void) {
    {
        std::cout << "\n=== Assignment Operator ===" << std::endl;

        ft::vector<double> testVector(42);
        ft::vector<double> assignedVector = testVector;

        my_assert(assignedVector.size() == testVector.size(), "Size check");
        my_assert(assignedVector.capacity() == testVector.capacity(), "Capacity check");

        bool elementsTest = true;
        for (unsigned int i = 0; i < assignedVector.size(); i++) {
            if (assignedVector[i] != testVector[i]) {
                elementsTest = false;
                break;
            }
        }
        my_assert(elementsTest, "Assigned elements assertion check");

        testVector[0] = 42.0;
        assignedVector[1] = 1.0;

        my_assert(testVector[0] != assignedVector[0] && testVector[1] != assignedVector[1], "Test for hard copy");
    }
    {
        ft::vector<double> testVector(42);
        ft::vector<double> assignedVector(21);
        
        assignedVector = testVector;
        my_assert(assignedVector.size() == testVector.size(), "Source vector greater than destination vector: Size check");
        my_assert(assignedVector.capacity() == testVector.capacity(), "Source vector greater than destination vector: Capacity check");

        bool elementsTest = true;
        for (unsigned int i = 0; i < assignedVector.size(); i++) {
            if (assignedVector[i] != testVector[i]) {
                elementsTest = false;
                break;
            }
        }
        my_assert(elementsTest, "Source vector greater than destination vector: Assigned elements assertion check");
    }
    {
        ft::vector<double> testVector(21);
        ft::vector<double> assignedVector(42);
        
        assignedVector = testVector;
        my_assert(assignedVector.size() == testVector.size(), "Source vector smaller than destination vector: Size check");
        my_assert(assignedVector.capacity() == testVector.capacity(), "Source vector smaller than destination vector: Capacity check");

        bool elementsTest = true;
        for (unsigned int i = 0; i < assignedVector.size(); i++) {
            if (assignedVector[i] != testVector[i]) {
                elementsTest = false;
                break;
            }
        }
        my_assert(elementsTest, "Source vector smaller than destination vector: Assigned elements assertion check");
    }



    return;
}