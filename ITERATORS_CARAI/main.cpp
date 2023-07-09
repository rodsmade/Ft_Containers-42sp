#include <iomanip>  // std::boolalpha

#include "ft_map.hpp"

int main() {
    ft::map<int> teste;
    std::cout << std::boolalpha;
    std::cout << "empty: " << teste.empty() << "\n";
    std::cout << "size: " << teste.size() << "\n";
    teste.insert(42);
    teste.insert(1);
    teste.insert(-3);
    teste.insert(37);
    teste.insert(14);
    teste.insert(23);
    teste.insert(5);
    teste.insert(6);
    teste.insert(9);
    teste.insert(369);
    teste.insert(52);
    teste.insert(43);
    teste.insert(69);
    teste.insert(323);
    teste.insert(87);
    teste.insert(326);
    teste.insert(2207);
    teste.insert(1813);
    teste.insert(6549);
    teste.insert(649);
    teste.insert(2042);
    teste.insert(619);
    teste.insert(443);
    teste.insert(400);
    teste.insert(949);
    teste.insert(777);
    std::cout << "empty: " << teste.empty() << "\n";
    std::cout << "size: " << teste.size() << "\n";

    for (ft::map<int>::iterator it = teste.begin(); it != teste.end(); ++it)
        std::cout << "begin iterator: " << *it << "\n";

    // ft::map<int>::iterator it = teste.begin();
    // for (ft::map<int>::size_type i = 0; i < teste.size(); i++) {
    //     std::cout << "begin iterator: " << *it << "\n";
    //     ++it;
    // }

    // std::cout << "begin iterator: " << *it << "\n";
    // ++it;
    // std::cout << "begin iterator: " << *it << "\n";
    // ++it;
    // std::cout << "begin iterator: " << *it << "\n";
    // ++it;
    // std::cout << "begin iterator: " << *it << "\n";

    teste.get_bin_tree().printTree();
    return 0;
}

// int main() { // BinaryTree tests!!
//     ft::BinaryTree<int> teste1;
//     teste1.insert(1);
//     teste1.insert(2);
//     teste1.insert(3);
//     ft::BinaryTree<int> teste2(42);
//     teste2.insert(43);
//     teste2.insert(44);
//     ft::BinaryTree<int> teste3(teste2);
//     ft::BinaryTree<int> teste4;
//     teste4 = teste1;
//
//     teste1.insert(6);
//     teste1.insert(5);
//     teste1.insert(4);
//     teste2.insert(41);
//     teste2.insert(40);
//
//     std::cout << "\nTeste 1: (size: " << teste1.getSize() << ")\n";
//     teste1.printTree();
//
//     std::cout << "\nTeste 2: (size: " << teste2.getSize() << ")\n";
//     teste2.printTree();
//     std::cout << "\nTeste 3: (size: " << teste3.getSize() << ")\n";
//     teste3.printTree();
//     std::cout << "\nTeste 4: (size: " << teste4.getSize() << ")\n";
//     teste4.printTree();
//
//     std::cout << std::boolalpha << std::endl;
//     std::cout << "teste1 == teste1: " << (teste1 == teste1) << std::endl;
//     std::cout << "teste1 == teste2: " << (teste1 == teste2) << std::endl;
//     std::cout << "teste1 == teste3: " << (teste1 == teste3) << std::endl;
//     std::cout << "teste1 == teste4: " << (teste1 == teste4) << std::endl;
//     std::cout << "teste2 == teste2: " << (teste2 == teste2) << std::endl;
//     std::cout << "teste2 == teste3: " << (teste2 == teste3) << std::endl;
//     std::cout << "teste2 == teste4: " << (teste2 == teste4) << std::endl;
//     std::cout << "teste3 == teste3: " << (teste3 == teste3) << std::endl;
//     std::cout << "teste3 == teste4: " << (teste3 == teste4) << std::endl;
//     std::cout << "teste4 == teste4: " << (teste4 == teste4) << std::endl;
// }

// int main() { // BinaryTreeNode Tests!!
//     ft::BinaryTreeNode<std::string> node2("DOIS");
//     ft::BinaryTreeNode<std::string> node3("TRES");
//     ft::BinaryTreeNode<std::string> node1("UM", &node2, &node3);
//     ft::BinaryTreeNode<std::string> node4(node1);
//     ft::BinaryTreeNode<std::string> node5;
//     node5 = node1;
//
//     std::cout << std::endl;
//     std::cout << node1 << std::endl;
//     std::cout << node2 << std::endl;
//     std::cout << node3 << std::endl;
//     std::cout << node4 << std::endl;
//     std::cout << node5 << std::endl;
//
//     node1 = ft::BinaryTreeNode<std::string>("NOVO UM");
//
//     std::cout << std::endl;
//     std::cout << node1 << std::endl;
//     std::cout << node2 << std::endl;
//     std::cout << node3 << std::endl;
//     std::cout << node4 << std::endl;
//     std::cout << node5 << std::endl;
// }
