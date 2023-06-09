#include <iostream>

// Custom data structure
class MyDataStructure {
private:
    int data[7];

public:
    // Iterator for custom data structure
    class iterator {
    private:
        int* current;  // pointer to current element

    public:
        explicit iterator(int* ptr) : current(ptr) {}

        iterator& operator++() {
            // Increment the iterator logic based on your data structure
            // Example: Move to the next element in your custom structure
            // You'll need to define the specific logic for your data structure here

            // For demonstration, let's increment by 2 positions in the array
            current += 2;

            return *this;
        }

        int& operator*() const {
            return *current;
        }

        bool operator!=(const iterator& other) const {
            return current != other.current;
        }
    };

    MyDataStructure() {
        data[0] = 1;
        data[1] = 2;
        data[2] = 3;
        data[3] = 4;
        data[4] = 5;
        data[5] = 6;
        data[6] = 7;
    }

    iterator begin() {
        // Return the iterator pointing to the beginning of your custom data structure
        // Example: Return the iterator initialized to the first element of your structure
        return iterator(&data[0]);
    }

    iterator end() {
        // Return the iterator pointing to the end of your custom data structure
        // Example: Return the iterator initialized to one past the last element of your structure
        return iterator(&data[5]);
    }
};

int main() {
    MyDataStructure myData;

    // Traverse the custom data structure using custom iterators
    for (MyDataStructure::iterator it = myData.begin(); it != myData.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
