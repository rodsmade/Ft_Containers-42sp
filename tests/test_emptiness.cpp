#include "tests_headers.hpp"

void test_emptiness(void) {
    std::cout << "=== Tests for emptiness ===" << std::endl;
    std::vector<double> stdVector;
    ft::vector<double> ftVector;

    std::cout << std::boolalpha;
    if (stdVector.empty() == ftVector.empty())
        std::cout << TEST_OK;
    else
        std::cout << TEST_NOK;
    std::cout << "Emptiness upon initialization" << std::endl;
    stdVector.push_back(42);
    stdVector.push_back(42);
    stdVector.push_back(42);
    stdVector.push_back(42);
    stdVector.push_back(42);
    ftVector.push_back(42);
    ftVector.push_back(42);
    ftVector.push_back(42);
    ftVector.push_back(42);
    ftVector.push_back(42);
    if (stdVector.empty() == ftVector.empty())
        std::cout << TEST_OK;
    else
        std::cout << TEST_NOK;
    std::cout << "Emptiness after adding some elements" << std::endl;

    stdVector.resize(0);
    ftVector.resize(0);
    if (stdVector.empty() == ftVector.empty())
        std::cout << TEST_OK;
    else
        std::cout << TEST_NOK;
    std::cout << "Emptiness after resizing to 0" << std::endl;
}