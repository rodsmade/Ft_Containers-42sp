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
        ContentType _content;
        Node        *_next;

        friend class List<T>;

    public:
        Node() : _content(ContentType()), _next(NULL) {};
        Node(ContentType content) : _content(content), _next(NULL) {};
        Node(const Node &other) : _content(other._content), _next(other._next) {};
        ~Node() {};

        friend std::ostream& operator<<(std::ostream& os, const Node& obj) {
            os << obj._content;
            return os;
        }
    };

    Node<T>     *_head;
    size_type   _size;

   public:
    List() : _head(NULL), _size(0) {};
    ~List() {
        Node<T> *temp;

        while (_head) {
            temp = _head->_next;
            delete _head;
            _head = temp;
        }
    }

    void insert(T value) {
        if (_head == NULL) {
            _head = new Node<T>(value);
            _size++;
            return ;
        }

        Node<T> *pivot(_head);
        while (pivot->_next)
            pivot = pivot->_next;
        
        pivot->_next = new Node<T>(value);
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
            pivot = pivot->_next;
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

    list.printElements();
}