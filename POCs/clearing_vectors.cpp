// clearing vectors
#include <algorithm>
#include <iostream>
#include <vector>

int main ()
// {
//   std::vector<int> myvector;
//   myvector.push_back (100);
//   myvector.push_back (200);
//   myvector.push_back (300);

//   std::cout << "myvector contains:";
//   for (unsigned i=0; i<myvector.size(); i++)
//     std::cout << ' ' << myvector[i];
//   std::cout << '\n';

//   std::cout << "Before clear: ";
//   std::cout << "capacity: " << myvector.capacity() << " size: " << myvector.size() << std::endl;
//   myvector.clear();
//   std::cout << "After clear: ";
//   std::cout << "capacity: " << myvector.capacity() << " size: " << myvector.size() << std::endl;
//   std::cout << "myvector contains:";
//   for (unsigned i=0; i<myvector.capacity(); i++)
//     std::cout << ' ' << myvector[i];
//   std::cout << '\n';



//   myvector.push_back (1101);
//   myvector.push_back (2202);

//   std::cout << "myvector contains:";
//   for (unsigned i=0; i<myvector.size(); i++)
//     std::cout << ' ' << myvector[i];
//   std::cout << '\n';

//   return 0;
// }
{
    std::vector<int> container{1, 2, 3};
 
    auto print = [](const int& n) { std::cout << " " << n; };
 
    container.push_back(200);
    container.reserve(5);

    std::cout << "Before clear:";
    std::for_each(container.begin(), container.end(), print);
    std::cout << "\nSize=" << container.size() << ", Capacity=" << container.capacity() << '\n';
 
    std::cout << "Clear\n";
    container.clear();
 
    std::cout << "After clear:";
    std::for_each(container.begin(), container.end(), print);
    std::cout << "\nSize=" << container.size() << ", Capacity=" << container.capacity() << '\n';
}