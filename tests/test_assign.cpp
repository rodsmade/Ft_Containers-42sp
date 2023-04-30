#include "test_functions_header.hpp"

void test_assign(void) {
    std::cout << "\n=== Testing vector assignment ===" << std::endl;
    {  // assign by fill version ( assign (size_type n, const value_type& val) )
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
    {  // assign by fill version ( assign (size_type n, const value_type& val) )
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
    {  // assign by fill version ( assign (size_type n, const value_type& val) )
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
    return ;
}