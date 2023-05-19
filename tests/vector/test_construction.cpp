#include "vector_tests_header.hpp"

template <typename T>
static void test_empty_vector_creation(std::string typeName) {
    try {
        ft::vector<T> ftVector;

        assert(ftVector.size() == 0 && ftVector.capacity() == 0 && ftVector.empty(), "Empty ft::vector<" + typeName + "> creation");
    } catch (const std::exception& e) {
        std::cout << TEST_NOK << e.what() << std::endl;
    }
}

template <typename T>
static void test_against_std_empty_vector_creation(std::string typeName) {
    try {
        ft::vector<T> ftVector;
        std::vector<T> stdVector;

        assert(ftVector.size() == stdVector.size() && ftVector.capacity() == stdVector.capacity() && ftVector.empty() == stdVector.empty(), "Empty ft::vector<" + typeName + "> against empty std::vector<" + typeName + "> creation");
    } catch (const std::exception& e) {
        std::cout << TEST_NOK << e.what() << std::endl;
    }
}

static void test_default_constructor(void) {
    std::cout << "  Default Constructor ==>\tvector<T, A>(void):" << std::endl;
    test_empty_vector_creation<double>("double");
    test_empty_vector_creation<float>("float");
    test_empty_vector_creation<std::string>("std::string");
    test_empty_vector_creation<ft::vector<double> >("ft::vector<double>");
    test_empty_vector_creation<Has_default>("Has_default");
    test_empty_vector_creation<No_default>("No_default");
    test_against_std_empty_vector_creation<double>("double");
    test_against_std_empty_vector_creation<float>("float");
    test_against_std_empty_vector_creation<std::string>("std::string");
    test_against_std_empty_vector_creation<ft::vector<double> >("ft::vector<double>");
    test_against_std_empty_vector_creation<Has_default>("Has_default");
    test_against_std_empty_vector_creation<No_default>("No_default");
}

static void test_size_type_constructor(void) {
    std::cout << "\n  Size_type Constructor ==>\tvector<T, A>(size_type size):" << std::endl;
    {
        ft::vector<double>::size_type intendedSize = 42;
        ft::vector<double> ftVector(intendedSize);
        std::vector<double> stdVector(intendedSize);

        std::stringstream ss;
        ss << "Creating vector of doubles with size " << intendedSize;
        assert(ftVector.size() == intendedSize, ss.str());
        assert(ftVector.size() == stdVector.size(), "Checking ft::vector size against std::vector size");
        assert(ftVector.capacity() == stdVector.capacity(), "Checking ft::vector capacity against std::vector capacity");
    }
    {
        ft::vector<double>::size_type intendedSize = 0;
        ft::vector<double> ftVector(intendedSize);
        std::vector<double> stdVector(intendedSize);

        std::stringstream ss;
        ss << "Creating vector of doubles with size " << intendedSize;
        assert(ftVector.size() == intendedSize, ss.str());
        assert(ftVector.size() == stdVector.size(), "Checking size of ft::vector<double> upon creation against std::vector<double>");
        assert(ftVector.capacity() == stdVector.capacity(), "Checking capacity of ft::vector<double> upon creation against std::vector<double>");
    }
    {
        ft::vector<double>::size_type intendedSize = 10000;
        ft::vector<double> ftVector(intendedSize);
        std::vector<double> stdVector(intendedSize);

        std::stringstream ss;
        ss << "Creating vector of doubles with size " << intendedSize;
        assert(ftVector.size() == intendedSize, ss.str());
        assert(ftVector.size() == stdVector.size(), "Checking size of ft::vector<double> upon creation against std::vector<double>");
        assert(ftVector.capacity() == stdVector.capacity(), "Checking capacity of ft::vector<double> upon creation against std::vector<double>");
    }
    {
        std::string ftExceptionMessage;
        std::string stdExceptionMessage;
        try {
            ft::vector<double>::size_type intendedSize = -1;
            ft::vector<double> ftVector(intendedSize);
            std::cout << TEST_NOK;
        } catch (const std::exception& e) {
            std::cout << TEST_OK;
            ftExceptionMessage = e.what();
        }
        std::cout << "Invalid creation size (greater than max_size())" << std::endl;

        try {
            std::vector<double>::size_type intendedSize = -1;
            std::vector<double> stdVector(intendedSize);
        } catch (const std::exception& e) {
            stdExceptionMessage = e.what();
        }
        assert(ftExceptionMessage == stdExceptionMessage, "Invalid creation size exception message check against std::vector");
    }
}

