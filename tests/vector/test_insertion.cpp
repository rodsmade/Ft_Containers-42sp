#include "vector_tests.hpp"

static void test_single_insert(void) {
    {
        std::cout << "  Single element insert ( insert(const_iterator pos, const_reference value) )" << std::endl;
        std::cout << "    Insertion size within current capacity (no internal reserve() needed)" << std::endl;
        ft::vector<int> ftVector(50);

        ftVector.resize(10);
        for (int i = 0; i < 10; i++)
            ftVector.at(i) = i + 1;

        ft::vector<int>::size_type oldSize = ftVector.size();

        ft::vector<int>::iterator tempIt(ftVector.begin());
        for (int i = 0; i < 5; i++)
            tempIt++;
        ft::vector<int>::const_iterator insertPosition(tempIt);

        ftVector.insert(insertPosition, 42);

        assert(ftVector.size() == oldSize + 1, "Size check for insertion in arbitrary position");
        assert(ftVector.at(0) == 1 &&
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
            , "Consistency check for insertion in arbitrary position");  

        oldSize = ftVector.size();
        ftVector.insert(ftVector.begin(), 21);

        assert(ftVector.size() == oldSize + 1, "Size check for insertion in the beginning of vector");
        assert(ftVector.at(0) == 21 &&
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
            , "Consistency check for insertion in the beginning of vector");

        oldSize = ftVector.size();
        ftVector.insert(ftVector.end(), 84);

        assert(ftVector.size() == oldSize + 1, "Size check for insertion at the end of vector");
        assert(ftVector.at(0) == 21 &&
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
            , "Consistency check for insertion at the end of vector");
    }
    {
        std::cout << "    Insertion size greater than current capacity (internal reserve() needed)" << std::endl;
        ft::vector<int> ftVector(10);
        for (int i = 0; i < 10; i++)
            ftVector.at(i) = i + 1;

        ft::vector<int>::size_type oldSize = ftVector.size();

        ft::vector<int>::iterator insertPos = ftVector.begin();
        for (int i = 0; i < 5; i++)
            insertPos++;
        
        ftVector.insert(insertPos, 42);

        assert(ftVector.size() == oldSize + 1, "Size check for insertion in arbitrary position");
        assert(ftVector.at(0) == 1 &&
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
            , "Consistency check for insertion in arbitrary position");

        oldSize = ftVector.size();
        ftVector.insert(ftVector.begin(), 21);

        assert(ftVector.size() == oldSize + 1, "Size check for insertion in the beginning of vector");
        assert(ftVector.at(0) == 21 &&
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
            , "Consistency check for insertion in the beginning of vector");

        oldSize = ftVector.size();
        ftVector.insert(ftVector.end(), 84);

        assert(ftVector.size() == oldSize + 1, "Size check for insertion at the end of vector");
        assert(ftVector.at(0) == 21 &&
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
            , "Consistency check for insertion at the end of vector");
    }
}

// static void test_fill_insert(void) {
//     {
//         std::cout << "\n  Fill insert ( insert(const_iterator pos, size_type count, const_reference value) )" << std::endl;
//         std::cout << "    Insertion size within current capacity (no internal reserve() needed)" << std::endl;
//         ft::vector<int> ftVector(50);

//         ftVector.resize(10);
//         for (int i = 0; i < 10; i++)
//             ftVector.at(i) = i + 1;

//         ft::vector<int>::size_type oldSize = ftVector.size();
//         ft::vector<int>::size_type numberOfCopies = 6;

//         ft::vector<int>::iterator insertPos = ftVector.begin();
//         for (int i = 0; i < 5; i++)
//             insertPos++;
        
//         ftVector.insert(insertPos, 42);
//         ftVector.insert(insertPos, numberOfCopies, 42);

