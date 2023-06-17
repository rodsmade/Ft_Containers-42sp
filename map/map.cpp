#include <map>
#include <vector>
#include <iostream>
#include <typeinfo>

// A class that does not have a default constructor.
class No_default {
   private:
    int _value;
   public:
    No_default(int arg) {
        _value = arg;
    };  // the only constructor for No_default
    bool operator==(const No_default& other) const {
        return (_value == other._value);
    };
    bool operator<(const No_default &other) const {
        return (_value < other._value);
    }
};

int main()
{
    std::map<std::string, std::string> mymap;

    mymap.insert(std::pair<std::string, std::string>("inazuma ", "shines eternal"));

    std::map<std::string, std::string>::iterator it = mymap.begin();
    std::cout << typeid(it).name() << "\n";
    std::cout << typeid(*it).name() << "\n";
    // std::cout << it << "\n";
    // std::cout << (*it) << "\n";
    std::cout << (*it).first << "\n";
    std::cout << (*it).second << "\n";

    return 0;
}
// {
//     std::map<No_default, No_default> mymap;


//     std::cout << mymap.size() << "\n";
//     mymap.insert(std::pair<No_default, No_default>(No_default(8), No_default(80)));
//     std::cout << mymap.size() << "\n";

    
//     // mymap.insert(std::pair<No_default, No_default>(No_default(6), No_default(60)));
//     // mymap.insert(std::pair<No_default, No_default>(No_default(4), No_default(40)));
//     // mymap.insert(std::pair<No_default, No_default>(No_default(5), No_default(50)));
//     // mymap.insert(std::pair<No_default, No_default>(No_default(1), No_default(10)));
//     // mymap.insert(std::pair<No_default, No_default>(No_default(9), No_default(90)));
//     // mymap.insert(std::pair<No_default, No_default>(No_default(7), No_default(70)));
//     // mymap.insert(std::pair<No_default, No_default>(No_default(2), No_default(20)));
//     // mymap.insert(std::pair<No_default, No_default>(No_default(10), No_default(100)));
//     // mymap.insert(std::pair<No_default, No_default>(No_default(3), No_default(30)));

//     // int i = 0;
//     // for (std::map<No_default, No_default>::iterator it = mymap.begin(); it != mymap.end(); it++) {
//     //     std::cout<< "element " << i << " [" << &(*it) << "] : (" << it->first << "," << it->second << ")\n";
//     //     i++;
//     // }

//     // std::vector<int> myvec;

//     // myvec.push_back(10);
//     // myvec.push_back(20);
//     // myvec.push_back(30);
//     // myvec.push_back(40);
//     // myvec.push_back(50);
//     // myvec.push_back(60);
//     // myvec.push_back(70);
//     // myvec.push_back(80);
//     // myvec.push_back(90);
//     // myvec.push_back(100);

//     // int j = 0;
//     // for (std::vector<int>::iterator it = myvec.begin(); it != myvec.end(); it++) {
//     //     std::cout<< "element " << j << " [" << &(*it) << "]\n";
//     //     j++;
//     // }

//     return 0;
// }