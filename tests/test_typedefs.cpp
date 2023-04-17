#include "tests_headers.hpp"

template <typename T, typename U>
void test_type_equality(std::string typeName) {
    (is_same<T, U>::value)
        ? (std::cout << TEST_OK)
        : (std::cout << TEST_NOK);
    std::cout << typeName << std::endl;
}

void test_typedefs(void) {
    std::cout << "=== Typedefs comparison ===" << std::endl;
    test_type_equality<ft::vector<int>::size_type, std::vector<int>::size_type>("size_type");
    test_type_equality<ft::vector<int>::value_type, std::vector<int>::value_type>("value_type");
    test_type_equality<ft::vector<int>::reference, std::vector<int>::reference>("reference");
    test_type_equality<ft::vector<int>::const_reference, std::vector<int>::const_reference>("const_reference");
    test_type_equality<ft::vector<int>::iterator, std::vector<int>::iterator>("iterator");
    test_type_equality<ft::vector<int>::const_iterator, std::vector<int>::const_iterator>("const_iterator");
    test_type_equality<ft::vector<int>::reverse_iterator, std::vector<int>::reverse_iterator>("reverse_iterator");
    test_type_equality<ft::vector<int>::const_reverse_iterator, std::vector<int>::const_reverse_iterator>("const_reverse_iterator");
}