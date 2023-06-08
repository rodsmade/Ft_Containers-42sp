#include "map_tests.hpp"

template <typename T>
static void test_empty_map_creation(std::string typeName) {
    try {
        ft::map<T> ftMap;

        assert(ftMap.size() == 0 && ftMap.empty() == true, "Empty ft::map<" + typeName + "> creation");
    } catch (const std::exception& e) {
        std::cerr << TEST_NOK << e.what() << std::endl;
    }
}

static void test_default_constructor() {
    std::cout << "  Default Constructor ==>\tmap<T>():" << std::endl;

    test_empty_map_creation<double>("double");
    test_empty_map_creation<float>("float");
    test_empty_map_creation<std::string>("std::string");
    test_empty_map_creation<ft::map<double> >("ft::map<double>");
    test_empty_map_creation<Has_default>("Has_default");
    test_empty_map_creation<No_default>("No_default");
};

// static void test_copy_constructor() {
//     std::cout << "\n  Copy Constructor\t==>\tmap(const map& other):" << std::endl;
//     {
//         ft::map<int> ftMap;

//         // create map
//         for (int i = 0; i < 10; i++) {
//             if (i % 2)
//                 ftMap.insert(42 + i);
//             else
//                 ftMap.insert(42 - i);
//         }

//         ft::map<int> copyMap(ftMap);

//         // bool consistencyCheck = true;

//         // for (int i = 0; i < 10; i++) {
//         //     consistencyCheck = consistencyCheck && (ftMap.top() == copyMap.top());
//         //     ftMap.pop();
//         //     copyMap.pop();
//         // }

//         assert(copyMap.size() == ftMap.size(), "Copy constructor size check");
//         assert(false, "Consistency check - Só vai dar pra terminar isso aqui quando tiver iterador");
//         // assert(consistencyCheck, "Copied elements integrity check");
//     }
//     {
//         ft::map<int> ftMap;

//         // create map
//         for (int i = 0; i < 10; i++) {
//             if (i % 2)
//                 ftMap.insert(42 + i);
//             else
//                 ftMap.insert(42 - i);
//         }

//         ft::map<int> copyMap(ftMap);

//         ftMap.insert(0);
//         ftMap.insert(10);
//         ftMap.insert(20);
//         ftMap.insert(30);

//         assert(ftMap.size() != copyMap.size(), "Check for hard copy.");
//     }
// };

// static void test_default_constructor(void) {
//     std::cout << "  Default Constructor\t==>\tmap<T, Container>(void):" << std::endl;
//     test_empty_map_creation<double>("double");
//     test_empty_map_creation<float>("float");
//     test_empty_map_creation<std::string>("std::string");
//     test_empty_map_creation<ft::map<double> >("ft::map<double>");
//     test_empty_map_creation<Has_default>("Has_default");
//     test_empty_map_creation<No_default>("No_default");
//     test_against_std_empty_map_creation<double>("double");
//     test_against_std_empty_map_creation<float>("float");
//     test_against_std_empty_map_creation<std::string>("std::string");
//     test_against_std_empty_map_creation<ft::map<double> >("ft::map<double>");
//     test_against_std_empty_map_creation<Has_default>("Has_default");
//     test_against_std_empty_map_creation<No_default>("No_default");
// }

void test_map_construction(void) {
    std::cout << "\n=== Map construction ===" << std::endl;

    test_default_constructor();
    assert(false, "Cant write copy constructor tests while iterators havent been implemented");
    // test_copy_constructor();

    return ;
}
