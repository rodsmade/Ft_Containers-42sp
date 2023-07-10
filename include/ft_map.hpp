#ifndef FT_MAP_HPP
#define FT_MAP_HPP

#include <iostream>

namespace ft {

// template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T> > >
template <typename T>
class map {
   private:
    /*=============================================
    ===        AUXILIARY IMPLEMENTATIONS        ===
    =============================================*/
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
        size_t      getSize(void) const;
    };

    class BinaryTreeIterator {
       private:
        typename BinaryTree::BinaryTreeNode* _node;

       public:
        BinaryTreeIterator(typename BinaryTree::BinaryTreeNode* node);
        ~BinaryTreeIterator(void);

        T&                  operator*(void);
        T&                  operator*(void) const;
        BinaryTreeIterator& operator++(void);
        bool                operator==(const BinaryTreeIterator& rhs);
        bool                operator!=(const BinaryTreeIterator& rhs);
    };

    /*=============================================
    ===              ATTRIBUTES                 ===
    =============================================*/
    BinaryTree _container;

   public:
    /*=============================================
    ===                ALIASES                  ===
    =============================================*/
    typedef T value_type;
    // typedef Key key_type;
    // typedef std::pair<const Key, T> value_type;
    typedef size_t size_type;
    // typedef Compare key_compare;
    // typedef T mapped_type;
    // typedef std::ptrdiff_t difference_type;
    // typedef Allocator allocator_type;
    // typedef [...] reference;
    // typedef [...] const_reference;
    // typedef [...] pointer;
    // typedef [...] const_pointer;
    typedef BinaryTreeIterator iterator;
    typedef const BinaryTreeIterator const_iterator;
    // typedef [...] reverse_iterator;
    // typedef [...] const_reverse_iterator;

    /*=============================================
    ===            MEMBER FUNCTIONS             ===
    =============================================*/
    // TODO: REMOVE
    BinaryTree& get_bin_tree(void) { return _container; };

    // Allocator:
    // allocator_type                   get_allocator() const;

    // Element Access:
    // T&                               at( const Key& key );
    // const T&                         at( const Key& key ) const;
    // T&                               operator[]( const Key& key );

    // Iterators:
    iterator                        begin(void);
    const_iterator                  begin(void) const;
    iterator                        end(void);
    const_iterator                  end(void) const;
    // reverse_iterator                            rbegin(); // = 1 before o menor elemento de todos
    // const_reverse_iterator                      rbegin() const;
    // reverse_iterator                            rend(); // o maior elemento de todos
    // const_reverse_iterator                      rend() const;

    // Capacity:
    bool                    empty(void) const;
    // size_type                                   max_size() const;
    size_type               size(void) const;

    // Modifiers:
    // void                    clear();
    // iterator                                    erase( iterator pos );
    // iterator                                    erase( iterator first, iterator last );
    // ATTENTION: TO IGNORANDO TUDO O QUE É KEY E TROCANDO PRA T, DEPOIS VOLTAR !!!!!!
    // size_type                                   erase( const Key& key ); // original
    // size_type               erase( const T& key ); // adaptado pra T
    // std::pair<iterator, bool>                   insert(const value_type& value);
    // TODO: adequar o protótipo abaixo (devolve bool) pro de cima (devolve pair<iterator, bool>)
    bool                    insert(value_type value);
    // iterator                                    insert( iterator pos, const value_type& value );
    // template< class InputIt >
    // void                                        insert( InputIt first, InputIt last );
    // void                                        swap( map& other );

    // Lookup:
    // size_type                                   count( const Key& key ) const;
    // iterator                                    find( const Key& key );
    // const_iterator                              find( const Key& key ) const;
    // std::pair<iterator,iterator>                equal_range( const Key& key );
    // std::pair<const_iterator,const_iterator>    equal_range( const Key& key ) const;
    // iterator                                    lower_bound( const Key& key );
    // const_iterator                              lower_bound( const Key& key ) const;
    // iterator                                    upper_bound( const Key& key );
    // const_iterator                              upper_bound( const Key& key ) const;

    // Observers:
    // key_compare                                 key_comp() const;
    // ft::map::value_compare                      value_comp() const;


    /*=============================================
    ===      CONSTRUCTION / DESTRUCTION         ===
    =============================================*/
    // Default:
    // TODO: adequar pro prototipo original
    // explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
    map();

    // Range:
    // template <class InputIterator>
    // map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());

    // Copy::
    // map(const map& other);

    // Destructor:
    ~map();

    /*=============================================
    ===           OPERATOR OVERLOADS            ===
    =============================================*/
    // map& operator=(const map& other);
};

// TODO: remover eu acho 
template <typename T>
std::ostream& operator<<(std::ostream& os, const typename map<T>::BinaryTree::BinaryTreeNode& node);

/*=============================================
===          NON-MEMBER FUNCTIONS           ===
=============================================*/
/*********************************************/
/*           OPERATOR OVERLOADS              */
/*********************************************/
// template <class T, class Compare, class Allocator>
// bool operator==(const map<T, Compare, Allocator>& lhs, const map<T, Compare, Allocator>& rhs);
// template <class T, class Compare, class Allocator>
// bool operator!=(const map<T, Compare, Allocator>& lhs, const map<T, Compare, Allocator>& rhs);
// template <class T, class Compare, class Allocator>
// bool operator<(const map<T, Compare, Allocator>& lhs, const map<T, Compare, Allocator>& rhs);
// template <class T, class Compare, class Allocator>
// bool operator<=(const map<T, Compare, Allocator>& lhs, const map<T, Compare, Allocator>& rhs);
// template <class T, class Compare, class Allocator>
// bool operator>(const map<T, Compare, Allocator>& lhs, const map<T, Compare, Allocator>& rhs);
// template <class T, class Compare, class Allocator>
// bool operator>=(const map<T, Compare, Allocator>& lhs, const map<T, Compare, Allocator>& rhs);

/*********************************************/
/*                  OTHER                    */
/*********************************************/
// template <class Key, class Compare, class Allocator>
// void swap(ft::map<Key, Compare, Allocator>& lhs, ft::map<Key, Compare, Allocator>& rhs );
// template <class T, class Compare, class Allocator>
// void swap(ft::map<T, Compare, Allocator>& lhs, ft::map<T, Compare, Allocator>& rhs );

};  // namespace ft

#include "ft_map.tpp"

#endif