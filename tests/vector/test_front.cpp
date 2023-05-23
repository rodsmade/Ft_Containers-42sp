#include "vector_tests.hpp"

static bool test_by_reference(const ft::vector<double> &ftVector, double expectedValue) {
    return (ftVector.front() == expectedValue);
}

void test_vector_front(void) {
    std::cout << "\n=== First Element of vector ( front() ) ===" << std::endl;

    ft::vector<double> ftVector;
    double firstElement = 42;

    ftVector.push_back(firstElement);

    bool integrityCheck = true;
    bool integrityCheckByRef = true;

    for (int i = 0; i < 100; i++) {
        ftVector.push_back(i * 257.5);

        integrityCheck = integrityCheck && (ftVector.front() == firstElement);
        integrityCheckByRef = integrityCheckByRef && test_by_reference(ftVector, firstElement);
    }

    assert(integrityCheck, "Adding multiple elements in vector via push_front and checking integrity ( reference front() )");
    assert(integrityCheckByRef, "Checking integrity of element returned by front via const reference ( const_reference front() const )");

}
