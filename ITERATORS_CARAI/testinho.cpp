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
    void _insert_recursively(T value, BinaryTreeNode<T>* &current_node) {
        if (current_node == NULL) {
            current_node = new BinaryTreeNode<T>(value);
        }
        else if (current_node->_content < value) {
            _insert_recursively(value, current_node->_smaller);
        }
        else if (current_node->_content > value) {
            _insert_recursively(value, current_node->_greater);
        }
    };
    void _delete_in_post_order_traversal(BinaryTreeNode<T>* current_node) {
        if (current_node) {
            _delete_in_post_order_traversal(current_node->_smaller);
            _delete_in_post_order_traversal(current_node->_greater);
            delete current_node;
        }
    }
    BinaryTreeNode<T>  *_copy_nodes_in_pre_order_traversal(BinaryTreeNode<T> *current_node) {
        if (current_node) {
            BinaryTreeNode<T>* new_node = new BinaryTreeNode<T>(current_node->_content);
            new_node->_smaller = _copy_nodes_in_pre_order_traversal(current_node->_smaller);
            new_node->_greater = _copy_nodes_in_pre_order_traversal(current_node->_greater);
            return new_node;
        }
        return (NULL);
    }

   public:
    BinaryTree() : _root(NULL) {
        std::cout << "Default constructor\n";
    }
    BinaryTree(T value) {
        std::cout << "Value constructor\n";
        _root = new BinaryTreeNode<T>(value);
    }
    BinaryTree(const BinaryTree<T> &other) {
        _root = _copy_nodes_in_pre_order_traversal(other._root);
    };
    ~BinaryTree() {
        if (_root)
            _delete_in_post_order_traversal(_root);
    };
    void insert(const T &value) {
        _insert_recursively(value, _root);
    };
};

template <typename V>
std::ostream& operator<<(std::ostream& os, const typename BinaryTree<V>::BinaryTreeNode& node) {
    os << node._content;
    return os;
};

}  // namespace ft

int main() {
    ft::BinaryTree<int> teste;
    teste.insert(1);
    teste.insert(2);
    teste.insert(3);
    ft::BinaryTree<int> teste2(42);
    teste2.insert(43);
    teste2.insert(44);
    teste2.insert(45);
    ft::BinaryTree<int> teste3(teste2);
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
