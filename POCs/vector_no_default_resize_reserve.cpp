#include <iostream>
#include <vector>

struct No_default {
    No_default(int ay) {
        (void) ay;
    };  // the only constructor for No_default
};

int main() {
    std::vector<No_default> vetor;

    vetor.resize(10);
}