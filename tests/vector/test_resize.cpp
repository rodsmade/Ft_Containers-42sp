#include "vector_tests.hpp"

void test_vector_resize(void) {
    std::cout << "\n=== Test resize ===" << std::endl;

    ft::vector<int> ftVector(42);
    std::vector<int> stdVector(42);

    ftVector.resize(100);
    stdVector.resize(100);
    assert(ftVector.size() == stdVector.size(), "Size check against std::vector after resizing to a higher value");
    assert(ftVector.capacity() == stdVector.capacity(), "Capacity check against std::vector after resizing to a higher value");

    ftVector.resize(5);
    stdVector.resize(5);
    assert(ftVector.size() == stdVector.size(), "Size check against std::vector after resizing to a lower value");
    assert(ftVector.capacity() == stdVector.capacity(), "Capacity check against std::vector after resizing to a lower value");

    {
        ft::vector<int>::size_type oldSize = 42;
        ft::vector<int>::size_type newSize = 50;

        ft::vector<int> ftVector(oldSize);
        ft::vector<int> oldFtVector = ftVector;

        ftVector.resize(newSize);

        bool integrityCheck = true;
        bool initialisationCheck = true;

        for (ft::vector<int>::size_type i = 0; i < oldSize; i++)
            integrityCheck = integrityCheck && (ftVector.at(i) == oldFtVector.at(i));
        for (ft::vector<int>::size_type i = oldSize; i < newSize; i++)
            initialisationCheck = initialisationCheck && (ftVector.at(i) == int());

        assert(integrityCheck, "Integrity of values after resizing to a greater value");
        assert(initialisationCheck, "Initialization of values past old vector size, after resizing to a greater value");
    }
    {
        ft::vector<int>::size_type oldSize = 42;
        ft::vector<int>::size_type newSize = 5;

        ft::vector<int> ftVector(oldSize);
        ft::vector<int> oldFtVector = ftVector;

        ftVector.resize(newSize);

        bool integrityCheck = true;
        bool initialisationCheck = true;

        for (ft::vector<int>::size_type i = 0; i < newSize; i++)
            integrityCheck = integrityCheck && (ftVector.at(i) == oldFtVector.at(i));
        for (ft::vector<int>::size_type i = newSize; i < oldSize; i++)
            initialisationCheck = initialisationCheck && (ftVector[i] == int());

        assert(integrityCheck, "Integrity of values after resizing to a lower value");
        assert(initialisationCheck, "Initialization of values past new vector size, after resizing to a lower value");
    }
    {
        ft::vector<double>::size_type oldSize = 42;
        ft::vector<double>::size_type newSize = 50;
        double value = 4234.9;

        ft::vector<double> ftVector(oldSize);
        ft::vector<double> oldFtVector = ftVector;

        ftVector.resize(newSize, value);

        bool initialisationCheck = true;

        for (ft::vector<double>::size_type i = oldSize; i < newSize; i++)
            initialisationCheck = initialisationCheck && (ftVector.at(i) == value);

        assert(initialisationCheck, "Initialization of values past new vector size, passing value to resize");

    }
}
