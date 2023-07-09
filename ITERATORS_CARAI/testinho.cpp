#include <iomanip>  // std::boolalpha
#include <iostream>

namespace ft {

template <typename T>
class map {
   private:
    // Prototypes
    // ...

    // Implementation
    class BinaryTree {
       private:
        // Prototypes
        class BinaryTreeNode;

        friend class map;

        template <typename U>
        friend std::ostream& operator<<(std::ostream& os, const BinaryTreeNode& node);

        // Implementation
        class BinaryTreeNode {
           private:
            // Prototypes
            friend class BinaryTree;
            template <typename U>
            friend class map;

            // Private members
            T _content;
            BinaryTreeNode* _parent;
            BinaryTreeNode* _smaller;
            BinaryTreeNode* _greater;

           public:
            BinaryTreeNode(T content = T(), BinaryTreeNode* parent = NULL, BinaryTreeNode* smaller = NULL, BinaryTreeNode* greater = NULL) : _content(content), _parent(parent), _smaller(smaller), _greater(greater){};
            ~BinaryTreeNode(){};
            BinaryTreeNode(const BinaryTreeNode& other) {
                _content = T(other._content);
                _parent = other._parent;
                _smaller = other._smaller;
                _greater = other._greater;
            };

            BinaryTreeNode& operator=(const BinaryTreeNode& other) {
                if (*this != other) {
                    _content = other._content;
                    _parent = other._parent;
                    _smaller = other._smaller;
                    _greater = other._greater;
                }
                return (*this);
            }

            bool operator==(const BinaryTreeNode& rhs) {
                return (this->_content == rhs._content && this->_parent == rhs._parent && this->_smaller == rhs._smaller && this->_greater == rhs._greater);
            }

            bool operator!=(const BinaryTreeNode& rhs) {
                return !(*this == rhs);
            }
        };

        // Attributes
        BinaryTreeNode* _root;
        size_t _size;

        // Private member functions
        void _insert_recursively(const T& value, BinaryTreeNode*& current_node, BinaryTreeNode** parent_node) {
            if (current_node == NULL) {
                current_node = new BinaryTreeNode(value);
                if (*parent_node)
                    current_node->_parent = *parent_node;
                _size++;
            } else if (current_node->_content < value) {
                _insert_recursively(value, current_node->_greater, &current_node);
            } else if (current_node->_content > value) {
                _insert_recursively(value, current_node->_smaller, &current_node);
            }
        };
        void _delete_in_post_order_traversal(BinaryTreeNode* current_node) {
            if (current_node) {
                _delete_in_post_order_traversal(current_node->_smaller);
                _delete_in_post_order_traversal(current_node->_greater);
                delete current_node;
            }
        };
        BinaryTreeNode* _copy_nodes_in_pre_order_traversal(BinaryTreeNode* current_node) {
            if (current_node) {
                BinaryTreeNode* new_node = new BinaryTreeNode(current_node->_content);
                new_node->_smaller = _copy_nodes_in_pre_order_traversal(current_node->_smaller);
                new_node->_greater = _copy_nodes_in_pre_order_traversal(current_node->_greater);
                return new_node;
            }
            return (NULL);
        };
        void _print_tree_helper(BinaryTreeNode* current_node, int level) {
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

            // std::cout << current_node->_content << std::endl;
            if (current_node->_parent)
                std::cout << current_node->_parent->_content << "/" << current_node->_content << std::endl;
            else
                std::cout << "🌱 "
                          << "/" << current_node->_content << std::endl;

            _print_tree_helper(current_node->_smaller, level + 1);
        }

        void _compare_in_order_traversal(BinaryTreeNode* lhs, BinaryTreeNode* rhs, bool* result) {
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
        BinaryTree() : _root(NULL), _size(0) {}
        BinaryTree(T value) {
            _root = new BinaryTreeNode(value);
            _size = 1;
        }
        BinaryTree(const BinaryTree& other) {
            _root = _copy_nodes_in_pre_order_traversal(other._root);
            _size = other._size;
        };
        ~BinaryTree() {
            if (_root)
                _delete_in_post_order_traversal(_root);
        };

        BinaryTree operator=(const BinaryTree& other) {
            if (*this != other) {
                _delete_in_post_order_traversal(_root);
                _root = _copy_nodes_in_pre_order_traversal(other._root);
                _size = other._size;
            }
            return (*this);
        }
        bool operator==(const BinaryTree& other) {
            bool result = true;
            _compare_in_order_traversal(this->_root, other._root, &result);
            return (result);
        }
        bool operator!=(const BinaryTree& other) {
            return (!(this->_root == other._root));
        }
        void insert(const T& value) {
            BinaryTreeNode* nullPtr = NULL;

            _insert_recursively(value, _root, &nullPtr);
        };
        void printTree() {
            _print_tree_helper(_root, 0);
        };
        size_t getSize(void) { return this->_size; };
    };

