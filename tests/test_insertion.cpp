#include "test_functions_header.hpp"

void test_insertion(void) {

    /*
        RESCREVER OS TESTES CONSIDERANDO:
        - insert no início, no meio e no fim quando vetor tem capacidade disponível
        - insert no início, no meio e no fim quando vetor NÃO TEM capacidade disponível (e precisa dar reserve)
    */

    std::cout << "\n=== Test insertion methods ( insert() ) ===" << std::endl;
    {
        std::cout << "  Single element insert ( insert(const_iterator pos, const_reference value) )" << std::endl;
        ft::vector<int> ftVector(10);
        for (int i = 0; i < 10; i++)
            ftVector.at(i) = i + 1;

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
    {
        std::cout << "\n  Fill insert ( insert(const_iterator pos, size_type count, const_reference value) )" << std::endl;
        ft::vector<int> ftVector;
        for (int i = 1; i <=10; i++)
            ftVector.push_back(i);

        ft::vector<int>::size_type oldSize = ftVector.size();
        ft::vector<int>::size_type numberOfCopies = 6;

        ftVector.insert(ftVector.begin() + 5, numberOfCopies, 42);

        assert(ftVector.size() == oldSize + numberOfCopies &&
            ftVector.at(0) == 1 &&
            ftVector.at(1) == 2 &&
            ftVector.at(2) == 3 &&
            ftVector.at(3) == 4 &&
            ftVector.at(4) == 5 &&
            ftVector.at(5) == 42 &&
            ftVector.at(6) == 42 &&
            ftVector.at(7) == 42 &&
            ftVector.at(8) == 42 &&
            ftVector.at(9) == 42 &&
            ftVector.at(10) == 42 &&
            ftVector.at(11) == 6 &&
            ftVector.at(12) == 7 &&
            ftVector.at(13) == 8 &&
            ftVector.at(14) == 9 &&
            ftVector.at(15) == 10
            , "Consistency check");

        oldSize = ftVector.size();
        numberOfCopies = 3;
        ftVector.insert(ftVector.begin(), numberOfCopies, 21);

        assert(ftVector.size() == oldSize + numberOfCopies &&
            ftVector.at(0) == 21 &&
            ftVector.at(1) == 21 &&
            ftVector.at(2) == 21 &&
            ftVector.at(3) == 1 &&
            ftVector.at(4) == 2 &&
            ftVector.at(5) == 3 &&
            ftVector.at(6) == 4 &&
            ftVector.at(7) == 5 &&
            ftVector.at(8) == 42 &&
            ftVector.at(9) == 42 &&
            ftVector.at(10) == 42 &&
            ftVector.at(11) == 42 &&
            ftVector.at(12) == 42 &&
            ftVector.at(13) == 42 &&
            ftVector.at(14) == 6 &&
            ftVector.at(15) == 7 &&
            ftVector.at(16) == 8 &&
            ftVector.at(17) == 9 &&
            ftVector.at(18) == 10
            , "Consistency check inserting element in the beginning of vector");

        oldSize = ftVector.size();
        numberOfCopies = 3;
        ftVector.insert(ftVector.end(), numberOfCopies, 84);

        assert(ftVector.size() == oldSize + numberOfCopies &&
            ftVector.at(0) == 21 &&
            ftVector.at(1) == 21 &&
            ftVector.at(2) == 21 &&
            ftVector.at(3) == 1 &&
            ftVector.at(4) == 2 &&
            ftVector.at(5) == 3 &&
            ftVector.at(6) == 4 &&
            ftVector.at(7) == 5 &&
            ftVector.at(8) == 42 &&
            ftVector.at(9) == 42 &&
            ftVector.at(10) == 42 &&
            ftVector.at(11) == 42 &&
            ftVector.at(12) == 42 &&
            ftVector.at(13) == 42 &&
            ftVector.at(14) == 6 &&
            ftVector.at(15) == 7 &&
            ftVector.at(16) == 8 &&
            ftVector.at(17) == 9 &&
            ftVector.at(18) == 10 &&
            ftVector.at(19) == 84 &&
            ftVector.at(20) == 84 &&
            ftVector.at(21) == 84 &&
            ftVector.at(22) == 84
            , "Consistency check inserting element in the end of vector");
    }


}