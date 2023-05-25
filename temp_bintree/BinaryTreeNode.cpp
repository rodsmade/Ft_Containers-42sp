#include <cstddef>

// template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T> > >
template <class T>
class BinaryTreeNode {
   public:
    T               _content;
    BinaryTreeNode  *_smaller;
    BinaryTreeNode  *_greater;

   public:
    BinaryTreeNode(const T &value) : _content(value), _smaller(NULL), _greater(NULL) {};
    // BinaryTreeNode(const BinaryTreeNode &other) : _content(other._content), _smaller(other._smaller), _greater(other._greater) {};
    // ~BinaryTreeNode() {};
    // BinaryTreeNode const &operator=(const BinaryTreeNode &other) {
    //     if (other != *this) {
    //         _content = other._content;
    //         _smaller = other._smaller;
    //         _greater = other._greater;
    //     }
    // };
};

template <class T>
class BinaryTree {
   private:
    BinaryTreeNode<T> *_root;
    size_t _size;
    size_t _height;

    void insertRecursive(BinaryTreeNode<T> *&current, const T &value) {
        if (current == NULL) {
            current = new BinaryTreeNode<T>(value);
            _size++;
        } else if (value < current->_content) {
            insertRecursive(current->_smaller, value);
        } else if (value > current->_content) {
            insertRecursive(current->_greater, value);
        }
    }

    void deleteRecursive(BinaryTreeNode<T> *&current) {
        if (current) {
            if (current->_smaller == NULL && current->_greater == NULL) {
                delete current;
                return ;
            } else {
                if (current->_smaller) {
                    deleteRecursive(current->_smaller);
                    current->_smaller = NULL;
                }
                if (current->_greater) {
                    deleteRecursive(current->_greater);
                    current->_greater = NULL;
                }
                deleteRecursive(current);
            }
        }
    }

    // Helper function for printing the tree
    void printTreeHelper(BinaryTreeNode<T>* current, int level) {
        if (current == NULL) {
            return;
        }

        printTreeHelper(current->_greater, level + 1);

        for (int i = 0; i < level; i++) {
            std::cout << "\t";
        }

        std::cout << current->_content << std::endl;

        printTreeHelper(current->_smaller, level + 1);
    }

   public:
    BinaryTree() : _root(NULL), _size(0), _height(0) {};
    // BinaryTree(const BinaryTree &other) : _root(other._root) {};
    ~BinaryTree() {
        if (_root) {

        }
    };
    // BinaryTree const &operator=(const BinaryTree &other) {
    //     if (*this != other) {
    //         _root = other._root;
    //     }
    // }

    // Accessors
    size_t  getSize(void) const { return _size; };
    size_t  getHeight(void) const { return _height; };

    // Public function to print the tree
    void printTree() {
        printTreeHelper(_root, 0);
    }

    // Modifiers
    void    insert(const T &newValue) {
        insertRecursive(_root, newValue);
    }
    void    clear(void) {
        deleteRecursive(_root);
    }

};
