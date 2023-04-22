#include "test_functions_header.hpp"

void test_assignment_operator(void) {
    std::cout << "\n=== Assignment Operator ===" << std::endl;

    ft::vector<double> testVector(42);
    ft::vector<double> assignedVector = testVector;


    assert(assignedVector.size() == testVector.size(), "Size check");
    assert(assignedVector.capacity() == testVector.capacity(), "Capacity check");

    bool elementsTest = true;
    for (unsigned int i = 0; i < assignedVector.size(); i++) {
        if (assignedVector[i] != testVector[i]) {
            elementsTest = false;
            break;
        }
    }
    assert(elementsTest, "Assigned elements assertion check");

    testVector[0] = 42.0;
    assignedVector[1] = 1.0;

    assert(testVector[0] != assignedVector[0] && testVector[1] != assignedVector[1], "Test for hard copy");

    try
    {
        assignedVector = assignedVector;
        assert(true, "Self-assignment");
    }
    catch(const std::exception& e)
    {
        assert(false, "Self-assignment");
    }
    

    // TODO: testes de assignment com vetor fonte maior, menor e igual que vetor destino.

    return;
}