//         assert(ftVector.size() == oldSize + numberOfCopies, "Size check for insertion in arbitrary position");
//         assert(ftVector.at(0) == 1 &&
//             ftVector.at(1) == 2 &&
//             ftVector.at(2) == 3 &&
//             ftVector.at(3) == 4 &&
//             ftVector.at(4) == 5 &&
//             ftVector.at(5) == 42 &&
//             ftVector.at(6) == 42 &&
//             ftVector.at(7) == 42 &&
//             ftVector.at(8) == 42 &&
//             ftVector.at(9) == 42 &&
//             ftVector.at(10) == 42 &&
//             ftVector.at(11) == 6 &&
//             ftVector.at(12) == 7 &&
//             ftVector.at(13) == 8 &&
//             ftVector.at(14) == 9 &&
//             ftVector.at(15) == 10
//             , "Consistency check for insertion in arbitrary position");

//         oldSize = ftVector.size();
//         numberOfCopies = 3;
//         ftVector.insert(ftVector.begin(), numberOfCopies, 21);

//         assert(ftVector.size() == oldSize + numberOfCopies, "Size check for insertion in the beginning of vector");
//         assert(ftVector.at(0) == 21 &&
//             ftVector.at(1) == 21 &&
//             ftVector.at(2) == 21 &&
//             ftVector.at(3) == 1 &&
//             ftVector.at(4) == 2 &&
//             ftVector.at(5) == 3 &&
//             ftVector.at(6) == 4 &&
//             ftVector.at(7) == 5 &&
//             ftVector.at(8) == 42 &&
//             ftVector.at(9) == 42 &&
//             ftVector.at(10) == 42 &&
//             ftVector.at(11) == 42 &&
//             ftVector.at(12) == 42 &&
//             ftVector.at(13) == 42 &&
//             ftVector.at(14) == 6 &&
//             ftVector.at(15) == 7 &&
//             ftVector.at(16) == 8 &&
//             ftVector.at(17) == 9 &&
//             ftVector.at(18) == 10
//             , "Consistency check for insertion in the beginning of vector");

//         oldSize = ftVector.size();
//         numberOfCopies = 4;
//         ftVector.insert(ftVector.end(), numberOfCopies, 84);

//         assert(ftVector.size() == oldSize + numberOfCopies, "Size check for insertion at the end of vector");
//         assert(ftVector.at(0) == 21 &&
//             ftVector.at(1) == 21 &&
//             ftVector.at(2) == 21 &&
//             ftVector.at(3) == 1 &&
//             ftVector.at(4) == 2 &&
//             ftVector.at(5) == 3 &&
//             ftVector.at(6) == 4 &&
//             ftVector.at(7) == 5 &&
//             ftVector.at(8) == 42 &&
//             ftVector.at(9) == 42 &&
//             ftVector.at(10) == 42 &&
//             ftVector.at(11) == 42 &&
//             ftVector.at(12) == 42 &&
//             ftVector.at(13) == 42 &&
//             ftVector.at(14) == 6 &&
//             ftVector.at(15) == 7 &&
//             ftVector.at(16) == 8 &&
//             ftVector.at(17) == 9 &&
//             ftVector.at(18) == 10 &&
//             ftVector.at(19) == 84 &&
//             ftVector.at(20) == 84 &&
//             ftVector.at(21) == 84 &&
//             ftVector.at(22) == 84
//             , "Consistency check for insertion at the end of vector");
//     }
//     {
//         std::cout << "    Insertion size greater than current capacity (internal reserve() needed)" << std::endl;
//         ft::vector<int> ftVector(10);

//         for (int i = 0; i < 10; i++)
//             ftVector.at(i) = i + 1;

//         ft::vector<int>::size_type oldSize = ftVector.size();
//         ft::vector<int>::size_type numberOfCopies = 6;

//         ft::vector<int>::iterator insertPos = ftVector.begin();
//         for (int i = 0; i < 5; i++)
//             insertPos++;
        
//         ftVector.insert(insertPos, numberOfCopies, 42);

