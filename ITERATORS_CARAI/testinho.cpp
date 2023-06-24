#include <iostream>

namespace ft {
template <typename T>
class BinaryTree {
   private:
    template <typename U>
    class BinaryTreeNode {
       private:
        U _content;
        BinaryTreeNode* _smaller;
        BinaryTreeNode* _greater;

       public:
        BinaryTreeNode(U content = U(), BinaryTreeNode* smaller = NULL, BinaryTreeNode* greater = NULL) : _content(content), _smaller(smaller), _greater(greater){};
        ~BinaryTreeNode(){};
        BinaryTreeNode(const BinaryTreeNode& other) {
            _content = U(other._content);
            _smaller = other._smaller;
            _greater = other._greater;
        };

        BinaryTreeNode<U>& operator=(const BinaryTreeNode &other) {
            if (*this != other) {
                _content = other._content;
                _smaller = other._smaller;
                _greater = other._greater;
            }
            return (*this);
        }

        bool operator==(const BinaryTreeNode<U>& rhs) {
            return (this->_content == rhs._content && this->_smaller == rhs._smaller && this->_greater == rhs._greater);
        }

        bool operator!=(const BinaryTreeNode<U>& rhs) {
            return !(*this == rhs);
        }
    };

    template <typename V>
    friend std::ostream& operator<<(std::ostream& os, const BinaryTreeNode<V>& node);

   public:
    BinaryTree() {
        std::cout << "Hello world\n";
    }
};

template <typename V>
std::ostream& operator<<(std::ostream& os, const typename BinaryTree<V>::BinaryTreeNode& node) {
    os << node._content;
    return os;
};

}  // namespace ft

// int main() {
//     ft::BinaryTreeNode<std::string> node2("DOIS");
//     ft::BinaryTreeNode<std::string> node3("TRES");
//     ft::BinaryTreeNode<std::string> node1("UM", &node2, &node3);
//     ft::BinaryTreeNode<std::string> node4(node1);
//     ft::BinaryTreeNode<std::string> node5;
//     node5 = node1;
//
//     std::cout << std::endl;
//     std::cout << node1 << std::endl;
//     std::cout << node2 << std::endl;
//     std::cout << node3 << std::endl;
//     std::cout << node4 << std::endl;
//     std::cout << node5 << std::endl;
//
//     node1 = ft::BinaryTreeNode<std::string>("NOVO UM");
//
//     std::cout << std::endl;
//     std::cout << node1 << std::endl;
//     std::cout << node2 << std::endl;
//     std::cout << node3 << std::endl;
//     std::cout << node4 << std::endl;
//     std::cout << node5 << std::endl;
// }

int main() {
    ft::BinaryTree<std::string> teste;
    (void) teste;
}