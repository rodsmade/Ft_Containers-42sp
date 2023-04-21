#include "test_functions_header.hpp"

template <typename T>
void test_empty_vector_creation(std::string typeName) {
    try {
        ft::vector<T> ftVector;

        assert(ftVector.size() == 0
            && ftVector.capacity() == 0
            && ftVector.empty()
            , "Empty ft::vector<" + typeName + "> creation");
    } catch (const std::exception& e) {
        std::cout << TEST_NOK << e.what() << std::endl;
    }
}

template <typename T>
void test_against_std_empty_vector_creation(std::string typeName) {
    try {
        ft::vector<T> ftVector;
        std::vector<T> stdVector;

        assert(ftVector.size() == stdVector.size()
            && ftVector.capacity() == stdVector.capacity()
            && ftVector.empty() == stdVector.empty()
            , "Empty ft::vector<" + typeName + "> against empty std::vector<" + typeName + "> creation");
    } catch (const std::exception& e) {
        std::cout << TEST_NOK << e.what() << std::endl;
    }
}

void test_default_constructor(void) {
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

void test_size_type_constructor(void) {
    std::cout << "  Size_type Constructor ==>\tvector<T, A>(size_type size):" << std::endl;
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
        std::cout << "Invalid creation size" << std::endl;

        try {
            std::vector<double>::size_type intendedSize = -1;
            std::vector<double> stdVector(intendedSize);
        } catch (const std::exception& e) {
            stdExceptionMessage = e.what();
        }
        assert(ftExceptionMessage == stdExceptionMessage, "Exception message");
    }
}

void test_copy_constructor() {
    // TODO
};

void test_vector_construction(void) {
    std::cout << "\n=== Vector Construction ===" << std::endl;
    test_default_constructor();
    test_size_type_constructor();
    // TODO:
    test_copy_constructor();

}
