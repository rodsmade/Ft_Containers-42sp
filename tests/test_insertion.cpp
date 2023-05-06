#include "test_functions_header.hpp"

void test_insertion(void) {
    std::cout << "\n=== Test insertion methods ( insert() ) ===" << std::endl;
    {
        ft::vector<int> ftVector;
        for (int i = 1; i <=10; i++)
            ftVector.push_back(i);

        ft::vector<int>::size_type oldSize = ftVector.size();


        ftVector.insert(ftVector.begin() + 5, 42);

        assert(ftVector.size() == oldSize + 1 &&
            ftVector.at(0) == 1 &&
            ftVector.at(1) == 2 &&
            ftVector.at(2) == 3 &&
            ftVector.at(3) == 4 &&
            ftVector.at(4) == 5 &&
            ftVector.at(5) == 42 &&
            ftVector.at(6) == 6 &&
            ftVector.at(7) == 7 &&
            ftVector.at(8) == 8 &&
            ftVector.at(9) == 9 &&
            ftVector.at(10) == 10
            , "Consistency check");

        oldSize = ftVector.size();
        ftVector.insert(ftVector.begin(), 21);

        assert(ftVector.size() == oldSize + 1 &&
            ftVector.at(0) == 21 &&
            ftVector.at(1) == 1 &&
            ftVector.at(2) == 2 &&
            ftVector.at(3) == 3 &&
            ftVector.at(4) == 4 &&
            ftVector.at(5) == 5 &&
            ftVector.at(6) == 42 &&
            ftVector.at(7) == 6 &&
            ftVector.at(8) == 7 &&
            ftVector.at(9) == 8 &&
            ftVector.at(10) == 9 &&
            ftVector.at(11) == 10
            , "Consistency check inserting element in the beginning of vector");

        oldSize = ftVector.size();
        ftVector.insert(ftVector.end(), 84);

        assert(ftVector.size() == oldSize + 1 &&
            ftVector.at(0) == 21 &&
            ftVector.at(1) == 1 &&
            ftVector.at(2) == 2 &&
            ftVector.at(3) == 3 &&
            ftVector.at(4) == 4 &&
            ftVector.at(5) == 5 &&
            ftVector.at(6) == 42 &&
            ftVector.at(7) == 6 &&
            ftVector.at(8) == 7 &&
            ftVector.at(9) == 8 &&
            ftVector.at(10) == 9 &&
            ftVector.at(11) == 10 &&
            ftVector.at(12) == 84
            , "Consistency check inserting element in the end of vector");
    }


}