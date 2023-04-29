#include "test_functions_header.hpp"

void test_swap(void) {
    std::cout << "\n=== Test vector swap() ===" << std::endl;
    ft::vector<unsigned long>::size_type originalSizeV1 = 5;
    ft::vector<unsigned long>::size_type originalSizeV2 = 10;

    ft::vector<unsigned long> vector1(originalSizeV1);
    ft::vector<unsigned long> vector2(originalSizeV2);

    for (ft::vector<unsigned long>::size_type i = 0; i < originalSizeV1; i++)
        vector1.at(i) = i + 1;
    for (ft::vector<unsigned long>::size_type i = 0; i < originalSizeV2; i++)
        vector2.at(i) = i + 6;


    ft::vector<unsigned long>::size_type originalCapacityV1 = vector1.capacity();
    ft::vector<unsigned long>::size_type originalCapacityV2 = vector2.capacity();

    vector1.swap(vector2);

    assert(vector2.size() == originalSizeV1 && vector1.size() == originalSizeV2, "Size check post-swap");
    assert(vector2.capacity() == originalCapacityV1 && vector1.capacity() == originalCapacityV2, "Capacity check post-swap");

    bool integrityCheckv1 = true;
    bool integrityCheckv2 = true;

    for (ft::vector<unsigned long>::size_type i = 0; i < originalSizeV1; i++)
        integrityCheckv2 = integrityCheckv2 && (vector2.at(i) == i + 1);
    for (ft::vector<unsigned long>::size_type i = 0; i < originalSizeV2; i++)
        integrityCheckv1 = integrityCheckv1 && (vector1.at(i) == i + 6);

    assert(integrityCheckv1, "Integrity check of vector 1 post-swap");
    assert(integrityCheckv2, "Integrity check of vector 2 post-swap");
}
