#include <iostream>

#include "../include/BinaryTree.hpp"

class No_default {
   private:
    int _value;
   public:
    No_default(int arg) {
        _value = arg;
    };  // the only constructor for No_default
    bool operator==(const No_default& other) const {
        return (_value == other._value);
    };
    bool operator<(const No_default &other) const {
        return (_value < other._value);
    };
    bool operator>(const No_default &other) const {
        return (!(_value == other._value || _value < other._value));
    };
};

int main() {
    ft::BinaryTree<int> *myTree = new ft::BinaryTree<int>;

    myTree->insert(int(42));
    std::cout << "size: " << myTree->getSize() << " height: " << myTree->getHeight() << std::endl;
    // myTree->insert(int(42));
    // std::cout << "size: " << myTree->getSize() << " height: " << myTree->getHeight() << std::endl;
    myTree->insert(int(369));
    std::cout << "size: " << myTree->getSize() << " height: " << myTree->getHeight() << std::endl;
    myTree->insert(int(2207));
    std::cout << "size: " << myTree->getSize() << " height: " << myTree->getHeight() << std::endl;
    myTree->insert(int(52));
    std::cout << "size: " << myTree->getSize() << " height: " << myTree->getHeight() << std::endl;
    myTree->insert(int(1));
    std::cout << "size: " << myTree->getSize() << " height: " << myTree->getHeight() << std::endl;
    myTree->insert(int(37));
    std::cout << "size: " << myTree->getSize() << " height: " << myTree->getHeight() << std::endl;
    myTree->insert(int(14));
    std::cout << "size: " << myTree->getSize() << " height: " << myTree->getHeight() << std::endl;
    myTree->insert(int(1813));
    std::cout << "size: " << myTree->getSize() << " height: " << myTree->getHeight() << std::endl;
    myTree->insert(int(2042));
    std::cout << "size: " << myTree->getSize() << " height: " << myTree->getHeight() << std::endl;
    myTree->insert(int(-3));
    std::cout << "size: " << myTree->getSize() << " height: " << myTree->getHeight() << std::endl;
    myTree->insert(int(69));
    std::cout << "size: " << myTree->getSize() << " height: " << myTree->getHeight() << std::endl;

    // std::cout << myTree->getContent() << std::endl;

    myTree->printTree();

    std::cout << std::boolalpha;
    std::cout << "achou: " << myTree->has(1813) << "\n";

    myTree->clear();
    delete myTree;


    return 0;
}