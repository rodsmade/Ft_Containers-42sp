#include "test_functions_header.hpp"

void test_resize(void) {
    std::cout << "\n=== Test resize ===" << std::endl;

    std::vector<int> ftVector(42);
    std::vector<int> stdVector(42);

    ftVector.resize(50);
    stdVector.resize(50);
    assert(ftVector.size() == stdVector.size(), "Size check against std::vector after resizing to a higher value");
    assert(ftVector.capacity() == stdVector.capacity(), "Capacity check against std::vector after resizing to a higher value");
    ftVector.resize(5);
    stdVector.resize(5);
    assert(ftVector.size() == stdVector.size(), "Size check against std::vector after resizing to a lower value");
    assert(ftVector.capacity() == stdVector.capacity(), "Capacity check against std::vector after resizing to a lower value");
}