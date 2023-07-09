#ifndef FT_MAP_TPP
#define FT_MAP_TPP

namespace ft {

/*      /‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\
       C|                    B I N A R Y   T R E E                    |Ↄ
        \_____________________________________________________________/      */

/*      /‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\
       C|               B I N A R Y   T R E E   N O D E               |Ↄ
        \_____________________________________________________________/      */

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
template <typename T>
void map<T>::insert(T value) {
    _container.insert(value);
};

template <typename T>
typename map<T>::size_type map<T>::size(void) {
    return _container.getSize();
};

template <typename T>
bool map<T>::empty(void) {
    return (size() == 0);
};

template <typename T>
typename map<T>::BinaryTreeIterator map<T>::begin(void) {
    typename BinaryTree::BinaryTreeNode* pivot = _container._root;
    while (pivot->_smaller)
        pivot = pivot->_smaller;
    return (BinaryTreeIterator(pivot));
};

template <typename T>
typename map<T>::BinaryTreeIterator map<T>::end(void) {
    return (BinaryTreeIterator(NULL));
};

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
template <typename T>
std::ostream& operator<<(std::ostream& os, const typename map<T>::BinaryTree::BinaryTreeNode& node) {
    os << node._content;
    return os;
};

}  // namespace ft

#endif