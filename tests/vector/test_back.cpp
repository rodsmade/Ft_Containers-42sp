#include "vector_tests.hpp"

static bool test_by_reference(const ft::vector<double> &ftVector, double expectedValue) {
    return (ftVector.back() == expectedValue);
}

void test_vector_back(void) {
    std::cout << "\n=== Last element of vector ( back() ) ===" << std::endl;

    ft::vector<double> ftVector(42);
    double lastElement;

    bool integrityCheck = true;
    bool integrityCheckByRef = true;

    for (int i = 0; i < 100; i++) {
        lastElement = i * 257.5;
        ftVector.push_back(lastElement);

        integrityCheck = integrityCheck && (ftVector.back() == lastElement);
        integrityCheckByRef = integrityCheckByRef && test_by_reference(ftVector, lastElement);
    }

    my_assert(integrityCheck, "Adding multiple elements in vector via push_back and checking integrity ( reference back() )");
    my_assert(integrityCheckByRef, "Checking integrity of element returned by back via const reference ( const_reference back() const )");

}
