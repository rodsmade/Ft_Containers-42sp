#include "test_functions_header.hpp"

void test_allocator(void) {
    std::cout << "\n=== Test get_allocator() ===" << std::endl;

    ft::vector<unsigned int> myvector;
    unsigned int * p;
    unsigned int i;

    // allocate an array with space for 5 elements using vector's allocator:
    try {
        p = myvector.get_allocator().allocate(5);
        assert(true, "Allocation using get_allocator()");
    } catch(const std::exception& e) {
        assert(false, "Allocation using get_allocator()");
        std::cerr << e.what() << '\n';
    }

    // construct values in-place on the array:
    try {
        for (i = 0; i < 5; i++)
            myvector.get_allocator().construct(&p[i], i);
        assert(true, "Construction using get_allocator()");
    } catch(const std::exception& e) {
        assert(false, "Construction using get_allocator()");
        std::cerr << e.what() << '\n';
    }

    // integrity check:
    bool integrityCheck = true;
    for (i = 0; i < 5; i++)
        integrityCheck = integrityCheck && (p[i] == i);
    assert(integrityCheck, "Integrity check of elements created using get_allocator()");

    // destroy:
    try {
        for (i = 0; i < 5; i++)
            myvector.get_allocator().destroy(&p[i]);
        assert(true, "Destruction using get_allocator()");
    } catch(const std::exception& e) {
        assert(false, "Destruction using get_allocator()");
        std::cerr << e.what() << '\n';
    }

    // deallocate:
    try {
        myvector.get_allocator().deallocate(p, 5);
        assert(true, "Deallocation using get_allocator()");
    } catch(const std::exception& e) {
        assert(false, "Deallocation using get_allocator()");
        std::cerr << e.what() << '\n';
    }

    return ;
}
