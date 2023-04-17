#include <iostream>
#include <vector>

int main() {
    std::vector<double> teste;
    std::cout << std::boolalpha;
    std::cout << teste.empty() << std::endl;
    teste.push_back(42);
    teste.push_back(42);
    teste.push_back(42);
    teste.push_back(42);
    teste.push_back(42);
    std::cout << teste.empty() << std::endl;
    std::cout << teste.size() << std::endl;
    std::cout << teste.capacity() << std::endl;
    teste.resize(0);
    std::cout << teste.empty() << std::endl;
    std::cout << teste.size() << std::endl;
    std::cout << teste.capacity() << std::endl;
    return 1;
}