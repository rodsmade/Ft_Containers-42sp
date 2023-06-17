#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <cstddef>

namespace ft {

// template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T> > >
template <class T, class Compare = std::less<T>, class Allocator = std::allocator<T> >
class BinaryTreeNode {
   public:
    Allocator       _allocator;
    Compare         _compare;
    T               _content;
    BinaryTreeNode  *_smaller;
    BinaryTreeNode  *_greater;

   public:
    BinaryTreeNode(const T &value, const Compare& comp = Compare(), const Allocator& alloc = Allocator());
    BinaryTreeNode(const BinaryTreeNode &other);
    ~BinaryTreeNode();
    BinaryTreeNode &operator=(const BinaryTreeNode &other);
};

template <class T, class Compare = std::less<T>, class Allocator = std::allocator<T> >
class BinaryTree {
   private:
    Allocator                               _allocator;
    Compare                                 _compare;
    BinaryTreeNode<T, Compare, Allocator>   *_root;
    size_t                                  _size;
    size_t                                  _height;
    bool                                    _cleared;

    void insertRecursive(BinaryTreeNode<T, Compare, Allocator> *&current, const T &value);

    void deleteRecursive(BinaryTreeNode<T, Compare, Allocator> *&current);

    bool lookupRecursive(BinaryTreeNode<T, Compare, Allocator> *&current, const T&value);

    // Helper function for printing the tree
    void printTreeHelper(BinaryTreeNode<T, Compare, Allocator>* current, int level);

   public:
    /*=============================================
    ===                ALIASES                  ===
    =============================================*/
    typedef Allocator allocator_type;
    typedef Compare key_compare;

    BinaryTree(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
    BinaryTree(const BinaryTree &other);
    ~BinaryTree();
    BinaryTree &operator=(const BinaryTree &other);

    // Accessors
    size_t  getSize(void) const;
    size_t  getHeight(void) const;

    // Public function to print the tree
    void printTree();

    // Modifiers
    void    insert(const T &newValue);
    void    clear(void);

    // Lookup
    bool    has(const T&value);
};

/*=============================================
===          NON-MEMBER FUNCTIONS           ===
=============================================*/
/*********************************************/
/*           OPERATOR OVERLOADS              */
/*********************************************/
// TODO: só vai sair quando tiver ITERADORES CARAI
// template <class T, class Compare, class Allocator>
// bool operator==(const BinaryTree<T, Compare, Allocator>& lhs, const BinaryTree<T, Compare, Allocator>& rhs);
// template <class T, class Compare, class Allocator>
// bool operator!=(const BinaryTree<T, Compare, Allocator>& lhs, const BinaryTree<T, Compare, Allocator>& rhs);

}  // namespace ft

#include "BinaryTree.tpp"

#endif