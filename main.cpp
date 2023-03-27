#include "ft_containers.hpp"

void test_vector_creation() {
    unsigned int intendedSize = 42;
    ft::Vector testVector(intendedSize);

    {  // Testing Size on Creation
        std::cout << "Size on creation: ";
        if (testVector.size() == intendedSize)
            std::cout << BOLD LIGHT_GREEN "OK" RESET;
        else
            std::cout << BOLD LIGHT_RED "NOK" RESET;
        std::cout << std::endl;
    }
    {  // Testing Initialisation of values
        std::cout << "Initialisation values: ";
        for (unsigned int i = 0; i < testVector.size(); i++) {
            if (testVector.get(i) != 0)
                std::cout << BOLD LIGHT_RED "NOK" RESET;
        }
        std::cout << BOLD LIGHT_GREEN "OK" RESET;
        std::cout << std::endl;
    }
    {  // Testing Valid set() operation at valid index
        std::cout << "Setting value at valid index: ";

        double designatedValue = 42.0;
        unsigned int designatedIndex = 12;

        testVector.set(designatedIndex, designatedValue);
        if (testVector.get(designatedIndex) == designatedValue)
            std::cout << BOLD LIGHT_GREEN "OK" RESET;
        else
            std::cout << BOLD LIGHT_RED "NOK" RESET;
        std::cout << std::endl;
    }
    {  // Testing copy construction
        ft::Vector copyVector(testVector);

        std::cout << "Copy-construction: ";
        bool sizeTest = true;
        bool elementsTest = true;

        sizeTest = (copyVector.size() == testVector.size());

        for (unsigned int i = 0; i < copyVector.size(); i++) {
            if (copyVector.get(i) != testVector.get(i)) {
                elementsTest = false;
                break;
            }
        }

        if (sizeTest && elementsTest)
            std::cout << BOLD LIGHT_GREEN "OK" RESET;
        else
            std::cout << BOLD LIGHT_RED "NOK" RESET;
        std::cout << std::endl;

        std::cout << "Test for hard copy: ";

        double originalValueInTestVector = testVector.get(41);
        double originalValueInCopyVector = copyVector.get(0);

        testVector.set(0, 42.0);
        copyVector.set(41, 1.0);

        if (testVector.get(41) == originalValueInTestVector && copyVector.get(0) == originalValueInCopyVector)
            std::cout << BOLD LIGHT_GREEN "OK" RESET;
        else
            std::cout << BOLD LIGHT_RED "NOK" RESET;
        std::cout << std::endl;
    }
    {  // Testing assignment operator (operator=)
        ft::Vector assignedVector = testVector;

        std::cout << "Basic assignment: ";
        bool sizeTest = true;
        bool elementsTest = true;

        sizeTest = (assignedVector.size() == testVector.size());

        for (unsigned int i = 0; i < assignedVector.size(); i++) {
            if (assignedVector.get(i) != testVector.get(i)) {
                elementsTest = false;
                break;
            }
        }

        if (sizeTest && elementsTest)
            std::cout << BOLD LIGHT_GREEN "OK" RESET;
        else
            std::cout << BOLD LIGHT_RED "NOK" RESET;
        std::cout << std::endl;

        std::cout << "Test for hard copy: ";

        double originalValueInTestVector = testVector.get(41);
        double originalValueInAssignedVector = assignedVector.get(0);

        testVector.set(0, 42.0);
        assignedVector.set(41, 1.0);

        if (testVector.get(41) == originalValueInTestVector && assignedVector.get(0) == originalValueInAssignedVector)
            std::cout << BOLD LIGHT_GREEN "OK" RESET;
        else
            std::cout << BOLD LIGHT_RED "NOK" RESET;
        std::cout << std::endl;

        std::cout << "Assignment to self: ";
        // TODO: implementar exception e alterar aqui 
        std::cout << BOLD LIGHT_GREEN "OK" RESET << std::endl;
    }
}

void test_vector_access() {
    unsigned int size = 10;
    ft::Vector myVector(size);
    const ft::Vector &myVectorRef = myVector;

    {  // Testing initialising vector values
        std::cout << "Initialising vector values: ";
        for (unsigned int i = 0; i < size; i++)
            myVector[i] = i * 0.1;
        for (unsigned int i = 0; i < size; i++) {
            if (myVector[i] != i * 0.1)
                std::cout << BOLD LIGHT_RED "NOK" RESET;
        }
        std::cout << BOLD LIGHT_GREEN "OK" RESET;
        std::cout << std::endl;
    }
    {
        std::cout << "Accessing vector values: ";
        for (unsigned int i = 0; i < size; i++) {
            if (myVector[i] != i * 0.1)
                std::cout << BOLD LIGHT_RED "NOK" RESET;
        }
        std::cout << BOLD LIGHT_GREEN "OK" RESET;
        std::cout << std::endl;
    }
    {
        int index = 2;
        std::cout << "Testing accessors by reference: ";
        myVector[index] = 42;
        (myVectorRef[index] != myVector[index]) ? (std::cout << BOLD LIGHT_RED "NOK" RESET) : (std::cout << BOLD LIGHT_GREEN "OK" RESET);
        std::cout << " ";

        index = 9;
        myVector[index] = -42;
        (myVectorRef[index] != myVector[index]) ? (std::cout << BOLD LIGHT_RED "NOK" RESET) : (std::cout << BOLD LIGHT_GREEN "OK" RESET);
        std::cout << " ";

        index = 0;
        myVector[index] = 24;
        (myVectorRef[index] != myVector[index]) ? (std::cout << BOLD LIGHT_RED "NOK" RESET) : (std::cout << BOLD LIGHT_GREEN "OK" RESET);
        std::cout << std::endl;
    }
}

int main() {
    // Preliminary tests, delete later maybe
    std::cout << "Preliminary tests:" << std::endl;
    ft::Map::test();
    ft::Set::test();
    ft::Stack::test();
    ft::Vector::test();
    std::cout << std::endl;

    // Vector creation test
    std::cout << "Vector creation tests:" << std::endl;
    test_vector_creation();
    std::cout << std::endl;

    // Accessing elements of Vector
    std::cout << "Vector accessor tests (subscript operator):" << std::endl;
    test_vector_access();

    return 0;
}