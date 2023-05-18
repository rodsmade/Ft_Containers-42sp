#include "test_functions_header.hpp"

void test_vector_assign(void) {
    std::cout << "\n=== Testing vector assignment ===" << std::endl;
    std::cout << "\n  assignment by fill ( assign (size_type n, const value_type& val) )" << std::endl;
    {  // assign by fill version ( assign (size_type n, const value_type& val) ) - Case 0 - new size equal to current capacity
        std::cout << "  Case 0 - new size equal to current capacity" << std::endl;

        double initialValue = 42.0;
        double newValue = 21.0;
        ft::vector<double>::size_type size = 42;

        ft::vector<double> ftVector(size, initialValue);
        std::vector<double> stdVector(size, initialValue);
        double initialCapacity = ftVector.capacity();

        ftVector.assign(size, newValue);
        stdVector.assign(size, newValue);

        assert(ftVector.size() == size, "Size check after assign()");
        assert(ftVector.capacity() == initialCapacity, "Capacity check after assign()");

        bool integrityCheck = true;

        for (ft::vector<double>::size_type i = 0; i < ftVector.size(); i++)
            integrityCheck = integrityCheck && (ftVector.at(i) == newValue);
        
        assert(integrityCheck, "Reassignment of vector's contents, no change in size/capacity");
        assert(ftVector.size() == stdVector.size() && ftVector.capacity() == stdVector.capacity(), "Size and capacity check against std::vector");
    }
    {  // assign by fill version ( assign (size_type n, const value_type& val) ) - Case 1 - new size less than current capacity
        std::cout << "\n  Case 1 - new size less than current capacity" << std::endl;
        double initialValue = 42.0;
        double newValue = 21.0;
        ft::vector<double>::size_type initialSize = 42;
        ft::vector<double>::size_type newSize = 21;

        ft::vector<double> ftVector(initialSize, initialValue);
        std::vector<double> stdVector(initialSize, initialValue);
        double initialCapacity = ftVector.capacity();

        ftVector.assign(newSize, newValue);
        stdVector.assign(newSize, newValue);

        assert(ftVector.size() == newSize, "Size check after assign()");
        assert(ftVector.capacity() == initialCapacity, "Capacity check after assign()");

        bool integrityCheck = true;

        for (ft::vector<double>::size_type i = 0; i < ftVector.size(); i++)
            integrityCheck = integrityCheck && (ftVector.at(i) == newValue);

        assert(integrityCheck, "Reassignment of vector's contents, new vector smaller in size than original");
        assert(ftVector.size() == stdVector.size() && ftVector.capacity() == stdVector.capacity(), "Size and capacity check against std::vector");
    }
    {  // assign by fill version ( assign (size_type n, const value_type& val) ) - Case 2 - new size greater than current capacity
        std::cout << "\n  Case 2 - new size greater than current capacity" << std::endl;
        double initialValue = 42.0;
        double newValue = 21.0;
        ft::vector<double>::size_type initialSize = 21;
        ft::vector<double>::size_type newSize = 420;

        ft::vector<double> ftVector(initialSize, initialValue);
        std::vector<double> stdVector(initialSize, initialValue);

        ftVector.assign(newSize, newValue);
        stdVector.assign(newSize, newValue);

        assert(ftVector.size() == newSize, "Size check after assign()");
        assert(ftVector.capacity() == newSize, "Capacity check after assign()");

        bool integrityCheck = true;

        for (ft::vector<double>::size_type i = 0; i < ftVector.size(); i++)
            integrityCheck = integrityCheck && (ftVector.at(i) == newValue);

        assert(integrityCheck, "Reassignment of vector's contents, new vector bigger in size than original");
        assert(ftVector.size() == stdVector.size() && ftVector.capacity() == stdVector.capacity(), "Size and capacity check against std::vector");
    }
    std::cout << "\n  assignment by range ( assign(InputIt first, InputIt last) )" << std::endl;
    {  // assign by range version ( assign(InputIt first, InputIt last) ) - Case 0 - new size equal to current capacity
        ft::vector<int> source;
        ft::vector<int>::size_type occurrences = 15;
        ft::vector<int>::value_type value = 42;
        ft::vector<int> destination(occurrences, value);

        for (int i = 0; i < 50; i++)
            source.push_back(i + 1);

        destination.assign(source.begin(), source.end());

        assert(destination.size() == source.size(), "Size check");

        bool integrityCheck = true;

        ft::vector<int>::iterator itDest = destination.begin();
        ft::vector<int>::iterator itSrc = source.begin();
        while (itDest != destination.end())
            integrityCheck = integrityCheck && (*(itDest++) == *(itSrc++));

        assert(integrityCheck, "Integrity check of elements after assignment");
    }
    return ;
}