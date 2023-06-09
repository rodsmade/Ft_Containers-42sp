// iterator_traits example
#include <iostream>     // std::cout
#include <iterator>     // std::iterator_traits
#include <typeinfo>     // typeid
#include <vector>

int main() {
    if (typeid(std::iterator_traits<int*>::iterator_category)==typeid(std::random_access_iterator_tag))
        std::cout << "int* is a random-access iterator";
    return 0;

    std::vector<int> myVec(42);

    for (int i = 0; i < 42; i++)
        myVec.push_back(i);

    std::iterator_traits<int*> myIt = myVec.begin();

}
