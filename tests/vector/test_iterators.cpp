#include "vector_tests.hpp"

static void test_begin_by_reference(const ft::vector<int> &ftVector, int expectedValue) {
    ft::vector<int>::const_iterator it(ftVector.begin());
    assert(*it == expectedValue, "Begin const_iterator points to the correct element (test by reference)");
}

static void test_begin() {
    std::cout << "\n=== Test begin() iterator ===" << std::endl;
    ft::vector<int> ftVector;

    ftVector.push_back(1);
    ftVector.push_back(2);
    ftVector.push_back(3);
    ftVector.push_back(4);
    ftVector.push_back(5);

    ft::vector<int>::iterator it = ftVector.begin();

    assert(*it == 1, "Begin iterator points to the correct element");
    test_begin_by_reference(ftVector, 1);
}

static void test_end_by_reference(const ft::vector<int> &ftVector, int lastValue) {
    ft::vector<int>::iterator expectedEnd(ftVector.begin());
    for (ft::vector<int>::size_type i = 0; i < ftVector.size(); i++)
        expectedEnd++;

    ft::vector<int>::iterator actualEnd = ftVector.end();

    assert(actualEnd == expectedEnd, "End const_iterator points to the correct element (test by reference)");
    assert(*(--actualEnd) == lastValue, "Last element of vector accessed via end()");
}

static void test_end() {
    std::cout << "\n=== Test end() iterator ===" << std::endl;
    ft::vector<int> ftVector;

    ftVector.push_back(1);
    ftVector.push_back(2);
    ftVector.push_back(3);
    ftVector.push_back(4);
    ftVector.push_back(5);

    ft::vector<int>::iterator expectedEnd(ftVector.begin());
    for (int i = 0; i < 5; i++)
        expectedEnd++;

    assert(ftVector.end() == expectedEnd, "End iterator points to the correct element");
    test_end_by_reference(ftVector, 5);
}

static void test_rbegin_by_reference(const ft::vector<int> &ftVector, int expectedValue) {
    ft::vector<int>::reverse_iterator it = ftVector.rbegin();
    assert(*it == expectedValue, "Rbegin const_iterator points to the correct element (test by reference)");
}

static void test_rbegin() {
    std::cout << "\n=== Test rbegin() iterator ===" << std::endl;
    ft::vector<int> ftVector;

    ftVector.push_back(1);
    ftVector.push_back(2);
    ftVector.push_back(3);
    ftVector.push_back(4);
    ftVector.push_back(5);

    ft::vector<int>::reverse_iterator it = ftVector.rbegin();

    assert(*it == 5, "Rbegin iterator points to the correct element");
    test_rbegin_by_reference(ftVector, 5);
}

static void test_rend_by_reference(const ft::vector<int> &ftVector, int lastValue) {
    ft::vector<int>::reverse_iterator expectedRend(ftVector.rbegin());

    for (ft::vector<int>::size_type i = 0; i < ftVector.size(); i++)
        expectedRend++;

    assert(ftVector.rend() == expectedRend, "Rend const_iterator points to the correct element (test by reference)");
    assert(*(--expectedRend) == lastValue, "Last element of vector accessed via rend()");
}

static void test_rend() {
    std::cout << "\n=== Test rend() iterator ===" << std::endl;
    ft::vector<int> ftVector;

    ftVector.push_back(1);
    ftVector.push_back(2);
    ftVector.push_back(3);
    ftVector.push_back(4);
    ftVector.push_back(5);

    ft::vector<int>::reverse_iterator expectedRend(ftVector.rbegin());
    for (int i = 0; i < 5; i++)
        expectedRend++;

    assert(ftVector.rend() == expectedRend, "Rend iterator points to the correct element");
    test_rend_by_reference(ftVector, 1);
}


void test_vector_iterators(void) {
    test_begin();
    test_end();
    test_rbegin();
    test_rend();
}