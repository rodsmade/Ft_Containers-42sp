#ifndef BINARY_TREE_TPP
#define BINARY_TREE_TPP

namespace ft {

//////////////////////////////////////////////////////////////////////////////////// BINARY TREE NODE 
template <class T, class Compare, class Allocator >
BinaryTreeNode<T, Compare, Allocator>::BinaryTreeNode(const T &value, const Compare& comp, const Allocator& alloc) : _allocator(alloc)
                                                                                                                    , _compare(comp)
                                                                                                                    , _content(value)
                                                                                                                    , _smaller(NULL)
                                                                                                                    , _greater(NULL) {};

template <class T, class Compare, class Allocator >
BinaryTreeNode<T, Compare, Allocator>::BinaryTreeNode(const BinaryTreeNode &other) : _allocator(other._allocator)
                                                                                    , _compare(other._compare)
                                                                                    , _content(other._content)
                                                                                    , _smaller(other._smaller)
                                                                                    , _greater(other._greater) {};

template <class T, class Compare, class Allocator >
BinaryTreeNode<T, Compare, Allocator> &BinaryTreeNode<T, Compare, Allocator>::operator=(const BinaryTreeNode &other) {
    if (other != *this) {
        _content = other._content;
        _smaller = other._smaller;
        _greater = other._greater;
    }
};

template <class T, class Compare, class Allocator >
BinaryTreeNode<T, Compare, Allocator>::~BinaryTreeNode() {};

//////////////////////////////////////////////////////////////////////////////////// BINARY TREE
template <class T, class Compare, class Allocator>
void BinaryTree<T, Compare, Allocator>::insertRecursive(BinaryTreeNode<T, Compare, Allocator> *&current, const T &value) {
    if (current == NULL) {
        current = new BinaryTreeNode<T, Compare, Allocator>(value);
        _size++;
    } else if (value < current->_content) {
        insertRecursive(current->_smaller, value);
    } else if (value > current->_content) {
        insertRecursive(current->_greater, value);
    }
}

template <class T, class Compare, class Allocator>
void BinaryTree<T, Compare, Allocator>::deleteRecursive(BinaryTreeNode<T, Compare, Allocator> *&current) {
    if (current) {
        if (current->_smaller == NULL && current->_greater == NULL) {
            delete current;
            current = NULL;
            return ;
        } else {
            if (current->_smaller)
                deleteRecursive(current->_smaller);
            if (current->_greater)
                deleteRecursive(current->_greater);
            deleteRecursive(current);
        }
    }
}

template <class T, class Compare, class Allocator>
void BinaryTree<T, Compare, Allocator>::printTreeHelper(BinaryTreeNode<T, Compare, Allocator>* current, int level) {
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

// MEMBER FUNCTIONS
// template <class T, class Compare, class Allocator>
// bool BinaryTree<T, Compare, Allocator>::has(const T&value) {
//     // TODO
// };


/*==============================================================================
===  CONSTRUCTION / DESTRUCTION                                              ===
==============================================================================*/
template <class T, class Compare, class Allocator>
BinaryTree<T, Compare, Allocator>::BinaryTree(const key_compare& comp, const allocator_type& alloc) : _allocator(alloc)
                                                                                                    , _compare(comp)
                                                                                                    , _root(NULL)
                                                                                                    , _size(0)
                                                                                                    , _height(0)
                                                                                                    , _cleared(true) {};

template <class T, class Compare, class Allocator>
BinaryTree<T,Compare, Allocator>::BinaryTree(const BinaryTree &other) : _allocator(other._allocator)
                                                                        , _compare(other._compare)
                                                                        , _root(other._root)
                                                                        , _size(other._size)
                                                                        , _height(other._height)
                                                                        , _cleared(other._cleared) {};

template <class T, class Compare, class Allocator>
BinaryTree<T, Compare, Allocator>::~BinaryTree() {
    if (!_cleared) {
        deleteRecursive(_root);
    }
};

template <class T, class Compare, class Allocator>
BinaryTree<T, Compare, Allocator> &BinaryTree<T, Compare, Allocator>::operator=(const BinaryTree &other) {
    if (*this != other) {
        deleteRecursive(_root);
        _root = other._root;
        _cleared = other._cleared;
        _size = other._size;
        _height = other._height;
    }
};

// Accessors
template <class T, class Compare, class Allocator>
size_t  BinaryTree<T, Compare, Allocator>::getSize(void) const { return _size; };

template <class T, class Compare, class Allocator>
size_t  BinaryTree<T, Compare, Allocator>::getHeight(void) const { return _height; };

template <class T, class Compare, class Allocator>
void BinaryTree<T, Compare, Allocator>::printTree() {
    printTreeHelper(_root, 0);
};

template <class T, class Compare, class Allocator>
void    BinaryTree<T, Compare, Allocator>::insert(const T &newValue) {
    insertRecursive(_root, newValue);
    _cleared = false;
}

template <class T, class Compare, class Allocator>
void    BinaryTree<T, Compare, Allocator>::clear(void) {
    deleteRecursive(_root);
    _cleared = true;
}

}  // namespace ft

#endif