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
        class BinaryTreeNode {
           private:
            // Prototypes
            friend class BinaryTree;
            template <typename U>
            friend class map;

            // Private members
            T               _content;
            BinaryTreeNode* _parent;
            BinaryTreeNode* _smaller;
            BinaryTreeNode* _greater;

           public:
            BinaryTreeNode(T content = T(), BinaryTreeNode* parent = NULL, BinaryTreeNode* smaller = NULL, BinaryTreeNode* greater = NULL);
            ~BinaryTreeNode(void);
            BinaryTreeNode(const BinaryTreeNode& other);

            BinaryTreeNode& operator=(const BinaryTreeNode& other);
            bool            operator==(const BinaryTreeNode& rhs);
            bool            operator!=(const BinaryTreeNode& rhs);
        };

        // Friend classes/functinos:
        friend class map;
        // TODO: REMOVER?
        template <typename U>
        friend std::ostream& operator<<(std::ostream& os, const BinaryTreeNode& node);

        // Attributes
        BinaryTreeNode* _root;
        size_t          _size;

        /*=============================================
        ===        PRIVATE MEMBER FUNCTIONS         ===
        =============================================*/
        bool            _insert_recursively(const T& value, BinaryTreeNode*& current_node, BinaryTreeNode** parent_node);
        void            _delete_in_post_order_traversal(BinaryTreeNode* current_node);
        BinaryTreeNode* _copy_nodes_in_pre_order_traversal(BinaryTreeNode* current_node);
        void            _print_tree_helper(BinaryTreeNode* current_node, int level);
        void            _compare_in_order_traversal(BinaryTreeNode* lhs, BinaryTreeNode* rhs, bool* result);

       public:
        BinaryTree();
        BinaryTree(T value);
        BinaryTree(const BinaryTree& other);
        ~BinaryTree();

        BinaryTree  operator=(const BinaryTree& other);
        bool        operator==(const BinaryTree& other);
        bool        operator!=(const BinaryTree& other);
        bool        insert(const T& value) ;
        void        printTree();
        size_t      getSize(void);
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

    bool                insert(T value);
    size_type           size(void);
    bool                empty(void);

    BinaryTreeIterator  begin(void);
    BinaryTreeIterator  end(void);

    /*=============================================
    ===      CONSTRUCTION / DESTRUCTION         ===
    =============================================*/
    map();
    ~map();
};

// TODO: remover eu acho 
template <typename T>
std::ostream& operator<<(std::ostream& os, const typename map<T>::BinaryTree::BinaryTreeNode& node);

};  // namespace ft

#include "ft_map.tpp"

#endif