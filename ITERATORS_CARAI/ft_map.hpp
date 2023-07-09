#ifndef FT_MAP_HPP
#define FT_MAP_HPP

#include <iostream>

namespace ft {

template <typename T>
class map {
   private:

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
        BinaryTreeIterator(typename BinaryTree::BinaryTreeNode* node);
        ~BinaryTreeIterator(void);

        T&                  operator*(void);
        BinaryTreeIterator& operator++(void);
        bool                operator==(const BinaryTreeIterator& rhs);
        bool                operator!=(const BinaryTreeIterator& rhs);
    };

    // Attributes
    BinaryTree _container;

   public:
    /*=============================================
    ===                ALIASES                  ===
    =============================================*/
    typedef T value_type;
    typedef size_t size_type;
    typedef BinaryTreeIterator iterator;

    /*=============================================
    ===            MEMBER FUNCTIONS             ===
    =============================================*/
    // TODO: REMOVE
    BinaryTree& get_bin_tree(void) { return _container; };

    void        insert(T value);
    size_type   size(void);
    bool        empty(void);

    BinaryTreeIterator begin(void);
    BinaryTreeIterator end(void);

    /*=============================================
    ===      CONSTRUCTION / DESTRUCTION         ===
    =============================================*/
    map();
    ~map();
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const typename map<T>::BinaryTree::BinaryTreeNode& node);

};  // namespace ft

#include "ft_map.tpp"

#endif