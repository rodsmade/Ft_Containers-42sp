#include "map_tests.hpp"

static void test_begin_by_reference(const ft::map<int> &ftMap, int expectedValue) {
    ft::map<int>::const_iterator it(ftMap.begin());
    my_assert(*it == expectedValue, "Begin const_iterator points to the correct element (test by reference)");
}

static void test_begin() {
    std::cout << "\n=== Test begin() iterator ===" << std::endl;

    ft::map<int> ftMap;
    {
        std::cout << " └ Balanced Tree" << std::endl;

        ftMap.insert(4);
        ftMap.insert(2);
        ftMap.insert(3);
        ftMap.insert(1);
        ftMap.insert(6);
        ftMap.insert(5);
        ftMap.insert(7);

        ft::map<int>::iterator it = ftMap.begin();

        my_assert(*it == 1, "Begin iterator points to the correct element");
        test_begin_by_reference(ftMap, 1);
    }
    {
        std::cout << " └ Unbalanced Tree" << std::endl;

        ftMap.insert(7);
        ftMap.insert(6);
        ftMap.insert(5);
        ftMap.insert(4);
        ftMap.insert(3);
        ftMap.insert(2);
        ftMap.insert(1);

        ft::map<int>::iterator it = ftMap.begin();

        my_assert(*it == 1, "Begin iterator points to the correct element");
        test_begin_by_reference(ftMap, 1);
    }
}

void test_map_iterators(void) {
    test_begin();
}
