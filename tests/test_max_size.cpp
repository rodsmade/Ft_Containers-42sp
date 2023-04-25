#include "test_functions_header.hpp"

void test_max_size(void) {
    std::cout << "\n=== Test maxsize ===" << std::endl;
    std::vector<double> stdVector;
    ft::vector<double> ftVector;

    assert(stdVector.max_size() == ftVector.max_size(), "Max size against std::vector");
    std::cout << "ft: " << ftVector.max_size() << "\t\tstd:: " << stdVector.max_size() << std::endl;
    // std::cout << "ft: " << ULONG_MAX << "\tstd:: " << LONG_MAX << std::endl;
    // std::cout << "ft: " << INT_MAX << "\t\t\tstd:: " << UINT_MAX << std::endl;
}