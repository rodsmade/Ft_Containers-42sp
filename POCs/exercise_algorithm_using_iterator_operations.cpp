// Write a function void copy(int* f1, int* e1, int* f2) that copies the elements of an array of ints defined by
// [f1:e1) into another [f2:f2+(e1–f1)). Use only the iterator operations mentioned above (not subscripting).

#include <iostream>

void copy(int* begin, int* end, int* destiny) {
    while (begin != end)
    {
        *destiny  = *begin;
        begin++;
        destiny++;
    }
    return ;
}

int main() {
    int original[10] = { 1, 2, 3, 42, 45, 6, 7, 8, 9, 10};
    int copia[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    copy(&original[0], &original[10], &copia[0]);

    for (int i = 0; i < 10; i++) {
        std::cout << copia[i] << " ";
    }
    std::cout << std::endl;
}