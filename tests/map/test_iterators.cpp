#include "map_tests.hpp"

static void test_begin_by_reference(const ft::map<int> &ftMap, int expectedValue) {
    ft::map<int>::const_iterator it(ftMap.begin());
    my_assert(*it == expectedValue, "Begin const_iterator points to the correct element (test by reference)");
}

static void test_begin() {
    std::cout << "\n=== Test begin() iterator ===" << std::endl;

    ft::map<int> ftMap;
    {
        ft::map<int>::iterator nullIt(NULL);

        my_assert(ftMap.begin() == nullIt, "Begin iterator to empty map");
    }
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

static void test_end_by_reference(const ft::map<int> &ftMap, int lastValue) {
    ft::map<int>::iterator expectedEnd(ftMap.begin());
    for (ft::map<int>::size_type i = 0; i < ftMap.size(); i++)
        ++expectedEnd;

    ft::map<int>::iterator actualEnd = ftMap.end();

    my_assert(actualEnd == expectedEnd, "End const_iterator points to the correct element (test by reference)");
    my_assert(*(--actualEnd) == lastValue, "Last element of map accessed via end()");
}

static void test_end() {
    std::cout << "\n=== Test end() iterator ===" << std::endl;
    ft::map<int> ftMap;

    ftMap.insert(1);
    ftMap.insert(2);
    ftMap.insert(3);
    ftMap.insert(4);
    ftMap.insert(5);

    ft::map<int>::iterator expectedEnd(ftMap.begin());
    for (int i = 0; i < 5; i++)
        ++expectedEnd;

    my_assert(ftMap.end() == expectedEnd, "End iterator points to the correct element");
    test_end_by_reference(ftMap, 5);
}

void test_map_iterators(void) {
    test_begin();
    test_end();
}
