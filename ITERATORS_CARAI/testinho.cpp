#include <iostream>

namespace ft {
template <typename T>
class BinaryTree {
   private:
    // Prototypes
    template <typename U>
    class BinaryTreeNode;

    template <typename V>
    friend std::ostream& operator<<(std::ostream& os, const BinaryTreeNode<V>& node);

    // Implementation
    template <typename U>
    class BinaryTreeNode {
       private:
        // Prototypes
        friend class BinaryTree<U>;

        // Private members
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

        BinaryTreeNode<U>& operator=(const BinaryTreeNode& other) {
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

    // Attributes
    BinaryTreeNode<T>* _root;

    // Private member functions
    void _recursive_insertion(T value, BinaryTreeNode<T>* &current_node) {
        if (current_node == NULL) {
            current_node = new BinaryTreeNode<T>(value);
        }
        else if (current_node->_content < value) {
            _recursive_insertion(value, current_node->_smaller);
        }
        else if (current_node->_content > value) {
            _recursive_insertion(value, current_node->_greater);
        }
    };
    void _recursive_deletion(BinaryTreeNode<T>* current_node) {
        if (current_node) {
            _recursive_deletion(current_node->_smaller);
            _recursive_deletion(current_node->_greater);
            delete current_node;
        }
    }

   public:
    BinaryTree() : _root(NULL) {
        std::cout << "Default constructor\n";
    }
    BinaryTree(T value) {
        std::cout << "Value constructor\n";
        _root = new BinaryTreeNode<T>(value);
    }
    ~BinaryTree() {
        if (_root)
            _recursive_deletion(_root);
    };
    void insert(const T &value) {
        _recursive_insertion(value, _root);
    };
};

template <typename V>
std::ostream& operator<<(std::ostream& os, const typename BinaryTree<V>::BinaryTreeNode& node) {
    os << node._content;
    return os;
};

}  // namespace ft

int main() {
    ft::BinaryTree<std::string> teste;
    teste.insert("eita deus");
    teste.insert("eita amor");
    teste.insert("eita febre");
    ft::BinaryTree<std::string> teste2("quarenta e dois");
    teste2.insert("quarenta e três");
    teste2.insert("quarenta e quatro");
    teste2.insert("quarenta e cinco");
}

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