//         assert(ftVector.size() == oldSize + numberOfCopies, "Size check for insertion at arbitrary position");
//         assert(ftVector.at(0) == 1 &&
//             ftVector.at(1) == 2 &&
//             ftVector.at(2) == 3 &&
//             ftVector.at(3) == 4 &&
//             ftVector.at(4) == 5 &&
//             ftVector.at(5) == 42 &&
//             ftVector.at(6) == 42 &&
//             ftVector.at(7) == 42 &&
//             ftVector.at(8) == 42 &&
//             ftVector.at(9) == 42 &&
//             ftVector.at(10) == 42 &&
//             ftVector.at(11) == 6 &&
//             ftVector.at(12) == 7 &&
//             ftVector.at(13) == 8 &&
//             ftVector.at(14) == 9 &&
//             ftVector.at(15) == 10
//             , "Consistency check for insertion at arbitrary position");

//         oldSize = ftVector.size();
//         numberOfCopies = 3;
//         ftVector.insert(ftVector.begin(), numberOfCopies, 21);

//         assert(ftVector.size() == oldSize + numberOfCopies, "Size check for insertion in the beginning of vector");
//         assert(ftVector.at(0) == 21 &&
//             ftVector.at(1) == 21 &&
//             ftVector.at(2) == 21 &&
//             ftVector.at(3) == 1 &&
//             ftVector.at(4) == 2 &&
//             ftVector.at(5) == 3 &&
//             ftVector.at(6) == 4 &&
//             ftVector.at(7) == 5 &&
//             ftVector.at(8) == 42 &&
//             ftVector.at(9) == 42 &&
//             ftVector.at(10) == 42 &&
//             ftVector.at(11) == 42 &&
//             ftVector.at(12) == 42 &&
//             ftVector.at(13) == 42 &&
//             ftVector.at(14) == 6 &&
//             ftVector.at(15) == 7 &&
//             ftVector.at(16) == 8 &&
//             ftVector.at(17) == 9 &&
//             ftVector.at(18) == 10
//             , "Consistency check for insertion in the beginning of vector");

//         oldSize = ftVector.size();
//         numberOfCopies = 4;
//         ftVector.insert(ftVector.end(), numberOfCopies, 84);

//         assert(ftVector.size() == oldSize + numberOfCopies, "Size check for insertion at the end of vector");
//         assert(ftVector.at(0) == 21 &&
//             ftVector.at(1) == 21 &&
//             ftVector.at(2) == 21 &&
//             ftVector.at(3) == 1 &&
//             ftVector.at(4) == 2 &&
//             ftVector.at(5) == 3 &&
//             ftVector.at(6) == 4 &&
//             ftVector.at(7) == 5 &&
//             ftVector.at(8) == 42 &&
//             ftVector.at(9) == 42 &&
//             ftVector.at(10) == 42 &&
//             ftVector.at(11) == 42 &&
//             ftVector.at(12) == 42 &&
//             ftVector.at(13) == 42 &&
//             ftVector.at(14) == 6 &&
//             ftVector.at(15) == 7 &&
//             ftVector.at(16) == 8 &&
//             ftVector.at(17) == 9 &&
//             ftVector.at(18) == 10 &&
//             ftVector.at(19) == 84 &&
//             ftVector.at(20) == 84 &&
//             ftVector.at(21) == 84 &&
//             ftVector.at(22) == 84
//             , "Consistency check for insertion at the end of vector");
//     }
// }

// static void test_range_insert(void) {
//     {
//         std::cout << "\n  Range insert ( insert(const_iterator pos, InputIt first, InputIt last) )" << std::endl;
//         std::cout << "    Insertion size within current capacity (no internal reserve() needed)" << std::endl;
//         ft::vector<int> ftVector(50);

//         ftVector.resize(10);
//         for (int i = 0; i < 10; i++)
//             ftVector.at(i) = i + 1;

//         ft::vector<int>::size_type oldSize = ftVector.size();
//         ft::vector<int>::size_type numberOfCopies = 6;
//         ft::vector<int> rangeVector(numberOfCopies, 42);

//         ft::vector<int>::iterator insertPos = ftVector.begin();
//         for (int i = 0; i < 5; i++)
//             insertPos++;

