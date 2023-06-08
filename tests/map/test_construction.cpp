#include "map_tests.hpp"

// template <typename T>
// static void test_empty_map_creation(std::string typeName) {
//     try {
//         ft::map<T> ftMap;

//         assert(true, "Empty ft::map<" + typeName + "> creation");
//     } catch (const std::exception& e) {
//         std::cerr << TEST_NOK << e.what() << std::endl;
//     }
// }

// template <typename T>
// static void test_against_std_empty_map_creation(std::string typeName) {
//     try {
//         ft::map<T> ftMap;
//         std::map<T> stdMap;

//         assert(ftMap.size() == stdMap.size() && ftMap.empty() == stdMap.empty(), "Empty ft::map<" + typeName + "> against empty std::map<" + typeName + "> creation");
//     } catch (const std::exception& e) {
//         std::cerr << TEST_NOK << e.what() << std::endl;
//     }
// }

// static void test_copy_constructor() {
//     std::cout << "\n  Copy Constructor\t==>\tmap(const map& other):" << std::endl;
//     {
//         ft::map<double> ftMap;

//         // create map
//         for (int i = 0; i < 10; i++)
//             ftMap.push(42 + i);

//         ft::map<double> copyMap(ftMap);

//         bool consistencyCheck = true;

//         for (int i = 0; i < 10; i++) {
//             consistencyCheck = consistencyCheck && (ftMap.top() == copyMap.top());
//             ftMap.pop();
//             copyMap.pop();
//         }

//         assert(copyMap.size() == ftMap.size(), "Copy constructor size check");
//         assert(consistencyCheck, "Copied elements integrity check");
//     }
//     {
//         ft::map<double> ftMap;

//         // create map
//         for (int i = 0; i < 10; i++)
//             ftMap.push(42 + i);

//         ft::map<double> copyMap(ftMap);

//         ftMap.pop();
//         ftMap.pop();
//         ftMap.pop();
//         ftMap.pop();
//         ftMap.pop();

//         assert(ftMap.size() != copyMap.size()
//                 && ftMap.top() != copyMap.top()
//                 , "Check for hard copy");

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

    ft::map<int> testMap;
    assert(testMap.size() == 0 && testMap.empty() == true, "Construction of empty map");

    return ;
}
