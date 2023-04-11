#include <iostream>
#include <vector>

int main (){

    std::vector<double> beb;

    std::cout << "send help" << std::endl;
    std::cout << (sizeof(std::vector<double>::size_type)) << std::endl;
    std::cout << (sizeof(int)) << std::endl;
    std::cout << (sizeof(std::size_t)) << std::endl;
    std::cout << (sizeof(unsigned long)) << std::endl;

    // Conclusão: o size_type da std::vector é unsigned long, que é o mesmo que size_t
}