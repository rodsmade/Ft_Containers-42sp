#include "vector_tests.hpp"

void test_vector_size_and_capacity(void) {
    std::cout << "\n=== Test size and capacity ===" << std::endl;

    ft::vector<int>::size_type intendedSize = 42;
    ft::vector<int> ftVector(intendedSize);
    std::vector<int> stdVector(intendedSize);

    assert(ftVector.size() == intendedSize, "Size upon creation");
    assert(ftVector.capacity() == intendedSize, "Capacity upon creation");
    assert(ftVector.size() == stdVector.size(), "Size check against std::vector");
    assert(ftVector.capacity() == stdVector.capacity(), "Size check against std::vector");
}