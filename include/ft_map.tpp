#ifndef FT_MAP_TPP
#define FT_MAP_TPP

namespace ft {

/*      /‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\
       C|                    B I N A R Y   T R E E                    |Ↄ
        \_____________________________________________________________/      */
/*==============================================================================
===  PRIVATE MEMBER FUNCTIONS                                                ===
==============================================================================*/
template <typename T>
bool map<T>::BinaryTree::_insert_recursively(const T& value, BinaryTreeNode*& current_node, BinaryTreeNode** parent_node) {
    if (current_node == NULL) {
        current_node = new BinaryTreeNode(value);
        if (*parent_node)
            current_node->_parent = *parent_node;
        _size++;
    } else if (current_node->_content < value) {
        if (!_insert_recursively(value, current_node->_greater, &current_node))
            return false;
    } else if (current_node->_content > value) {
        if (!_insert_recursively(value, current_node->_smaller, &current_node))
            return false;
    } else {
        return false;
    }
    return true;
};

template <typename T>
void map<T>::BinaryTree::_delete_in_post_order_traversal(BinaryTreeNode* current_node) {
    if (current_node) {
        _delete_in_post_order_traversal(current_node->_smaller);
        _delete_in_post_order_traversal(current_node->_greater);
        delete current_node;
    }
};

template <typename T>
typename map<T>::BinaryTree::BinaryTreeNode* map<T>::BinaryTree::_copy_nodes_in_pre_order_traversal(BinaryTreeNode* current_node) {
    if (current_node) {
        BinaryTreeNode* new_node = new BinaryTreeNode(current_node->_content);
        new_node->_smaller = _copy_nodes_in_pre_order_traversal(current_node->_smaller);
        new_node->_greater = _copy_nodes_in_pre_order_traversal(current_node->_greater);
        return new_node;
    }
    return (NULL);
};

template <typename T>
void map<T>::BinaryTree::_print_tree_helper(BinaryTreeNode* current_node, int level) {
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
};

template <typename T>
void map<T>::BinaryTree::_compare_in_order_traversal(BinaryTreeNode* lhs, BinaryTreeNode* rhs, bool* result) {
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

/*=============================================================================
===  MEMBER FUNCTIONS                                                       ===
=============================================================================*/
template <typename T>
map<T>::BinaryTree::BinaryTree() : _root(NULL), _size(0) {};

template <typename T>
map<T>::BinaryTree::BinaryTree(T value) {
    _root = new BinaryTreeNode(value);
    _size = 1;
};

template <typename T>
map<T>::BinaryTree::BinaryTree(const BinaryTree& other) {
    _root = _copy_nodes_in_pre_order_traversal(other._root);
    _size = other._size;
};

template <typename T>
map<T>::BinaryTree::~BinaryTree() {
    if (_root)
        _delete_in_post_order_traversal(_root);
};

template <typename T>
typename map<T>::BinaryTree map<T>::BinaryTree::operator=(const BinaryTree& other) {
    if (*this != other) {
        _delete_in_post_order_traversal(_root);
        _root = _copy_nodes_in_pre_order_traversal(other._root);
        _size = other._size;
    }
    return (*this);
};

template <typename T>
bool map<T>::BinaryTree::operator==(const BinaryTree& other) {
    bool result = true;
    _compare_in_order_traversal(this->_root, other._root, &result);
    return (result);
};

template <typename T>
bool map<T>::BinaryTree::operator!=(const BinaryTree& other) {
    return (!(this->_root == other._root));
};

template <typename T>
bool map<T>::BinaryTree::insert(const T& value) {
    BinaryTreeNode* nullPtr = NULL;

    return _insert_recursively(value, _root, &nullPtr);
};

template <typename T>
void map<T>::BinaryTree::printTree() {
    _print_tree_helper(_root, 0);
};

template <typename T>
size_t map<T>::BinaryTree::getSize(void) const { return this->_size; };


/*      /‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\
       C|               B I N A R Y   T R E E   N O D E               |Ↄ
        \_____________________________________________________________/      */
template <typename T>
map<T>::BinaryTree::BinaryTreeNode::BinaryTreeNode(T content, BinaryTreeNode* parent, BinaryTreeNode* smaller, BinaryTreeNode* greater) : _content(content), _parent(parent), _smaller(smaller), _greater(greater) {};

template <typename T>
map<T>::BinaryTree::BinaryTreeNode::~BinaryTreeNode(void) {};

template <typename T>
map<T>::BinaryTree::BinaryTreeNode::BinaryTreeNode(const BinaryTreeNode& other) {
    _content = T(other._content);
    _parent = other._parent;
    _smaller = other._smaller;
    _greater = other._greater;
};

template <typename T>
typename map<T>::BinaryTree::BinaryTreeNode& map<T>::BinaryTree::BinaryTreeNode::operator=(const BinaryTreeNode& other) {
    if (*this != other) {
        _content = other._content;
        _parent = other._parent;
        _smaller = other._smaller;
        _greater = other._greater;
    }
    return (*this);
};

template <typename T>
bool map<T>::BinaryTree::BinaryTreeNode::operator==(const BinaryTreeNode& rhs) {
    return (this->_content == rhs._content && this->_parent == rhs._parent && this->_smaller == rhs._smaller && this->_greater == rhs._greater);
}

template <typename T>
bool map<T>::BinaryTree::BinaryTreeNode::operator!=(const BinaryTreeNode& rhs) {
    return !(*this == rhs);
}

/*      /‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\
       C|           B I N A R Y   T R E E   I T E R A T O R           |Ↄ
        \_____________________________________________________________/      */
template <typename T>
map<T>::BinaryTreeIterator::BinaryTreeIterator(typename map<T>::BinaryTree::BinaryTreeNode* node) : _node(node){};

template <typename T>
map<T>::BinaryTreeIterator::~BinaryTreeIterator(void) {};

template <typename T>
T& map<T>::BinaryTreeIterator::operator*(void) {
    return _node->_content;
};

template <typename T>
T& map<T>::BinaryTreeIterator::operator*(void) const {
    return _node->_content;
};

template <typename T>
typename map<T>::BinaryTreeIterator& map<T>::BinaryTreeIterator::operator++() {
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
};

template <typename T>
bool map<T>::BinaryTreeIterator::operator==(const BinaryTreeIterator& rhs) {
    return (_node == rhs._node);
};

template <typename T>
bool map<T>::BinaryTreeIterator::operator!=(const BinaryTreeIterator& rhs) {
    return (!(*this == rhs));
};


/*      /‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\
       C|                            M A P                            |Ↄ
        \_____________________________________________________________/      */
/*=============================================================================
===  MEMBER FUNCTIONS                                                       ===
=============================================================================*/
// └----- Allocator

// └----- Element Access:

// └----- Iterators:
template <typename T>
typename map<T>::iterator map<T>::begin(void) {
    if (this->size() == 0)
        return (BinaryTreeIterator(NULL));

    typename BinaryTree::BinaryTreeNode* pivot = _container._root;
    while (pivot->_smaller)
        pivot = pivot->_smaller;
    return (BinaryTreeIterator(pivot));
};

template <typename T>
typename map<T>::const_iterator map<T>::begin(void) const {
    if (this->size() == 0)
        return (BinaryTreeIterator(NULL));

    typename BinaryTree::BinaryTreeNode* pivot = _container._root;
    while (pivot->_smaller)
        pivot = pivot->_smaller;
    return (BinaryTreeIterator(pivot));
};

template <typename T>
typename map<T>::iterator map<T>::end(void) {
    return (BinaryTreeIterator(NULL));
};

template <typename T>
typename map<T>::const_iterator map<T>::end(void) const {
    return (BinaryTreeIterator(NULL));
};

// └----- Capacity:
template <typename T>
bool map<T>::empty(void) const {
    return (size() == 0);
};

template <typename T>
typename map<T>::size_type map<T>::size(void) const {
    return _container.getSize();
};

// └----- Modifiers:
template <typename T>
bool map<T>::insert(value_type value) {
    return _container.insert(value);
};

// └----- Lookup:

// └----- Observers:

/*=============================================================================
===  CONSTRUCTION / DESTRUCTION                                             ===
=============================================================================*/
template <typename T>
map<T>::map() : _container(BinaryTree()) {};

template <typename T>
map<T>::~map() {};

/*=============================================================================
===  NON-MEMBER FUNCTIONS                                                   ===
=============================================================================*/
// TODO: remover
template <typename T>
std::ostream& operator<<(std::ostream& os, const typename map<T>::BinaryTree::BinaryTreeNode& node) {
    os << node._content;
    return os;
};

/******************************************************************************/
/*   OPERATOR OVERLOADS                                                       */
/******************************************************************************/

}  // namespace ft

#endif