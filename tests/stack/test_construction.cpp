#include "stack_tests_header.hpp"

template <typename T>
static void test_empty_stack_creation(std::string typeName) {
    try {
        ft::stack<T> ftStack;

        assert(true, "Empty ft::stack<" + typeName + "> creation");
    } catch (const std::exception& e) {
        std::cout << TEST_NOK << e.what() << std::endl;
    }
}

// template <typename T>
// static void test_against_std_empty_stack_creation(std::string typeName) {
//     try {
//         ft::stack<T> ftStack;
//         std::stack<T> stdStack;

//         assert(ftStack.size() == stdStack.size() && ftStack.capacity() == stdStack.capacity() && ftStack.empty() == stdStack.empty(), "Empty ft::stack<" + typeName + "> against empty std::stack<" + typeName + "> creation");
//     } catch (const std::exception& e) {
//         std::cout << TEST_NOK << e.what() << std::endl;
//     }
// }

static void test_default_constructor(void) {
    std::cout << "  Default Constructor ==>\tstack<T, A>(void):" << std::endl;
    test_empty_stack_creation<double>("double");
    // test_empty_stack_creation<float>("float");
    // test_empty_stack_creation<std::string>("std::string");
    // test_empty_stack_creation<ft::stack<double> >("ft::stack<double>");
    // test_empty_stack_creation<Has_default>("Has_default");
    // test_empty_stack_creation<No_default>("No_default");
    // test_against_std_empty_stack_creation<double>("double");
    // test_against_std_empty_stack_creation<float>("float");
    // test_against_std_empty_stack_creation<std::string>("std::string");
    // test_against_std_empty_stack_creation<ft::stack<double> >("ft::stack<double>");
    // test_against_std_empty_stack_creation<Has_default>("Has_default");
    // test_against_std_empty_stack_creation<No_default>("No_default");
}

void test_stack_construction(void) {
    test_default_constructor();
    return ;
}

////////////////////////////////////////////////////////////////////////////////////

// static void test_size_type_constructor(void) {
//     std::cout << "\n  Size_type Constructor ==>\tstack<T, A>(size_type size):" << std::endl;
//     {
//         ft::stack<double>::size_type intendedSize = 42;
//         ft::stack<double> ftStack(intendedSize);
//         std::stack<double> stdStack(intendedSize);

//         std::stringstream ss;
//         ss << "Creating stack of doubles with size " << intendedSize;
//         assert(ftStack.size() == intendedSize, ss.str());
//         assert(ftStack.size() == stdStack.size(), "Checking ft::stack size against std::stack size");
//         assert(ftStack.capacity() == stdStack.capacity(), "Checking ft::stack capacity against std::stack capacity");
//     }
//     {
//         ft::stack<double>::size_type intendedSize = 0;
//         ft::stack<double> ftStack(intendedSize);
//         std::stack<double> stdStack(intendedSize);

//         std::stringstream ss;
//         ss << "Creating stack of doubles with size " << intendedSize;
//         assert(ftStack.size() == intendedSize, ss.str());
//         assert(ftStack.size() == stdStack.size(), "Checking size of ft::stack<double> upon creation against std::stack<double>");
//         assert(ftStack.capacity() == stdStack.capacity(), "Checking capacity of ft::stack<double> upon creation against std::stack<double>");
//     }
//     {
//         ft::stack<double>::size_type intendedSize = 10000;
//         ft::stack<double> ftStack(intendedSize);
//         std::stack<double> stdStack(intendedSize);

//         std::stringstream ss;
//         ss << "Creating stack of doubles with size " << intendedSize;
//         assert(ftStack.size() == intendedSize, ss.str());
//         assert(ftStack.size() == stdStack.size(), "Checking size of ft::stack<double> upon creation against std::stack<double>");
//         assert(ftStack.capacity() == stdStack.capacity(), "Checking capacity of ft::stack<double> upon creation against std::stack<double>");
//     }
//     {
//         std::string ftExceptionMessage;
//         std::string stdExceptionMessage;
//         try {
//             ft::stack<double>::size_type intendedSize = -1;
//             ft::stack<double> ftStack(intendedSize);
//             std::cout << TEST_NOK;
//         } catch (const std::exception& e) {
//             std::cout << TEST_OK;
//             ftExceptionMessage = e.what();
//         }
//         std::cout << "Invalid creation size (greater than max_size())" << std::endl;

//         try {
//             std::stack<double>::size_type intendedSize = -1;
//             std::stack<double> stdStack(intendedSize);
//         } catch (const std::exception& e) {
//             stdExceptionMessage = e.what();
//         }
//         assert(ftExceptionMessage == stdExceptionMessage, "Invalid creation size exception message check against std::stack");
//     }
// }

// static void test_initialisation_value_constructor(void) {
//     std::cout << "\n  Initialization value Constructor ==>\tstack(size_type size, const_reference value):" << std::endl;
//     {
//         ft::stack<double>::size_type intendedSize = 42;
//         double value = 42.0;
//         ft::stack<double> ftStack(intendedSize, value);

//         bool integrityCheck = true;

//         for (ft::stack<double>::size_type i = 0; i < intendedSize; i++)
//             integrityCheck = integrityCheck && (ftStack.at(i) == value);

