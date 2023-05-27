#ifndef BINARY_TREE_TPP
#define BINARY_TREE_TPP

namespace ft {

template <class T>
BinaryTreeNode<T>::BinaryTreeNode(const T &value) : _content(value), _smaller(NULL), _greater(NULL) {};

template <class T>
void BinaryTree<T>::insertRecursive(BinaryTreeNode<T> *&current, const T &value) {
    if (current == NULL) {
        current = new BinaryTreeNode<T>(value);
        _size++;
    } else if (value < current->_content) {
        insertRecursive(current->_smaller, value);
    } else if (value > current->_content) {
        insertRecursive(current->_greater, value);
    }
}

template <class T>
void BinaryTree<T>::deleteRecursive(BinaryTreeNode<T> *&current) {
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

template <class T>
void BinaryTree<T>::printTreeHelper(BinaryTreeNode<T>* current, int level) {
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

// constructor
template <class T>
BinaryTree<T>::BinaryTree() : _root(NULL), _size(0), _height(0), _cleared(true) {};

template <class T>
BinaryTree<T>::~BinaryTree() {
    if (!_cleared) {
        deleteRecursive(_root);
    }
};

// Accessors
template <class T>
size_t  BinaryTree<T>::getSize(void) const { return _size; };

template <class T>
size_t  BinaryTree<T>::getHeight(void) const { return _height; };

template <class T>
void BinaryTree<T>::printTree() {
    printTreeHelper(_root, 0);
};

template <class T>
void    BinaryTree<T>::insert(const T &newValue) {
    insertRecursive(_root, newValue);
    _cleared = false;
}

template <class T>
void    BinaryTree<T>::clear(void) {
    deleteRecursive(_root);
    _cleared = true;
}

}

#endif