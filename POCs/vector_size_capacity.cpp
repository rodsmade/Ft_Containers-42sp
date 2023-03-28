#include <iostream>
#include <vector>

int main() {
    
    for (int i = 0; i < 50; i++) {
        std::vector<int> *edu = new std::vector<int>(i+5);
        std::cout << (edu->size() == edu->capacity()) << std::endl;
    }

    // conclusão: size sempre vai ser igual ao capacity.
}