#include "vector_tests.hpp"

static void test_positional_erase_returns(void) {
    ft::vector<int> ftVector;

    for (int i = 1; i <= 10; i++) {
        ftVector.push_back(i);
    }

    int *posToDelete;
    int *eraseReturn;

    posToDelete = &(*ftVector.begin());
    eraseReturn = &(*ftVector.erase(ftVector.begin()));

    assert(posToDelete == eraseReturn, "Check iterator return when erasing first element");

    posToDelete = &(*(ftVector.begin() + 4));
    eraseReturn = &(*ftVector.erase(ftVector.begin() + 4));

    assert(posToDelete == eraseReturn, "Check iterator return when erasing arbitrary element");

    ftVector.erase(ftVector.begin());
    ftVector.erase(ftVector.begin());
    ftVector.erase(ftVector.begin());
    ftVector.erase(ftVector.begin());
    ftVector.erase(ftVector.begin());
    ftVector.erase(ftVector.begin());
    ftVector.erase(ftVector.begin());

    posToDelete = &(*ftVector.begin());
    eraseReturn = &(*ftVector.erase(ftVector.begin()));
    assert(posToDelete == eraseReturn, "Check iterator return when vector has only one element left");
    return ;
}

static void test_positional_erase(void) {
    std::cout << "\n  Single instance erase ( erase(iterator pos) ) ===" << std::endl;

    ft::vector<int> ftVector;

    for (int i = 1; i <= 10; i++) {
        ftVector.push_back(i);
    }

    ftVector.erase(ftVector.begin());

    ft::vector<int>::iterator it = ftVector.begin();

    assert(ftVector.size() == 9
            && (*(it) == 2)
            && (*(++it) == 3)
            && (*(++it) == 4)
            && (*(++it) == 5)
            && (*(++it) == 6)
            && (*(++it) == 7)
            && (*(++it) == 8)
            && (*(++it) == 9)
            && (*(++it) == 10)
            , "Consistency check after one erase() in the beginning of vector");

    it = ftVector.begin();
    it++;
    it++;
    it++;
    it++;
    ftVector.erase(it);

    it = ftVector.begin();
    assert(ftVector.size() == 8
            && (*(it) == 2)
            && (*(++it) == 3)
            && (*(++it) == 4)
            && (*(++it) == 5)
            && (*(++it) == 7)
            && (*(++it) == 8)
            && (*(++it) == 9)
            && (*(++it) == 10)
            , "Consistency check after one erase() in the middle of vector");

    ftVector.erase(ftVector.begin());
    ftVector.erase(ftVector.begin());
    ftVector.erase(ftVector.begin());
    ftVector.erase(ftVector.begin());
    ftVector.erase(ftVector.begin());
    ftVector.erase(ftVector.begin());
    ftVector.erase(ftVector.begin());
    assert(ftVector.size() == 1
            && (*(ftVector.begin()) == 10)
            , "Consistency check after many erase()s");

    ftVector.erase(ftVector.begin());
    assert(ftVector.size() == 0, "Size check when emptying vector");
}

static void test_range_erase(void) {
    std::cout << "\n  Range instance erase ( erase(iterator first, iterator last) ) ===" << std::endl;
    ft::vector<int> ftVector;
    ft::vector<int>::iterator returnIt;

    for (int i = 1; i <= 10; i++) {
        ftVector.push_back(i);
    }

    ft::vector<int>::size_type sizeBefore = ftVector.size();
    returnIt = ftVector.erase(ftVector.begin() + 2, ftVector.begin() + 7);
    ft::vector<int>::size_type sizeAfter = ftVector.size();

    assert(returnIt == ftVector.begin() + 2, "Return iterator check for range erase");
    assert(sizeAfter == sizeBefore - 5 &&
            ftVector.at(0) == 1 &&
            ftVector.at(1) == 2 &&
            ftVector.at(2) == 8 &&
            ftVector.at(3) == 9 &&
            ftVector.at(4) == 10
            ,"Consistency check for range erase");


}

void test_vector_erase(void) {
    std::cout << "\n=== Tests for erase() ===";
    test_positional_erase();
    test_positional_erase_returns();
    test_range_erase();
}
