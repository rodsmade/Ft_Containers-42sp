#include "vector_tests_header.hpp"

static bool test_by_reference(const ft::vector<double> &ftVector, double *expectedValue) {
    return (ftVector.data() == expectedValue);
}

void test_vector_data(void) {
    std::cout << "\n=== Tests raw pointer ( data() ) ===" << std::endl;

    ft::vector<double> ftVector(10);

    assert(ftVector.data() == &ftVector.at(0) && ftVector.data() == &ftVector[0], "Address of first element matches pointer returned by data() ( value_type* data() )");
    assert(test_by_reference(ftVector, &ftVector.at(0)) && test_by_reference(ftVector, &ftVector[0]), "Test by reference ( const value_type* data() const )");
}
