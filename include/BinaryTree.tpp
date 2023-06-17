#ifndef BINARY_TREE_TPP
#define BINARY_TREE_TPP

namespace ft {

//////////////////////////////////////////////////////////////////////////////////// BINARY TREE NODE 
template <class T, class Compare, class Allocator >
BinaryTreeNode<T, Compare, Allocator>::BinaryTreeNode(const T &value, const Compare& comp, const Allocator& alloc) : _allocator(alloc)
                                                                                                                    , _compare(comp)
                                                                                                                    , _content(value)
                                                                                                                    , _smaller(NULL)
                                                                                                                    , _greater(NULL)
                                                                                                                    , _parent(NULL) {};

template <class T, class Compare, class Allocator >
BinaryTreeNode<T, Compare, Allocator>::BinaryTreeNode(const BinaryTreeNode &other) : _allocator(other._allocator)
                                                                                    , _compare(other._compare)
                                                                                    , _content(other._content)
                                                                                    , _smaller(other._smaller)
                                                                                    , _greater(other._greater)
                                                                                    , _parent(other._parent) {};

template <class T, class Compare, class Allocator >
BinaryTreeNode<T, Compare, Allocator> &BinaryTreeNode<T, Compare, Allocator>::operator=(const BinaryTreeNode &other) {
    if (other != *this) {
        _allocator = other._allocator;
        _compare = other._compare;
        _content = other._content;
        _smaller = other._smaller;
        _greater = other._greater;
        _parent = other._parent;
    }
};

template <class T, class Compare, class Allocator >
BinaryTreeNode<T, Compare, Allocator>::~BinaryTreeNode() {};

//////////////////////////////////////////////////////////////////////////////////// BINARY TREE
template <class T, class Compare, class Allocator>
void BinaryTree<T, Compare, Allocator>::_insertRecursive(BinaryTreeNode<T, Compare, Allocator> *&current, const T &value, BinaryTreeNode<T, Compare, Allocator> *&parent) {
    if (current == NULL) {
        current = new BinaryTreeNode<T, Compare, Allocator>(value);
        if (current != parent)
            current->_parent = parent;
        _size++;
    } else if (value < current->_content) {
        _insertRecursive(current->_smaller, value, current);
    } else if (value > current->_content) {
        _insertRecursive(current->_greater, value, current);
    }
}

template <class T, class Compare, class Allocator>
void BinaryTree<T, Compare, Allocator>::_deleteRecursive(BinaryTreeNode<T, Compare, Allocator> *&current) {
    if (current) {
        if (current->_smaller == NULL && current->_greater == NULL) {
            delete current;
            current = NULL;
            return ;
        } else {
            if (current->_smaller)
                _deleteRecursive(current->_smaller);
            if (current->_greater)
                _deleteRecursive(current->_greater);
            _deleteRecursive(current);
        }
    }
}

template <class T, class Compare, class Allocator>
bool BinaryTree<T, Compare, Allocator>::_lookupRecursive(BinaryTreeNode<T, Compare, Allocator> *&current, const T&value) {
    if (current->_content == value)
        return (true);
    else if (!current->_greater && !current->_smaller)
        return (false);
    else {
        if (value < current->_content)
            return (_lookupRecursive(current->_smaller, value));
        else
            return (_lookupRecursive(current->_greater, value));
    }
};

template <class T, class Compare, class Allocator>
void BinaryTree<T, Compare, Allocator>::_inOrderTraversal(BinaryTreeNode<T, Compare, Allocator> *current) {
    if (current == NULL)
        return;

    _inOrderTraversal(current->_smaller);
    std::cout << current->_content << " ";
    _inOrderTraversal(current->_greater);
};

template <class T, class Compare, class Allocator>
void BinaryTree<T, Compare, Allocator>::_preOrderTraversal(BinaryTreeNode<T, Compare, Allocator> *current) {
    if (current == NULL)
        return;

    std::cout << current->_content << " ";
    _preOrderTraversal(current->_smaller);
    _preOrderTraversal(current->_greater);
};

template <class T, class Compare, class Allocator>
void BinaryTree<T, Compare, Allocator>::_postOrderTraversal(BinaryTreeNode<T, Compare, Allocator> *current) {
    if (current == NULL)
        return;

    _postOrderTraversal(current->_smaller);
    _postOrderTraversal(current->_greater);
    std::cout << current->_content << " ";
};

template <class T, class Compare, class Allocator>
void BinaryTree<T, Compare, Allocator>::_printTreeHelper(BinaryTreeNode<T, Compare, Allocator>* current, int level)
{
    if (current == NULL) {
        return;
    }

    _printTreeHelper(current->_greater, level + 1);

    for (int i = 0; i < level; i++) {
        std::cout << "\t";
    }

    // std::cout << current->_content << std::endl;
    if (current->_parent)
        std::cout << current->_parent->_content << "/" << current->_content << std::endl;
    else
        std::cout << "NULL" << "/" << current->_content << std::endl;

    _printTreeHelper(current->_smaller, level + 1);
}
// {
//     (void) current;
//     (void) level;
//     _inOrderTraversal(_root);
//     std::cout << std::endl;
// }

// MEMBER FUNCTIONS
template <class T, class Compare, class Allocator>
bool BinaryTree<T, Compare, Allocator>::has(const T&value) {
    if (_root == NULL)
        return (false);

    return (_lookupRecursive(_root, value));
};

// template <class T, class Compare, class Allocator>
// BinaryTreeNode<T, Compare, Allocator> *BinaryTree<T, Compare, Allocator>::_findNodeByContent(T searchContent) {
//     BinaryTreeNode<T, Compare, Allocator> *pivot = _root;
//     while (pivot != NULL) {
//         if (searchContent < pivot->_content > )
//             pivot = pivot->_smaller;
//         else if (searchContent > pivot->_content)
//             pivot = pivot->_greater;
//         else
//             return (pivot);
//     }

//     return (NULL);
// };

template <class T, class Compare, class Allocator>
BinaryTreeNode<T, Compare, Allocator> *BinaryTree<T, Compare, Allocator>::getNextNode(T searchValue) {
    if (_root == NULL)
        return NULL;

    BinaryTreeNode<T, Compare, Allocator> *pivot = _root;
    BinaryTreeNode<T, Compare, Allocator> *nextGreaterValue = NULL;

    while (pivot != NULL) {
        if (searchValue < pivot->_content) {
            nextGreaterValue = pivot;
            pivot = pivot->_smaller;
        }
        else
            pivot = pivot->_greater;
    }

    return (nextGreaterValue);
}

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
        _deleteRecursive(_root);
    }
};

