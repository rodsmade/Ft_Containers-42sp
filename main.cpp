#include "ft_containers.hpp"

struct No_default {
    No_default(int ay) {
        (void) ay;
    };  // the only constructor for No_default
};

void test_vector_creation() {
    unsigned int intendedSize = 42;
    ft::vector<double> testVector(intendedSize);

    {  // Testing Initialisation of values
        std::cout << "Initialisation values: ";
        for (unsigned int i = 0; i < testVector.size(); i++) {
            if (testVector[i] != 0)
                std::cout << BOLD LIGHT_RED "NOK" RESET;
        }
        std::cout << BOLD LIGHT_GREEN "OK" RESET;
        std::cout << std::endl;
    }
    {   // Testing Valid set() operation at valid index
        std::cout << "Setting value at valid index: ";

        double designatedValue = 42.0;
        unsigned int designatedIndex = 12;

        testVector[designatedIndex] = designatedValue;
        if (testVector[designatedIndex] == designatedValue)
            std::cout << BOLD LIGHT_GREEN "OK" RESET;
        else
            std::cout << BOLD LIGHT_RED "NOK" RESET;
        std::cout << std::endl;
    }
    {  // Testing copy construction
        ft::vector<double> copyVector(testVector);

        std::cout << "Copy-construction: ";
        bool sizeTest = true;
        bool elementsTest = true;

        sizeTest = (copyVector.size() == testVector.size());

        for (unsigned int i = 0; i < copyVector.size(); i++) {
            if (copyVector[i] != testVector[i]) {
                elementsTest = false;
                break;
            }
        }

        if (sizeTest && elementsTest)
            std::cout << BOLD LIGHT_GREEN "OK" RESET;
        else
            std::cout << BOLD LIGHT_RED "NOK" RESET;
        std::cout << std::endl;

        std::cout << "Test for hard copy: ";

        double originalValueInTestVector = testVector[41];
        double originalValueInCopyVector = copyVector[0];

        testVector[0] = 42.0;
        copyVector[41] = 1.0;

        if (testVector[41] == originalValueInTestVector && copyVector[0] == originalValueInCopyVector)
            std::cout << BOLD LIGHT_GREEN "OK" RESET;
        else
            std::cout << BOLD LIGHT_RED "NOK" RESET;
        std::cout << std::endl;
    }
    {  // Testing assignment operator (operator=)
        ft::vector<double> assignedVector = testVector;

        std::cout << "Basic assignment: ";
        bool sizeTest = true;
        bool elementsTest = true;

        sizeTest = (assignedVector.size() == testVector.size());

        for (unsigned int i = 0; i < assignedVector.size(); i++) {
            if (assignedVector[i] != testVector[i]) {
                elementsTest = false;
                break;
            }
        }

        if (sizeTest && elementsTest)
            std::cout << BOLD LIGHT_GREEN "OK" RESET;
        else
            std::cout << BOLD LIGHT_RED "NOK" RESET;
        std::cout << std::endl;

        std::cout << "Test for hard copy: ";

        double originalValueInTestVector = testVector[41];
        double originalValueInAssignedVector = assignedVector[0];

        testVector[0] = 42.0;
        assignedVector[41] = 1.0;

        if (testVector[41] == originalValueInTestVector && assignedVector[0] == originalValueInAssignedVector)
            std::cout << BOLD LIGHT_GREEN "OK" RESET;
        else
            std::cout << BOLD LIGHT_RED "NOK" RESET;
        std::cout << std::endl;

        std::cout << "Assignment to self: ";
        // TODO: implementar exception e alterar aqui
        std::cout << BOLD LIGHT_GREEN "OK" RESET << std::endl;
    }
}

void test_vector_access() {
    unsigned int size = 10;
    ft::vector<double> myVector(size);
    const ft::vector<double> &myVectorRef = myVector;

    {  // Testing initialising vector values
        std::cout << "Initialising vector values: ";
        for (unsigned int i = 0; i < size; i++)
            myVector[i] = i * 0.1;
        for (unsigned int i = 0; i < size; i++) {
            if (myVector[i] != i * 0.1)
                std::cout << BOLD LIGHT_RED "NOK" RESET;
        }
        std::cout << BOLD LIGHT_GREEN "OK" RESET;
        std::cout << std::endl;
    }
    {
        std::cout << "Accessing vector values: ";
        for (unsigned int i = 0; i < size; i++) {
            if (myVector[i] != i * 0.1)
                std::cout << BOLD LIGHT_RED "NOK" RESET;
        }
        std::cout << BOLD LIGHT_GREEN "OK" RESET;
        std::cout << std::endl;
    }
    {
        int index = 2;
        std::cout << "Testing accessors by reference: ";
        myVector[index] = 42;
        (myVectorRef[index] != myVector[index]) ? (std::cout << BOLD LIGHT_RED "NOK" RESET) : (std::cout << BOLD LIGHT_GREEN "OK" RESET);
        std::cout << " ";

        index = 9;
        myVector[index] = -42;
        (myVectorRef[index] != myVector[index]) ? (std::cout << BOLD LIGHT_RED "NOK" RESET) : (std::cout << BOLD LIGHT_GREEN "OK" RESET);
        std::cout << " ";

        index = 0;
        myVector[index] = 24;
        (myVectorRef[index] != myVector[index]) ? (std::cout << BOLD LIGHT_RED "NOK" RESET) : (std::cout << BOLD LIGHT_GREEN "OK" RESET);
        std::cout << std::endl;
    }
}

int main() {
    // Vector creation test
    std::cout << "Vector creation tests:" << std::endl;
    test_vector_creation();
    std::cout << std::endl;

    // Accessing elements of Vector
    std::cout << "Vector accessor tests (subscript operator):" << std::endl;
    test_vector_access();

    // TODO: testes de assignment com vetor fonte maior, menor e igual que vetor destino.
    // TODO: testes de inicialização de capacity
    // TODO: testes de inicialização de uma classe sem default (No_Default)
    // TODO: testes de reserve
    // TODO: testes do reserve e resize comparando com o resultado da std library (tipo a POC)
    // TODO: testes do push_back, comparar sizes e capacitys do vetor com o da std
    // TODO: escrever teste de assignment operator e comparar sizes e capacitys com os da std
    //          todos os testes de copy e assignment vale a pena checar o size e capacity contra a std lib
    // TODO: escrever teste de protected value access (at) comparando com a std::vector
    // TODO: escrever teste de protected value access (at) comparando com a std::vector
    //          - obs: se não usar bloco de try/catch no teste do at, vai dar leak dentro da out_of_bound. ficar ligado nisso. o leak ñ eh na minha estrutura de dado.
    //          - obs2: ufa o comportamento tá igual com a std::vector.

    return 0;
}