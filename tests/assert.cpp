#include "test_functions_header.hpp"

/*
    If `condition`, prints out TEST_OK. else, prints out TEST_NOK.
    If provided, tagline` will be printed after assertion result.
*/
void assert(bool condition, const std::string& tagline)
{
    (condition)
        ? ( std::cout << TEST_OK )
        : ( std::cout << TEST_NOK );
    std::cout << tagline << std::endl;
}