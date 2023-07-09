#include "vector_tests.hpp"

void test_vector_size_and_capacity(void) {
    std::cout << "\n=== Test size and capacity ===" << std::endl;

    ft::vector<int>::size_type intendedSize = 42;
    ft::vector<int> ftVector(intendedSize);
    std::vector<int> stdVector(intendedSize);

    my_assert(ftVector.size() == intendedSize, "Size upon creation");
    my_assert(ftVector.capacity() == intendedSize, "Capacity upon creation");
    my_assert(ftVector.size() == stdVector.size(), "Size check against std::vector");
    my_assert(ftVector.capacity() == stdVector.capacity(), "Size check against std::vector");
}