    class BinaryTreeIterator {
       private:
        typename BinaryTree::BinaryTreeNode* _node;

       public:
        BinaryTreeIterator(typename BinaryTree::BinaryTreeNode* node) : _node(node){};
        ~BinaryTreeIterator(void){};

        T& operator*(void) {
            return _node->_content;
        }
        BinaryTreeIterator& operator++() {
        if (!_node) {
            // Tree is empty
            _node = NULL;
        } else {
            if (!_node->_greater) {
                while (_node->_parent && _node->_parent->_content <= _node->_content) {
                    _node = _node->_parent;
                }
                _node = _node->_parent;
            } else {
                _node = _node->_greater;
                while (_node->_smaller)
                    _node = _node->_smaller;
            }
        }

        return *this;
}

        bool operator==(const BinaryTreeIterator& rhs) {
            return (_node == rhs._node);
        }
        bool operator!=(const BinaryTreeIterator& rhs) {
            return (!(*this == rhs));
        }
    };

    // Attributes
    BinaryTree _container;

   public:
    // Aliases
    typedef T value_type;
    typedef size_t size_type;
    typedef BinaryTreeIterator iterator;

    map() : _container(BinaryTree()) { std::cout << "Map default constructor called\n"; };
    ~map() { std::cout << "Map destructor called\n"; };

    // TODO: REMOVE
    BinaryTree& get_bin_tree(void) { return _container; };

    void insert(T value) {
        _container.insert(value);
    };

    size_type size(void) {
        return _container.getSize();
    };

    bool empty(void) {
        return (size() == 0);
    }

    BinaryTreeIterator begin(void) {
        typename BinaryTree::BinaryTreeNode* pivot = _container._root;
        while (pivot->_smaller)
            pivot = pivot->_smaller;
        return (BinaryTreeIterator(pivot));
    };

    BinaryTreeIterator end(void) {
        return (BinaryTreeIterator(NULL));
    };
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const typename map<T>::BinaryTree::BinaryTreeNode& node) {
    os << node._content;
    return os;
};

}  // namespace ft

int main() {
    ft::map<int> teste;
    std::cout << std::boolalpha;
    std::cout << "empty: " << teste.empty() << "\n";
    std::cout << "size: " << teste.size() << "\n";
    teste.insert(42);
    teste.insert(1);
    teste.insert(-3);
    teste.insert(37);
    teste.insert(14);
    teste.insert(23);
    teste.insert(5);
    teste.insert(6);
    teste.insert(9);
    teste.insert(369);
    teste.insert(52);
    teste.insert(43);
    teste.insert(69);
    teste.insert(323);
    teste.insert(87);
    teste.insert(326);
    teste.insert(2207);
    teste.insert(1813);
    teste.insert(6549);
    teste.insert(649);
    teste.insert(2042);
    teste.insert(619);
    teste.insert(443);
    teste.insert(400);
    teste.insert(949);
    teste.insert(777);
    std::cout << "empty: " << teste.empty() << "\n";
    std::cout << "size: " << teste.size() << "\n";

    for (ft::map<int>::iterator it = teste.begin(); it != teste.end(); ++it)
        std::cout << "begin iterator: " << *it << "\n";

    // ft::map<int>::iterator it = teste.begin();
    // for (ft::map<int>::size_type i = 0; i < teste.size(); i++) {
    //     std::cout << "begin iterator: " << *it << "\n";
    //     ++it;
    // }

    // std::cout << "begin iterator: " << *it << "\n";
    // ++it;
    // std::cout << "begin iterator: " << *it << "\n";
    // ++it;
    // std::cout << "begin iterator: " << *it << "\n";
    // ++it;
    // std::cout << "begin iterator: " << *it << "\n";

    teste.get_bin_tree().printTree();
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
//
//     teste1.insert(6);
//     teste1.insert(5);
//     teste1.insert(4);
//     teste2.insert(41);
//     teste2.insert(40);
//
//     std::cout << "\nTeste 1: (size: " << teste1.getSize() << ")\n";
//     teste1.printTree();
//
//     std::cout << "\nTeste 2: (size: " << teste2.getSize() << ")\n";
//     teste2.printTree();
//     std::cout << "\nTeste 3: (size: " << teste3.getSize() << ")\n";
//     teste3.printTree();
//     std::cout << "\nTeste 4: (size: " << teste4.getSize() << ")\n";
//     teste4.printTree();
//
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
