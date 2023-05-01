#include "test_functions_header.hpp"

static void test_by_reference(const ft::vector<int> &ftVector, int expectedValue) {
    ft::vector<int>::const_iterator it = ftVector.begin();
    assert(*it == expectedValue, "End const_iterator points to the correct element (test by reference)");
}

void test_end() {
    std::cout << "\n=== Test end() iterator ===" << std::endl;
    ft::vector<int> ftVector;

    ftVector.push_back(1);
    ftVector.push_back(2);
    ftVector.push_back(3);
    ftVector.push_back(4);
    ftVector.push_back(5);

    ft::vector<int>::iterator it = ftVector.end();

    assert(it == ftVector.begin() + ftVector.size(), "End iterator points to the correct element");
    test_by_reference(ftVector, 1);
}