//         assert(integrityCheck, "Integrity check for stack<double> constructor that receives initialisation value as arg");
//     }
//     {
//         ft::stack<No_default>::size_type intendedSize = 42;
//         No_default value(10);
//         ft::stack<No_default> ftStack(intendedSize, value);

//         bool integrityCheck = true;

//         for (ft::stack<No_default>::size_type i = 0; i < intendedSize; i++)
//             integrityCheck = integrityCheck && (ftStack.at(i) == value);

//         assert(integrityCheck, "Integrity check for stack<No_default> constructor that receives initialisation value as arg");
//     }
// };

// static void test_allocator_arg_constructor(void) {
//     std::cout << "\n  Allocator Constructor ==>\tstack(const allocator_type& alloc):" << std::endl;
    
//     ft::stack<int> intStack;

//     ft::stack<char> charStack(intStack.get_allocator());

//     charStack.push_back('H');
//     charStack.push_back('E');
//     charStack.push_back('N');
//     charStack.push_back('L');
//     charStack.push_back('O');

//     charStack.resize(11);

//     charStack.at(5) = ' ';
//     charStack.at(6) = 'w';
//     charStack.at(7) = 'o';
//     charStack.at(8) = 'r';
//     charStack.at(9) = 'l';
//     charStack.at(10) = 'd';

//     std::string msg("HENLO world");

//     bool integrityCheck = true;

//     for (int i = 0; i < 11; i++)
//         integrityCheck = integrityCheck && (charStack.at((ft::stack<char>::size_type) i) == msg[i]);

//     assert(integrityCheck, "Manipulation of stack of chars created passing an int allocator as argument");
// }

// static void test_triple_args_constructor(void) {
//     std::cout << "\n  Triple args Constructor ==>\tstack(size_type size, const_reference value, const allocator_type& allocator):" << std::endl;
//     {
//         ft::stack<int> intStack;
//         ft::stack<char>::size_type intendedSize = 42;
//         char value = 42;
//         ft::stack<char> ftStack(intendedSize, value, intStack.get_allocator());

//         bool integrityCheck = true;

//         for (ft::stack<double>::size_type i = 0; i < intendedSize; i++)
//             integrityCheck = integrityCheck && (ftStack.at(i) == value);

//         assert(integrityCheck, "Integrity check for stack<char> constructor that receives initialisation value as arg and allocator of a stack<int>");
//     }
// }

// static void test_range_constructor(void) {
//     std::cout << "\n  Range Constructor ==>\tstack(InputIt first, InputIt last, const allocator_type& allocator = allocator_type()):" << std::endl;
//     ft::stack<double> baseStack(42);
//     for (int i = 0; i < 42; i++)
//         baseStack.at(i) = (i + 1) * 42.0;
//     {
//         ft::stack<double> newStack(baseStack.begin(), baseStack.end());

//         assert(newStack == baseStack, "New stack copies full range of base stack");
//     }
//     {
//         ft::stack<double> newStack(baseStack.begin(), baseStack.begin() + 10);

//         bool consistencyCheck = true;

//         for (ft::stack<double>::size_type i = 0; i < newStack.size(); i++)
//             consistencyCheck = consistencyCheck && (newStack.at(i) == baseStack.at(i));

//         assert(newStack.size() == 10 && consistencyCheck, "New stack partially copies base stack from the beginning");
//     }
//     {
//         ft::stack<double> newStack(baseStack.end() - 10, baseStack.end());

//         bool consistencyCheck = true;

//         for (ft::stack<double>::size_type i = 0; i < newStack.size(); i++)
//             consistencyCheck = consistencyCheck && (newStack.at(i) == baseStack.at(baseStack.size() - 10 + i));

//         assert(newStack.size() == 10 && consistencyCheck, "New stack partially copies the tail of the stack");
//     }
//     {
//         ft::stack<double> newStack(baseStack.begin(), baseStack.begin());

//         assert(newStack.empty() == true, "New stack out of two equal iterators is empty");
//     }

// }

// static void test_copy_constructor() {
//     std::cout << "\n  Copy Constructor ==>\tstack(const stack& other):" << std::endl;

//     ft::stack<double>::size_type intendedSize = 42;
//     ft::stack<double> testStack(intendedSize);
//     ft::stack<double> copyStack(testStack);

//     bool elementsTest = true;

//     assert(copyStack.size() == testStack.size(), "Copy constructor size check");
//     assert(copyStack.capacity() == testStack.capacity(), "Copy constructor capacity check");

//     for (unsigned int i = 0; i < copyStack.size(); i++) {
//         if (copyStack[i] != testStack[i]) {
//             elementsTest = false;
//             break;
//         }
//     }
//     assert(elementsTest, "Copied elements assertion check");

//     testStack[0] = 42.0;
//     copyStack[1] = 1.0;

//     assert(testStack[0] != copyStack[0] && testStack[1] != copyStack[1], "Test for hard copy");
// };

// void test_stack_construction(void) {
//     std::cout << "\n=== Stack Construction ===" << std::endl;
//     test_default_constructor();
//     test_size_type_constructor();
//     test_initialisation_value_constructor();
//     test_allocator_arg_constructor();
//     test_triple_args_constructor();
//     test_range_constructor();
//     test_copy_constructor();
// }
