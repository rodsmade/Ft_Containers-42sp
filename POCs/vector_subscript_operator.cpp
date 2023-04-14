#include <iostream>
#include <vector>

int main() {
    std::vector<int> vetor(5, 42);

    vetor[0] = 43;
    // vetor[50] = 44;

    for (std::vector<int>::iterator it = vetor.begin(); it != vetor.end(); it++)
        std::cout << *it << std::endl;

    int i = -1;
    while (std::cin >> i && i !=-1)
        try {
            std::cout << "v[" << i << "]==" << vetor.at(i) << "\n";
        } catch (const std::exception &e) {
            std::cout << "bad index: " << i << "\n";
        }

    // conclusão: o at estoura uma exceção se o acesso for inválido. o [] não, é totalmente desprotegido (e perigoso).
}