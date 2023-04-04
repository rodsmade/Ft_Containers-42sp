#include <iostream>
#include <vector>

int main() {
    // {  // test 0:
    //     std::cout << "\n=== TEST 0:" << std::endl;
    //     for (int i = 0; i < 50; i++) {
    //         std::vector<int> *edu = new std::vector<int>(i + 5);
    //         std::cout << (edu->size() == edu->capacity()) << std::endl;
    //     }
    // }  // conclusão: size sempre vai ser igual ao capacity.

    {  // test 1: push_back size/capacity
        std::cout << "\n=== TEST 1: push_back size/capacity" << std::endl;
        int *begin;
        std::vector<int> van;

        for (int i = 0; i < 20; i++) {
            van.push_back(1);
            begin = &van[0];
            std::cout << "begins at: " << begin << "; " << van.size() << " (size), " << van.capacity() << " (capacity)" << std::endl;
        }
    }

    {  // test 2: reserve
        std::cout << "\n=== TEST 2: reserve" << std::endl;
        std::vector<int> edu = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int *begin;

        begin = &edu[0];
        std::cout << "original (10 elems):\n"
                  << "  begins at: " << begin << "; " << edu.size() << " (size), " << edu.capacity() << " (capacity)" << std::endl;

        edu.reserve(5);
        begin = &edu[0];
        std::cout << "reserve to lesser (5 elems)\n"
                  << "  begins at: " << begin << "; " << edu.size() << " (size), " << edu.capacity() << " (capacity)" << std::endl;

        edu.reserve(35);
        begin = &edu[0];
        std::cout << "reserve to greater (35 elems)\n"
                  << "  begins at: " << begin << "; " << edu.size() << " (size), " << edu.capacity() << " (capacity)" << std::endl;
    }  // conclusão: reserve não mexe no size (mesmo fazendo reserve pra baixo), só no capacity

    {  // test 3: resize
        std::cout << "\n=== TEST 3: resize" << std::endl;
        std::vector<int> rods = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int *begin;

        begin = &rods[0];
        std::cout << "original: (10 elems)\n"
                  << "  begins at: " << begin << "; " << rods.size() << " (size), " << rods.capacity() << " (capacity)" << std::endl;

        rods.resize(5);
        begin = &rods[0];
        std::cout << "resize to lesser (5 elems):\n"
                  << "  begins at: " << begin << "; " << rods.size() << " (size), " << rods.capacity() << " (capacity)" << std::endl;

        rods.resize(15);
        begin = &rods[0];
        std::cout << "resize to greater (15 elems):\n"
                  << "  begins at: " << begin << "; " << rods.size() << " (size), " << rods.capacity() << " (capacity)" << std::endl;
    }

    {  // test 4: resize
        std::cout << "\n=== TEST 4: resize" << std::endl;
        std::vector<int> lula = {1, 2, 3, 4, 5};
        int *begin;

        std::cout << " -- original (5 elems) --" << std::endl;
        begin = &lula[0];
        std::cout << begin << ": ";
        for (unsigned int i = 0; i < lula.capacity(); i++)
            std::cout << lula[i] << " ";
        std::cout << std::endl;

        begin = &lula[0];
        std::cout << begin << ": ";
        for (unsigned int i = 0; i < lula.size(); i++)
            std::cout << lula[i] << " ";
        std::cout << std::endl;

        lula.reserve(3);
        std::cout << " -- after reserve to lesser (3 elems) --" << std::endl;

        begin = &lula[0];
        std::cout << begin << ": ";
        for (unsigned int i = 0; i < lula.capacity(); i++)
            std::cout << lula[i] << " ";
        std::cout << std::endl;
        begin = &lula[0];
        std::cout << begin << ": ";
        for (unsigned int i = 0; i < lula.size(); i++)
            std::cout << lula[i] << " ";
        std::cout << std::endl;

        lula.resize(3);
        std::cout << " -- after resize to lesser (3 elems) --" << std::endl;

        begin = &lula[0];
        std::cout << begin << ": ";
        for (unsigned int i = 0; i < lula.capacity(); i++)
            std::cout << lula[i] << " ";
        std::cout << std::endl;
        begin = &lula[0];
        std::cout << begin << ": ";
        for (unsigned int i = 0; i < lula.size(); i++)
            std::cout << lula[i] << " ";
        std::cout << std::endl;

        lula.reserve(20);
        std::cout << " -- after reserve to greater (20 elems) --" << std::endl;

        begin = &lula[0];
        std::cout << begin << ": ";
        for (unsigned int i = 0; i < lula.capacity(); i++)
            std::cout << lula[i] << " ";
        std::cout << std::endl;
        begin = &lula[0];
        std::cout << begin << ": ";
        for (unsigned int i = 0; i < lula.size(); i++)
            std::cout << lula[i] << " ";
        std::cout << std::endl;

        lula.resize(30);
        std::cout << " -- after resize to greater (30 elems) --" << std::endl;

        begin = &lula[0];
        std::cout << begin << ": ";
        for (unsigned int i = 0; i < lula.capacity(); i++)
            std::cout << lula[i] << " ";
        std::cout << std::endl;
        begin = &lula[0];
        std::cout << begin << ": ";
        for (unsigned int i = 0; i < lula.size(); i++)
            std::cout << lula[i] << " ";
        std::cout << std::endl;

    }  // conclusão: o size no reserve p/ baixo não muda, mas o size no resize p/ baixo muda. no entanto, não acontece nenhum free!! o capacity permanece o mesmo e os elementos q tinham sido alocados continuam lá, porém mascarados pela alteração do valor de size
}