template <class T, class Compare, class Allocator>
BinaryTree<T, Compare, Allocator> &BinaryTree<T, Compare, Allocator>::operator=(const BinaryTree &other) {
    if (*this != other) {
        _deleteRecursive(_root);
         _allocator = other._allocator;
         _compare = other._compare;
        _root = other._root;
        _cleared = other._cleared;
        _size = other._size;
        _height = other._height;
    }
    return (*this);
};

// Accessors
template <class T, class Compare, class Allocator>
size_t  BinaryTree<T, Compare, Allocator>::getSize(void) const { return _size; };

template <class T, class Compare, class Allocator>
size_t  BinaryTree<T, Compare, Allocator>::getHeight(void) const { return _height; };

template <class T, class Compare, class Allocator>
void BinaryTree<T, Compare, Allocator>::printTree() {
    _printTreeHelper(_root, 0);
};

template <class T, class Compare, class Allocator>
void    BinaryTree<T, Compare, Allocator>::insert(const T &newValue) {
    _insertRecursive(_root, newValue, _root);
    _cleared = false;
}

template <class T, class Compare, class Allocator>
void    BinaryTree<T, Compare, Allocator>::clear(void) {
    _deleteRecursive(_root);
    _cleared = true;
}

/*==============================================================================
===  NON-MEMBER FUNCTIONS                                                    ===
==============================================================================*/
/******************************************************************************/
/*   OPERATOR OVERLOADS                                                       */
/******************************************************************************/
// TODO: só vai sair quando tiver ITERADORES CARAI
// template <class T, class Compare, class Allocator>
// bool operator==(const BinaryTree<T, Compare, Allocator>& lhs, const BinaryTree<T, Compare, Allocator>& rhs) {
//     if (lhs.getSize() != rhs.getSize());
//         return (false);
//     return (false);
// };

// template <class T, class Compare, class Allocator>
// bool operator!=(const BinaryTree<T, Compare, Allocator>& lhs, const BinaryTree<T, Compare, Allocator>& rhs) {
//     return (false);
// };


}  // namespace ft

#endif