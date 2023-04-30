#include "test_functions_header.hpp"

void test_reserve(void) {
    std::cout << "\n=== Test reserve ===" << std::endl;

    ft::vector<int> ftVector(42);
    std::vector<int> stdVector(42);

    ftVector.reserve(50);
    stdVector.reserve(50);
    assert(ftVector.size() == stdVector.size(), "Size check against std::vector after resizing to a higher value");
    assert(ftVector.capacity() == stdVector.capacity(), "Capacity check against std::vector after resizing to a higher value");

    ftVector.reserve(5);
    stdVector.reserve(5);
    assert(ftVector.size() == stdVector.size(), "Size check against std::vector after resizing to a lower value");
    assert(ftVector.capacity() == stdVector.capacity(), "Capacity check against std::vector after resizing to a lower value");
}