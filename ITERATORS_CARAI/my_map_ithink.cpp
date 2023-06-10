#include <cstddef> // NULL wtd
#include <iostream> // std::string, std::cout

template <typename T>
class List {
   public:
    /* ---------------- ALIASES ---------------- */
    typedef size_t size_type;

   private:
    template <typename ContentType>
    class Node {
    private:
        ContentType         _content;
        Node<ContentType>   *_next;

    public:
        Node() : _content(ContentType()), _next(NULL) {};
        Node(ContentType content) : _content(content), _next(NULL) {};
        Node(const Node &other) : _content(other._content), _next(other._next) {};
        ~Node() {};

        Node<ContentType> *getNext(void) { return (_next); };
        void setNext(Node *next) { _next = next; };

        friend std::ostream& operator<<(std::ostream& os, const Node& obj) {
            os << obj._content;
            return os;
        }
    };
    // template <typename IteratorType>
    // class MyIterator {
    //     Node<IteratorType>  _node;
    // };
    Node<T>     *_head;
    size_type   _size;

   public:
    List() : _head(NULL), _size(0) {};
    ~List() {
        Node<T> *temp;

        while (_head) {
            temp = _head->getNext();
            delete _head;
            _head = temp;
        }
    }

    void insert(T value) {
        if (_head == NULL) 
            _head = new Node<T>(value);
        else {
            Node<T> *pivot(_head);
            while (pivot->getNext())
                pivot = pivot->getNext();
            pivot->setNext(new Node<T>(value));
        }
        _size++;
        return ;
    }

    size_type size(void) {
        return (_size);
    }

    void printElements(void) {
        Node<T> *pivot = _head;
        for (size_type i = 0; i < _size; i++) {
            std::cout << *pivot << " ";
            pivot = pivot->getNext();
        }
        std::cout << std::endl;
    }
};

int main() {
    List<std::string> list;
    std::cout << "Tamanho da list: " << list.size() << "\n";
    list.insert("quarenta e dois");

    List<std::string>::size_type listSize = list.size();

    std::cout << "Tamanho da list: " << listSize << "\n";

    list.insert("quarenta e três");
    std::cout << "Tamanho da list: " << list.size() << "\n";

    list.insert("quarenta e quatro");
    std::cout << "Tamanho da list: " << list.size() << "\n";

    list.insert("quarenta e cinco");
    std::cout << "Tamanho da list: " << list.size() << "\n";

    list.insert("quarenta e seis");
    std::cout << "Tamanho da list: " << list.size() << "\n";

    list.insert("quarenta e sete");
    std::cout << "Tamanho da list: " << list.size() << "\n";

    list.printElements();
}