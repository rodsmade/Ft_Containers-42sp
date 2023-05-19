#include "test_props.hpp"

/*
    If `condition`, prints out TEST_OK. else, prints out TEST_NOK.
    If provided, `tagline` will be printed after assertion result.
*/
void assert(bool condition, const std::string& tagline)
{
    (condition)
        ? ( std::cout << TEST_OK << tagline << std::endl)
        : ( std::cerr << TEST_NOK << tagline << std::endl);
}