#include "tests_headers.hpp"

void test_cleanup(void) {
    std::cout << "=== Tests the cleaning up process of a vector ===" << std::endl;
    std::vector<int> stdVector;
    ft::vector<int> ftVector;

    for (int i = 0; i < 42; i++) {
        stdVector.push_back(i);
        ftVector.push_back(i);

    }

    stdVector.clear();
    ftVector.clear();

    if (stdVector.size() == ftVector.size() && stdVector.capacity() && ftVector.capacity())
        std::cout << TEST_OK;
    else
        std::cout << TEST_NOK;

    std::cout << "Vector cleanup" << std::endl;

}