static void test_initialisation_value_constructor(void) {
    std::cout << "\n  Initialization value Constructor ==>\tvector(size_type size, const_reference value):" << std::endl;
    {
        ft::vector<double>::size_type intendedSize = 42;
        double value = 42.0;
        ft::vector<double> ftVector(intendedSize, value);

        bool integrityCheck = true;

        for (ft::vector<double>::size_type i = 0; i < intendedSize; i++)
            integrityCheck = integrityCheck && (ftVector.at(i) == value);

        assert(integrityCheck, "Integrity check for vector<double> constructor that receives initialisation value as arg");
    }
    {
        ft::vector<No_default>::size_type intendedSize = 42;
        No_default value(10);
        ft::vector<No_default> ftVector(intendedSize, value);

        bool integrityCheck = true;

        for (ft::vector<No_default>::size_type i = 0; i < intendedSize; i++)
            integrityCheck = integrityCheck && (ftVector.at(i) == value);

        assert(integrityCheck, "Integrity check for vector<No_default> constructor that receives initialisation value as arg");
    }
};

static void test_allocator_arg_constructor(void) {
    std::cout << "\n  Allocator Constructor ==>\tvector(const allocator_type& alloc):" << std::endl;
    
    ft::vector<int> intVector;

    ft::vector<char> charVector(intVector.get_allocator());

    charVector.push_back('H');
    charVector.push_back('E');
    charVector.push_back('N');
    charVector.push_back('L');
    charVector.push_back('O');

    charVector.resize(11);

    charVector.at(5) = ' ';
    charVector.at(6) = 'w';
    charVector.at(7) = 'o';
    charVector.at(8) = 'r';
    charVector.at(9) = 'l';
    charVector.at(10) = 'd';

    std::string msg("HENLO world");

    bool integrityCheck = true;

    for (int i = 0; i < 11; i++)
        integrityCheck = integrityCheck && (charVector.at((ft::vector<char>::size_type) i) == msg[i]);

    assert(integrityCheck, "Manipulation of vector of chars created passing an int allocator as argument");
}

static void test_triple_args_constructor(void) {
    std::cout << "\n  Triple args Constructor ==>\tvector(size_type size, const_reference value, const allocator_type& allocator):" << std::endl;
    {
        ft::vector<int> intVector;
        ft::vector<char>::size_type intendedSize = 42;
        char value = 42;
        ft::vector<char> ftVector(intendedSize, value, intVector.get_allocator());

        bool integrityCheck = true;

        for (ft::vector<double>::size_type i = 0; i < intendedSize; i++)
            integrityCheck = integrityCheck && (ftVector.at(i) == value);

        assert(integrityCheck, "Integrity check for vector<char> constructor that receives initialisation value as arg and allocator of a vector<int>");
    }
}

static void test_range_constructor(void) {
    std::cout << "\n  Range Constructor ==>\tvector(InputIt first, InputIt last, const allocator_type& allocator = allocator_type()):" << std::endl;
    ft::vector<double> baseVector(42);
    for (int i = 0; i < 42; i++)
        baseVector.at(i) = (i + 1) * 42.0;
    {
        ft::vector<double> newVector(baseVector.begin(), baseVector.end());

        assert(newVector == baseVector, "New vector copies full range of base vector");
    }
    {
        ft::vector<double> newVector(baseVector.begin(), baseVector.begin() + 10);

        bool consistencyCheck = true;

        for (ft::vector<double>::size_type i = 0; i < newVector.size(); i++)
            consistencyCheck = consistencyCheck && (newVector.at(i) == baseVector.at(i));

        assert(newVector.size() == 10 && consistencyCheck, "New vector partially copies base vector from the beginning");
    }
    {
        ft::vector<double> newVector(baseVector.end() - 10, baseVector.end());

        bool consistencyCheck = true;

        for (ft::vector<double>::size_type i = 0; i < newVector.size(); i++)
            consistencyCheck = consistencyCheck && (newVector.at(i) == baseVector.at(baseVector.size() - 10 + i));

        assert(newVector.size() == 10 && consistencyCheck, "New vector partially copies the tail of the vector");
    }
    {
        ft::vector<double> newVector(baseVector.begin(), baseVector.begin());

        assert(newVector.empty() == true, "New vector out of two equal iterators is empty");
    }

}

static void test_copy_constructor() {
    std::cout << "\n  Copy Constructor ==>\tvector(const vector& other):" << std::endl;

    ft::vector<double>::size_type intendedSize = 42;
    ft::vector<double> testVector(intendedSize);
    ft::vector<double> copyVector(testVector);

    bool elementsTest = true;

    assert(copyVector.size() == testVector.size(), "Copy constructor size check");
    assert(copyVector.capacity() == testVector.capacity(), "Copy constructor capacity check");

    for (unsigned int i = 0; i < copyVector.size(); i++) {
        if (copyVector[i] != testVector[i]) {
            elementsTest = false;
            break;
        }
    }
    assert(elementsTest, "Copied elements assertion check");

    testVector[0] = 42.0;
    copyVector[1] = 1.0;

    assert(testVector[0] != copyVector[0] && testVector[1] != copyVector[1], "Test for hard copy");
};

void test_vector_construction(void) {
    std::cout << "\n=== Vector Construction ===" << std::endl;
    test_default_constructor();
    test_size_type_constructor();
    test_initialisation_value_constructor();
    test_allocator_arg_constructor();
    test_triple_args_constructor();
    test_range_constructor();
    test_copy_constructor();
}
