#include <iostream>
#include <memory> // for std::allocator

int main() {
    std::allocator<int> alloc; // create an allocator for integers

    // allocate memory for an array of 5 integers
    int* arr = alloc.allocate(5);

    // construct the elements of the array
    for (int i = 0; i < 5; i++) {
        alloc.construct(&arr[i], i);
    }

    // print the elements of the array
    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // destruct the elements of the array
    for (int i = 0; i < 5; i++) {
        alloc.destroy(&arr[i]);
    }

    // deallocate the memory
    alloc.deallocate(arr, 5);

    return 0;
}