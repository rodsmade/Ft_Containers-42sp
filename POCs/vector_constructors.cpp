#include <vector>
#include <iostream>
#include <climits>

// int main() {
//     std::vector<char> test;
//     std::cout << test.max_size() << std::endl;
//     std::cout << LONG_MAX << std::endl;
//     std::cout << INT_MAX << std::endl;
    
//     std::vector<char> test2(-1);
//     std::cout << test2.size() << std::endl;
//     std::cout << test2.capacity() << std::endl;
// }

struct No_default {
    int _value;
    No_default(int arg) {
        _value = arg;
    };  // the only constructor for No_default
};

int main() {
    std::vector<No_default> teste;
    std::vector<No_default> teste2(10);
}