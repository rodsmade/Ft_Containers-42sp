#include "vector_tests.hpp"

void test_vector_pop_back(void) {
        std::cout << "\n=== Test element removal in vector ( pop_back() ) ===" << std::endl;

    {
        ft::vector<double> ftVector;
        ft::vector<double>::size_type vectorSize = 50;

        for (ft::vector<double>::size_type i = 0; i < vectorSize; i++) {
            ftVector.push_back(42.0);
        }

        ftVector.pop_back();

        my_assert(ftVector.size() == vectorSize - 1, "Pop back one element");

        for (ft::vector<double>::size_type i = 0; i < vectorSize - 1; i++)
            ftVector.pop_back();

        my_assert(ftVector.empty(), "Vector is empty by popping elements from the back");

    }
    {
        ft::vector<int> ftVector;
        ft::vector<int>::size_type vectorSize = 50;

        for (ft::vector<double>::size_type i = 0; i < vectorSize; i++) {
            ftVector.push_back(i);
        }

        my_assert(ftVector[0] == 0 && ftVector[ftVector.size() - 1] == 49, "Initial elements");

        ftVector.pop_back();

        my_assert(ftVector[0] == 0 && ftVector[ftVector.size() - 1] == 48, "First and last elements consistency after one pop_back");
    }
    {
        ft::vector<int> ftVector;
        std::vector<int> stdVector;
        ft::vector<int>::size_type vectorSize = 50;

        for (ft::vector<int>::size_type i = 0; i < vectorSize; i++) {
            ftVector.push_back(42);
            stdVector.push_back(42);
        }

        ftVector.pop_back();
        stdVector.pop_back();
        ftVector.pop_back();
        stdVector.pop_back();
        ftVector.pop_back();
        stdVector.pop_back();
        ftVector.pop_back();
        stdVector.pop_back();
        ftVector.pop_back();
        stdVector.pop_back();
        ftVector.pop_back();
        stdVector.pop_back();
        ftVector.pop_back();
        stdVector.pop_back();
        ftVector.pop_back();
        stdVector.pop_back();
        ftVector.pop_back();
        stdVector.pop_back();
        ftVector.pop_back();
        stdVector.pop_back();
        ftVector.pop_back();
        stdVector.pop_back();

        my_assert(ftVector.size() == stdVector.size(), "Check size after pop_back agains std::vector");
        my_assert(ftVector.capacity() == stdVector.capacity(), "Check capacity after pop_back agains std::vector");
    }
}
