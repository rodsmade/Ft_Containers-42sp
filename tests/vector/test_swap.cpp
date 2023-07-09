#include "vector_tests.hpp"

static void test_member_swap() {
    std::cout << "=== Member swap() ===" << std::endl;
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

    my_assert(vector2.size() == originalSizeV1 && vector1.size() == originalSizeV2, "Size check post-swap");
    my_assert(vector2.capacity() == originalCapacityV1 && vector1.capacity() == originalCapacityV2, "Capacity check post-swap");

    bool integrityCheckv1 = true;
    bool integrityCheckv2 = true;

    for (ft::vector<unsigned long>::size_type i = 0; i < originalSizeV1; i++)
        integrityCheckv2 = integrityCheckv2 && (vector2.at(i) == i + 1);
    for (ft::vector<unsigned long>::size_type i = 0; i < originalSizeV2; i++)
        integrityCheckv1 = integrityCheckv1 && (vector1.at(i) == i + 6);

    my_assert(integrityCheckv1, "Integrity check of vector 1 post-swap");
    my_assert(integrityCheckv2, "Integrity check of vector 2 post-swap");
}

static void test_non_member_swap() {
    std::cout << "=== Non-member swap() ===" << std::endl;

    ft::vector<int>::size_type sizeFoo = 3;
    ft::vector<int>::size_type sizeBar = 5;
    ft::vector<int>::value_type valueFoo = 100;
    ft::vector<int>::value_type valueBar = 200;

    ft::vector<int> foo (sizeFoo, valueFoo);   // three ints with a value of 100
    ft::vector<int> bar (sizeBar, valueBar);   // five ints with a value of 200

    foo.swap(bar);

    my_assert(foo == ft::vector<int>(sizeBar, valueBar), "Integrity of vector 1 post-swap");
    my_assert(bar == ft::vector<int>(sizeFoo, valueFoo), "Integrity of vector 2 post-swap");
}

void test_vector_swap(void) {
    std::cout << "\n=== Test vector swap() ===" << std::endl;
    test_member_swap();
    test_non_member_swap();
}
