#include <iostream>
#include <vector>

int main() {
    // // test 1:
    // for (int i = 0; i < 50; i++) {
    //     std::vector<int> *edu = new std::vector<int>(i+5);
    //     std::cout << (edu->size() == edu->capacity()) << std::endl;
    // }
    // conclusão: size sempre vai ser igual ao capacity.

    // test 2: reserve
    std::vector<int> edu = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << edu.size() << ", " << edu.capacity() << std::endl;
    edu.reserve(5);
    std::cout << edu.size() << ", " << edu.capacity() << std::endl;
    edu.reserve(15);
    std::cout << edu.size() << ", " << edu.capacity() << std::endl;

    // test 3: resize
    std::vector<int> rods = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << rods.size() << ", " << rods.capacity() << std::endl;
    rods.resize(5);
    std::cout << rods.size() << ", " << rods.capacity() << std::endl;
    rods.resize(15);
    std::cout << rods.size() << ", " << rods.capacity() << std::endl;

    // test 4: resize
    int *begin;
    std::vector<int> lula = {1, 2, 3, 4, 5};
    begin = &lula[0];
    std::cout << begin << ": ";
    for (int i = 0; i < lula.capacity(); i++)
        std::cout << lula[i] << " ";
    std::cout << std::endl;
    begin = &lula[0];
    std::cout << begin << ": ";
    for (int i = 0; i < lula.size(); i++)
        std::cout << lula[i] << " ";
    std::cout << std::endl;
    lula.reserve(3);
    begin = &lula[0];
    std::cout << begin << ": ";
    for (int i = 0; i < lula.capacity(); i++)
        std::cout << lula[i] << " ";
    std::cout << std::endl;
    begin = &lula[0];
    std::cout << begin << ": ";
    for (int i = 0; i < lula.size(); i++)
        std::cout << lula[i] << " ";
    std::cout << std::endl;

    // conclusão: o size no reserve não muda, mas o size no resize muda (quando alocando pra mais, quando aloca pra mais ou pra menos)
}