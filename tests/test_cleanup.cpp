#include "test_functions_header.hpp"

void test_cleanup(void) {
    std::cout << "\n=== Tests the cleaning up process of a vector ===" << std::endl;
    std::vector<int> stdVector;
    ft::vector<int> ftVector;

    for (int i = 0; i < 42; i++) {
        stdVector.push_back(i);
        ftVector.push_back(i);
    }

    stdVector.clear();
    ftVector.clear();

    assert(ftVector.size() == 0, "Vector size after cleanup");
    assert(ftVector.capacity() != 0, "Vector capacity after cleanup");
    assert(ftVector.size() == stdVector.size(), "Check ft::vector size after cleanup against std::vector");
    assert(ftVector.capacity() == stdVector.capacity(), "Check ft::vector capacity after cleanup against std::vector");

}
