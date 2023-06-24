#include <iostream>

namespace ft {
template <typename T>
class BinaryTreeNode {
   private:
    T _content;
    BinaryTreeNode* _smaller;
    BinaryTreeNode* _greater;

   public:
    BinaryTreeNode(T content = T(), BinaryTreeNode* smaller = NULL, BinaryTreeNode* greater = NULL) : _content(content), _smaller(smaller), _greater(greater){};
    ~BinaryTreeNode() {};
    BinaryTreeNode(const BinaryTreeNode& other) {
        std::cout << "copy constructor\n";
        _content = T(other._content);
        _smaller = other._smaller;
        _greater = other._greater;
    };

    BinaryTreeNode<T> &operator=(const BinaryTreeNode<T> &other) {
        std::cout << "assignment operator\n";
        if (*this != other) {
            _content = other._content;
            _smaller = other._smaller;
            _greater = other._greater;
        }
        return (*this);
    }

    bool operator==(const BinaryTreeNode<T> &rhs) {
        return (this->_content == rhs._content
                && this->_smaller == rhs._smaller
                && this->_greater == rhs._greater);
    }

    bool operator!=(const BinaryTreeNode<T> &rhs) {
        return !(*this == rhs);
    }

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const BinaryTreeNode<U>& node);
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const BinaryTreeNode<T>& node) {
    os << node._content;
    return os;
}

}  // namespace ft

int main() {
    ft::BinaryTreeNode<std::string> node2("DOIS");
    ft::BinaryTreeNode<std::string> node3("TRES");
    ft::BinaryTreeNode<std::string> node1("UM", &node2, &node3);
    ft::BinaryTreeNode<std::string> node4(node1);
    ft::BinaryTreeNode<std::string> node5;
    node5 = node2;

    std::cout << std::endl;
    std::cout << node1 << std::endl;
    std::cout << node2 << std::endl;
    std::cout << node3 << std::endl;
    std::cout << node4 << std::endl;
    std::cout << node5 << std::endl;

    node1 = ft::BinaryTreeNode<std::string>("NOVO UM");

    std::cout << std::endl;
    std::cout << node1 << std::endl;
    std::cout << node2 << std::endl;
    std::cout << node3 << std::endl;
    std::cout << node4 << std::endl;
    std::cout << node5 << std::endl;
}