//         ftVector.insert(insertPos, rangeVector.begin(), rangeVector.end());

//         assert(ftVector.size() == oldSize + numberOfCopies, "Size check for insertion in arbitrary position");
//         assert(ftVector.at(0) == 1 &&
//             ftVector.at(1) == 2 &&
//             ftVector.at(2) == 3 &&
//             ftVector.at(3) == 4 &&
//             ftVector.at(4) == 5 &&
//             ftVector.at(5) == 42 &&
//             ftVector.at(6) == 42 &&
//             ftVector.at(7) == 42 &&
//             ftVector.at(8) == 42 &&
//             ftVector.at(9) == 42 &&
//             ftVector.at(10) == 42 &&
//             ftVector.at(11) == 6 &&
//             ftVector.at(12) == 7 &&
//             ftVector.at(13) == 8 &&
//             ftVector.at(14) == 9 &&
//             ftVector.at(15) == 10
//             , "Consistency check for insertion in arbitrary position");

//         oldSize = ftVector.size();
//         numberOfCopies = 3;
//         rangeVector.clear();
//         rangeVector.insert(rangeVector.begin(), numberOfCopies, 21);

//         ftVector.insert(ftVector.begin(), rangeVector.begin(), rangeVector.end());

//         assert(ftVector.size() == oldSize + numberOfCopies, "Size check for insertion in the beginning of vector");
//         assert(ftVector.at(0) == 21 &&
//             ftVector.at(1) == 21 &&
//             ftVector.at(2) == 21 &&
//             ftVector.at(3) == 1 &&
//             ftVector.at(4) == 2 &&
//             ftVector.at(5) == 3 &&
//             ftVector.at(6) == 4 &&
//             ftVector.at(7) == 5 &&
//             ftVector.at(8) == 42 &&
//             ftVector.at(9) == 42 &&
//             ftVector.at(10) == 42 &&
//             ftVector.at(11) == 42 &&
//             ftVector.at(12) == 42 &&
//             ftVector.at(13) == 42 &&
//             ftVector.at(14) == 6 &&
//             ftVector.at(15) == 7 &&
//             ftVector.at(16) == 8 &&
//             ftVector.at(17) == 9 &&
//             ftVector.at(18) == 10
//             , "Consistency check for insertion in the beginning of vector");

//         oldSize = ftVector.size();
//         numberOfCopies = 4;
//         rangeVector.clear();
//         rangeVector.insert(rangeVector.begin(), numberOfCopies, 84);

//         ftVector.insert(ftVector.end(), rangeVector.begin(), rangeVector.end());

//         assert(ftVector.size() == oldSize + numberOfCopies, "Size check for insertion at the end of vector");
//         assert(ftVector.at(0) == 21 &&
//             ftVector.at(1) == 21 &&
//             ftVector.at(2) == 21 &&
//             ftVector.at(3) == 1 &&
//             ftVector.at(4) == 2 &&
//             ftVector.at(5) == 3 &&
//             ftVector.at(6) == 4 &&
//             ftVector.at(7) == 5 &&
//             ftVector.at(8) == 42 &&
//             ftVector.at(9) == 42 &&
//             ftVector.at(10) == 42 &&
//             ftVector.at(11) == 42 &&
//             ftVector.at(12) == 42 &&
//             ftVector.at(13) == 42 &&
//             ftVector.at(14) == 6 &&
//             ftVector.at(15) == 7 &&
//             ftVector.at(16) == 8 &&
//             ftVector.at(17) == 9 &&
//             ftVector.at(18) == 10 &&
//             ftVector.at(19) == 84 &&
//             ftVector.at(20) == 84 &&
//             ftVector.at(21) == 84 &&
//             ftVector.at(22) == 84
//             , "Consistency check for insertion at the end of vector");
//     }
//     {
//         std::cout << "    Insertion size greater than current capacity (internal reserve() needed)" << std::endl;
//         ft::vector<int> ftVector(10);

//         for (int i = 0; i < 10; i++)
//             ftVector.at(i) = i + 1;

