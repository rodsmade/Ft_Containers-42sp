#include "ft_containers.hpp"

void test_vector_creation() {
    unsigned int intendedSize = 42;
    ft::Vector testVector(intendedSize);

    // Testing Size on Creation
    std::cout << "Size on creation: ";
    if (testVector.size() == intendedSize)
        std::cout << "OK";
    else
        std::cout << "NOK";
    std::cout << std::endl;

    // Testing Initialisation of values
    std::cout << "Initialisation values: ";
    for (unsigned int i = 0; i < testVector.size(); i++) {

        if (testVector.get(i) != 0)
            std::cout << "NOK";
    }
    std::cout << "OK";
    std::cout << std::endl;

    // Testing Valid set() operation at valid index
    std::cout << "Setting value at valid index: ";

    double designatedValue = 42.0;
    unsigned int designatedIndex = 12;
    
    testVector.set(designatedIndex, designatedValue);
    if (testVector.get(designatedIndex) == designatedValue)
        std::cout << "OK";
    else
        std::cout << "NOK";
    std::cout << std::endl;
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

    return 0;
}