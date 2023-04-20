#include "test_functions_header.hpp"

void test_emptiness(void) {
    std::cout << "=== Tests for emptiness ===" << std::endl;
    std::vector<double> stdVector;
    ft::vector<double> ftVector;

    std::cout << std::boolalpha;
    assert(stdVector.empty() == ftVector.empty(), "Emptiness upon initialization");

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
    assert(stdVector.empty() == ftVector.empty(), "Emptiness after adding some elements");

    stdVector.resize(0);
    ftVector.resize(0);
    assert(stdVector.empty() == ftVector.empty(), "Emptiness after resizing to 0");
}