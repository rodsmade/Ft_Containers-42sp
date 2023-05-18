#include "test_functions_header.hpp"

static void test_protected_read_access(void) {
    std::vector<int> stdVector(42);
    ft::vector<int> ftVector(42);

    try {
        ftVector.at(0);
        ftVector.at(20);
        ftVector.at(41);
        assert(true, "Protected read access of valid indices");
    }
    catch(const std::exception& e)
    {
        assert(false, "Protected read access of valid indices");
        std::cerr << e.what() << std::endl;
    }

    try {
        ftVector.at(42);
        assert(false, "Protected read access of out of bound index");
    }
        catch(const std::exception& e) {
        assert(true, "Protected read access of out of bound index");
    }

    try {
        ftVector.at(-1);
        assert(false, "Protected read access of out of bound (negative) index");
    }
        catch(const std::exception& e) {
        assert(true, "Protected read access of out of bound (negative) index");
    }

}

static void test_protected_write_access(void) {
    std::vector<int> stdVector(42);
    ft::vector<int> ftVector(42);

    try {
        ftVector.at(0) = 42;
        ftVector.at(20) = 42;
        ftVector.at(41) = 42;
        assert(true, "Protected write access of valid indices");
    }
    catch(const std::exception& e)
    {
        assert(false, "Protected write access of valid indices");
        std::cerr << e.what() << std::endl;
    }

    try {
        ftVector.at(42) = 42;
        assert(false, "Protected write access of out of bound index");
    }
        catch(const std::exception& e) {
        assert(true, "Protected write access of out of bound index");
    }

    try {
        ftVector.at(-1) = 42;
        assert(false, "Protected write access of out of bound (negative) index");
    }
        catch(const std::exception& e) {
        assert(true, "Protected write access of out of bound (negative) index");
    }
}

static void test_out_of_bound_exception_msg (void) {
    std::vector<int> stdVector(42);
    ft::vector<int> ftVector(42);
    std::string ftExceptionMsg = "";
    std::string stdExceptionMsg = "";

    try {
        ftVector.at(42);
    }
    catch(const std::exception& e)
    {
        ftExceptionMsg += e.what();
    }
    try {
        stdVector.at(42);
    }
    catch(const std::exception& e)
    {
        stdExceptionMsg += e.what();
    }
    assert(ftExceptionMsg == stdExceptionMsg, "Exception message assertion");
}

static void test_unprotected_access() {
    std::vector<int> stdVector(42);
    ft::vector<int> ftVector(42);

    int intendedValue = 42;
    int valueRead;

    ftVector[0] = intendedValue;
    valueRead = ftVector[0];

    assert(valueRead == intendedValue, "Unprotected read and write access check of valid index");

    try {
        ftVector[42];
        assert(true, "Unprotected read access of invalid index");
    } catch (const std::exception& e) {
        assert(false, "Unprotected read access of invalid index");
    }

    // Unprotected write access for invalid indices won't be tested, for i do not wish to jumble up any memory.
}

void test_vector_access(void) {
    std::cout << "\n=== Test access functions ( at() && operator[] ) ===" << std::endl;

    test_protected_read_access();
    test_protected_write_access();
    test_unprotected_access();
    test_out_of_bound_exception_msg();
}
