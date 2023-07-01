#include <iostream>
#include <iomanip> // std::boolalpha

namespace ft {

template <typename T>
class map {
   private:
    // Prototypes
    template <typename U>
    class BinaryTree;

    // Implementation
    template <typename Batatafrita>
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
        BinaryTreeNode<Batatafrita>* _root;
        size_t _size;

        // Private member functions
        void _insert_recursively(const Batatafrita& value, BinaryTreeNode<Batatafrita>*& current_node) {
            if (current_node == NULL) {
                current_node = new BinaryTreeNode<Batatafrita>(value);
                _size++;
            } else if (current_node->_content < value) {
                _insert_recursively(value, current_node->_greater);
            } else if (current_node->_content > value) {
                _insert_recursively(value, current_node->_smaller);
            }
        };
        void _delete_in_post_order_traversal(BinaryTreeNode<Batatafrita>* current_node) {
            if (current_node) {
                _delete_in_post_order_traversal(current_node->_smaller);
                _delete_in_post_order_traversal(current_node->_greater);
                delete current_node;
            }
        };
        BinaryTreeNode<Batatafrita>* _copy_nodes_in_pre_order_traversal(BinaryTreeNode<Batatafrita>* current_node) {
            if (current_node) {
                BinaryTreeNode<Batatafrita>* new_node = new BinaryTreeNode<Batatafrita>(current_node->_content);
                new_node->_smaller = _copy_nodes_in_pre_order_traversal(current_node->_smaller);
                new_node->_greater = _copy_nodes_in_pre_order_traversal(current_node->_greater);
                return new_node;
            }
            return (NULL);
        };
        void _print_tree_helper(BinaryTreeNode<Batatafrita>* current_node, int level) {
            if (current_node == NULL) {
                for (int i = 0; i < level; i++) {
                    std::cout << "\t";
                }

                std::cout << "🍃" << std::endl;
                return;
            }

            _print_tree_helper(current_node->_greater, level + 1);

            for (int i = 0; i < level; i++) {
                std::cout << "\t";
            }

            std::cout << current_node->_content << std::endl;
            // if (current_node->_parent)
            //     std::cout << current_node->_parent->_content << "/" << current_node->_content << std::endl;
            // else
            //     std::cout << "NULL"
            //               << "/" << current_node->_content << std::endl;

            _print_tree_helper(current_node->_smaller, level + 1);
        }

        void _compare_in_order_traversal(BinaryTreeNode<Batatafrita>* lhs, BinaryTreeNode<Batatafrita>* rhs, bool* result) {
            if (*result == false)
                return;
            else {
                if (lhs == NULL && rhs == NULL)  // both are leaves
                    return;
                else if (lhs == NULL || rhs == NULL) {  // one is leaf and the other is not
                    *result = false;
                    return;
                } else {  // none are leaves
                    _compare_in_order_traversal(lhs->_smaller, rhs->_smaller, result);
                    if (lhs->_content != rhs->_content) {
                        *result = false;
                        return;
                    }
                    _compare_in_order_traversal(lhs->_greater, rhs->_greater, result);
                }
            }
        };

    public:
        BinaryTree() : _root(NULL), _size(0) {
            std::cout << "Default constructor\n";
        }
        BinaryTree(Batatafrita value) {
            std::cout << "Value constructor\n";
            _root = new BinaryTreeNode<Batatafrita>(value);
            _size = 1;
        }
        BinaryTree(const BinaryTree<Batatafrita>& other) {
            _root = _copy_nodes_in_pre_order_traversal(other._root);
            _size = other._size;
        };
        ~BinaryTree() {
            if (_root)
                _delete_in_post_order_traversal(_root);
        };

        BinaryTree<Batatafrita> operator=(const BinaryTree<Batatafrita>& other) {
            if (*this != other) {
                _delete_in_post_order_traversal(_root);
                _root = _copy_nodes_in_pre_order_traversal(other._root);
                _size = other._size;
            }
            return (*this);
        }
        bool operator==(const BinaryTree<Batatafrita>& other) {
            bool result = true;
            _compare_in_order_traversal(this->_root, other._root, &result);
            return (result);
        }
        bool operator!=(const BinaryTree<Batatafrita>& other) {
            return (!(this->_root == other._root));
        }
        void insert(const Batatafrita& value) {
            _insert_recursively(value, _root);
        };
        void printTree() {
            _print_tree_helper(_root, 0);
        };
        size_t getSize(void) { return this->_size; };
    };

    // Attributes
    BinaryTree<T>   _container;

   public:
    map() : _container(BinaryTree<T>()) { std::cout << "Map default constructor called\n"; };
    ~map() { std::cout << "Map destructor called\n"; };

};

template <typename V>
std::ostream& operator<<(std::ostream& os, const typename map<V>::BinaryTree::BinaryTreeNode& node) {
    os << node._content;
    return os;
};

}  // namespace ft

int main() {
    ft::map<int> teste;
    return 0;
}

// int main() { // BinaryTree tests!!
//     ft::BinaryTree<int> teste1;
//     teste1.insert(1);
//     teste1.insert(2);
//     teste1.insert(3);
//     ft::BinaryTree<int> teste2(42);
//     teste2.insert(43);
//     teste2.insert(44);
//     ft::BinaryTree<int> teste3(teste2);
//     ft::BinaryTree<int> teste4;
//     teste4 = teste1;

//     teste1.insert(6);
//     teste1.insert(5);
//     teste1.insert(4);
//     teste2.insert(41);
//     teste2.insert(40);

//     std::cout << "\nTeste 1: (size: " << teste1.getSize() << ")\n";
//     teste1.printTree();

//     std::cout << "\nTeste 2: (size: " << teste2.getSize() << ")\n";
//     teste2.printTree();
//     std::cout << "\nTeste 3: (size: " << teste3.getSize() << ")\n";
//     teste3.printTree();
//     std::cout << "\nTeste 4: (size: " << teste4.getSize() << ")\n";
//     teste4.printTree();

//     std::cout << std::boolalpha << std::endl;
//     std::cout << "teste1 == teste1: " << (teste1 == teste1) << std::endl;
//     std::cout << "teste1 == teste2: " << (teste1 == teste2) << std::endl;
//     std::cout << "teste1 == teste3: " << (teste1 == teste3) << std::endl;
//     std::cout << "teste1 == teste4: " << (teste1 == teste4) << std::endl;
//     std::cout << "teste2 == teste2: " << (teste2 == teste2) << std::endl;
//     std::cout << "teste2 == teste3: " << (teste2 == teste3) << std::endl;
//     std::cout << "teste2 == teste4: " << (teste2 == teste4) << std::endl;
//     std::cout << "teste3 == teste3: " << (teste3 == teste3) << std::endl;
//     std::cout << "teste3 == teste4: " << (teste3 == teste4) << std::endl;
//     std::cout << "teste4 == teste4: " << (teste4 == teste4) << std::endl;
// }

// int main() { // BinaryTreeNode Tests!!
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
