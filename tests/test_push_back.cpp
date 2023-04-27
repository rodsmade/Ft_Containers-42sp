#include "test_functions_header.hpp"

void test_push_back(void) {
    std::cout << "\n=== Test element insertion in vector ( push_back() ) ===" << std::endl;
    std::vector<int> stdVector;
    ft::vector<int> ftVector;

    bool sizeCheck = true;
    bool capacityCheck = true;

    for (int i = 0; i < 42; i++) {
        stdVector.push_back(i);
        ftVector.push_back(i);
        sizeCheck = sizeCheck && (ftVector.size() == stdVector.size());
        capacityCheck = capacityCheck && (ftVector.capacity() == stdVector.capacity());
    }

    assert(sizeCheck, "Size check when gradually incrementing an empty vector");
    assert(capacityCheck, "Capacity check when gradually incrementing an empty vector");
}
