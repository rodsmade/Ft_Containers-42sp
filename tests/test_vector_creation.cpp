#include "tests_headers.hpp"

template <typename T>
void test_empty_vector_creation(std::string typeName) {
    try {
        ft::vector<T> ftVector;

        if (ftVector.size() != 0 || ftVector.capacity() != 0 || !ftVector.empty())
            std::cout << TEST_NOK;
        else
            std::cout << TEST_OK;
        std::cout << "Empty ft::vector<" << typeName << "> creation" << std::endl;
    } catch (const std::exception& e) {
        std::cout << TEST_NOK << e.what() << std::endl;
    }
}

template <typename T>
void test_against_std_vector(std::string typeName) {
    try {
        ft::vector<T> ftVector;
        std::vector<T> stdVector;

        if (ftVector.size() != stdVector.size() || ftVector.capacity() != stdVector.capacity() || ftVector.empty() != stdVector.empty())
            std::cout << TEST_NOK;
        else
            std::cout << TEST_OK;
        std::cout << "Empty ft::vector<" << typeName << "> against empty std::vector<" << typeName << "> creation" << std::endl;
    } catch (const std::exception& e) {
        std::cout << TEST_NOK << e.what() << std::endl;
    }
}

void test_vector_creation(void) {
    std::cout << "=== Vector creation ===" << std::endl;
    std::cout << "Empty vector creation:" << std::endl;
    test_empty_vector_creation<double>("double");
    test_empty_vector_creation<float>("float");
    test_empty_vector_creation<std::string>("std::string");
    test_empty_vector_creation<ft::vector<double> >("ft::vector<double>");
    test_empty_vector_creation<Has_default>("Has_default");
    test_empty_vector_creation<No_default>("No_default");
    std::cout << "\nTesting against STL's vector:" << std::endl;
    test_against_std_vector<double>("double");
    test_against_std_vector<float>("float");
    test_against_std_vector<std::string>("std::string");
    test_against_std_vector<ft::vector<double> >("ft::vector<double>");
    test_against_std_vector<Has_default>("Has_default");
    test_against_std_vector<No_default>("No_default");
}
