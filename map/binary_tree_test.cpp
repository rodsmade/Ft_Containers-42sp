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
    // std::cout << "size: " << myTree->getSize() << " height: " << myTree->getHeight() << std::endl;
    // myTree->insert(int(42));
    // std::cout << "size: " << myTree->getSize() << " height: " << myTree->getHeight() << std::endl;
    myTree->insert(int(369));
    // std::cout << "size: " << myTree->getSize() << " height: " << myTree->getHeight() << std::endl;
    myTree->insert(int(2207));
    // std::cout << "size: " << myTree->getSize() << " height: " << myTree->getHeight() << std::endl;
    myTree->insert(int(52));
    // std::cout << "size: " << myTree->getSize() << " height: " << myTree->getHeight() << std::endl;
    myTree->insert(int(1));
    // std::cout << "size: " << myTree->getSize() << " height: " << myTree->getHeight() << std::endl;
    myTree->insert(int(37));
    // std::cout << "size: " << myTree->getSize() << " height: " << myTree->getHeight() << std::endl;
    myTree->insert(int(14));
    // std::cout << "size: " << myTree->getSize() << " height: " << myTree->getHeight() << std::endl;
    myTree->insert(int(1813));
    // std::cout << "size: " << myTree->getSize() << " height: " << myTree->getHeight() << std::endl;
    myTree->insert(int(2042));
    // std::cout << "size: " << myTree->getSize() << " height: " << myTree->getHeight() << std::endl;
    myTree->insert(int(-3));
    // std::cout << "size: " << myTree->getSize() << " height: " << myTree->getHeight() << std::endl;
    myTree->insert(int(69));
    // std::cout << "size: " << myTree->getSize() << " height: " << myTree->getHeight() << std::endl;
    myTree->insert(int(69));
    myTree->insert(int(43));
    myTree->insert(int(649));
    myTree->insert(int(619));
    myTree->insert(int(323));
    myTree->insert(int(6549));
    myTree->insert(int(5));
    myTree->insert(int(87));
    myTree->insert(int(9));
    myTree->insert(int(443));
    myTree->insert(int(949));
    myTree->insert(int(23));
    myTree->insert(int(326));
    myTree->insert(int(400));
    myTree->insert(int(52));
    myTree->insert(int(777));

    // std::cout << myTree->getContent() << std::endl;

    // myTree->printTree();

    std::cout << std::boolalpha;
    std::cout << "achou: " << myTree->has(1813) << "\n";

    std::cout << "depois de -3 vem o: " << myTree->getNextNode(-3)->_content << std::endl;
    std::cout << "depois de 649 vem o: " << myTree->getNextNode(649)->_content << std::endl;
    std::cout << "depois de 42 vem o: " << myTree->getNextNode(42)->_content << std::endl;
    std::cout << "depois de 9 vem o: " << myTree->getNextNode(9)->_content << std::endl;
    std::cout << "depois de 14 vem o: " << myTree->getNextNode(14)->_content << std::endl;

    // std::cout << "segundo ELEMENTO DA ARVORE: \n";
    // std::cout << myTree->getNextNode(42) << "\n";


    myTree->clear();
    delete myTree;


    return 0;
}