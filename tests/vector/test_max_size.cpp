#include "test_functions_header.hpp"

void test_vector_max_size(void) {
    std::cout << "\n=== Test maxsize ===" << std::endl;
    std::vector<double> stdVector;
    ft::vector<double> ftVector;

    assert(stdVector.max_size() == ftVector.max_size(), "Max size against std::vector");
}