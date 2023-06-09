#include <iostream>

class Node {
   public:
    int     *content;
    Node    *next;

    Node() : content(NULL), next(NULL) {};
};

// Custom data structure
class MyList {
private:
    Node *firstLinkInTheChain;

public:
    // Iterator for custom data structure
    class iterator {
    private:
        int *current;  // pointer to current element

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

    MyList() {
        firstLinkInTheChain = NULL;
    }

    iterator begin() {
        // Return the iterator pointing to the beginning of your custom data structure
        // Example: Return the iterator initialized to the first element of your structure
        return iterator(firstLinkInTheChain->content);
    }

    iterator end() {
        // Return the iterator pointing to the end of your custom data structure
        // Example: Return the iterator initialized to one past the last element of your structure
        
        
        while (firstLinkInTheChain)
        
        return iterator(&data[5]);
    }
};

int main() {
    MyList myData;

    // Traverse the custom data structure using custom iterators
    for (MyList::iterator it = myData.begin(); it != myData.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