//         ft::vector<int>::size_type oldSize = ftVector.size();
//         ft::vector<int>::size_type numberOfCopies = 6;

//         ft::vector<int>::iterator insertPos = ftVector.begin();
//         for (int i = 0; i < 5; i++)
//             insertPos++;

//         ftVector.insert(insertPos, numberOfCopies, 42);

//         assert(ftVector.size() == oldSize + numberOfCopies, "Size check for insertion at arbitrary position");
//         assert(ftVector.at(0) == 1 &&
//             ftVector.at(1) == 2 &&
//             ftVector.at(2) == 3 &&
//             ftVector.at(3) == 4 &&
//             ftVector.at(4) == 5 &&
//             ftVector.at(5) == 42 &&
//             ftVector.at(6) == 42 &&
//             ftVector.at(7) == 42 &&
//             ftVector.at(8) == 42 &&
//             ftVector.at(9) == 42 &&
//             ftVector.at(10) == 42 &&
//             ftVector.at(11) == 6 &&
//             ftVector.at(12) == 7 &&
//             ftVector.at(13) == 8 &&
//             ftVector.at(14) == 9 &&
//             ftVector.at(15) == 10
//             , "Consistency check for insertion at arbitrary position");

//         oldSize = ftVector.size();
//         numberOfCopies = 3;
//         ftVector.insert(ftVector.begin(), numberOfCopies, 21);

//         assert(ftVector.size() == oldSize + numberOfCopies, "Size check for insertion in the beginning of vector");
//         assert(ftVector.at(0) == 21 &&
//             ftVector.at(1) == 21 &&
//             ftVector.at(2) == 21 &&
//             ftVector.at(3) == 1 &&
//             ftVector.at(4) == 2 &&
//             ftVector.at(5) == 3 &&
//             ftVector.at(6) == 4 &&
//             ftVector.at(7) == 5 &&
//             ftVector.at(8) == 42 &&
//             ftVector.at(9) == 42 &&
//             ftVector.at(10) == 42 &&
//             ftVector.at(11) == 42 &&
//             ftVector.at(12) == 42 &&
//             ftVector.at(13) == 42 &&
//             ftVector.at(14) == 6 &&
//             ftVector.at(15) == 7 &&
//             ftVector.at(16) == 8 &&
//             ftVector.at(17) == 9 &&
//             ftVector.at(18) == 10
//             , "Consistency check for insertion in the beginning of vector");

//         oldSize = ftVector.size();
//         numberOfCopies = 4;
//         ftVector.insert(ftVector.end(), numberOfCopies, 84);

//         assert(ftVector.size() == oldSize + numberOfCopies, "Size check for insertion at the end of vector");
//         assert(ftVector.at(0) == 21 &&
//             ftVector.at(1) == 21 &&
//             ftVector.at(2) == 21 &&
//             ftVector.at(3) == 1 &&
//             ftVector.at(4) == 2 &&
//             ftVector.at(5) == 3 &&
//             ftVector.at(6) == 4 &&
//             ftVector.at(7) == 5 &&
//             ftVector.at(8) == 42 &&
//             ftVector.at(9) == 42 &&
//             ftVector.at(10) == 42 &&
//             ftVector.at(11) == 42 &&
//             ftVector.at(12) == 42 &&
//             ftVector.at(13) == 42 &&
//             ftVector.at(14) == 6 &&
//             ftVector.at(15) == 7 &&
//             ftVector.at(16) == 8 &&
//             ftVector.at(17) == 9 &&
//             ftVector.at(18) == 10 &&
//             ftVector.at(19) == 84 &&
//             ftVector.at(20) == 84 &&
//             ftVector.at(21) == 84 &&
//             ftVector.at(22) == 84
//             , "Consistency check for insertion at the end of vector");
//     }
// }

void test_vector_insertion(void) {
    std::cout << "\n=== Test insertion methods ( insert() ) ===" << std::endl;
    test_single_insert();
    // test_fill_insert();
    // test_range_insert();
}