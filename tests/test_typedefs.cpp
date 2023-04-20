#include "test_functions_header.hpp"

void test_typedefs(void) {
    std::cout << "\n=== Typedefs comparison ===" << std::endl;
    assert(is_same<ft::vector<int>::size_type, std::vector<int>::size_type>::value, "size_type");
    assert(is_same<ft::vector<int>::value_type, std::vector<int>::value_type>::value, "value_type");
    assert(is_same<ft::vector<int>::reference, std::vector<int>::reference>::value, "reference");
    assert(is_same<ft::vector<int>::const_reference, std::vector<int>::const_reference>::value, "const_reference");
    assert(is_same<ft::vector<int>::iterator, std::vector<int>::iterator>::value, "iterator");
    assert(is_same<ft::vector<int>::const_iterator, std::vector<int>::const_iterator>::value, "const_iterator");
    assert(is_same<ft::vector<int>::reverse_iterator, std::vector<int>::reverse_iterator>::value, "reverse_iterator");
    assert(is_same<ft::vector<int>::const_reverse_iterator, std::vector<int>::const_reverse_iterator>::value, "const_reverse_iterator");
}