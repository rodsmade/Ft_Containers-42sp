#include "map_tests.hpp"

static void test_insert(void) {
    std::cout << "  Insert" << std::endl;
    std::cout << "   └ Single Element ( insert(const value_type& value) )" << std::endl;

    ft::map<int> testMap;

    bool insertionReturn = true;

    insertionReturn = insertionReturn && testMap.insert(42);
    assert(testMap.size() == 1 && insertionReturn == true, "Insertion of one element successful");

    insertionReturn = insertionReturn && testMap.insert(43);
    assert(testMap.size() == 2 && insertionReturn == true, "Insertion of one element greater than _root successful");

    insertionReturn = insertionReturn && testMap.insert(41);
    assert(testMap.size() == 3 && insertionReturn == true, "Insertion of one element smaller than _root successful");
}

void test_map_modifiers(void) {
    std::cout << "\n=== Map Modifiers ===" << std::endl;
    test_insert();
}