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
        ContentType &getContent(void) { return (_content); };
        void setContent(ContentType content) { _content = content; };

        friend std::ostream& operator<<(std::ostream& os, const Node& obj) {
            os << obj._content;
            return os;
        }
    };

    template <typename ContentType>
    class MyIterator {
       private:
        Node<ContentType>  *_node;
       public:
        MyIterator(Node<ContentType> *node) : _node(node) {};
        ContentType &operator*(void) {
            return (_node->getContent());
        }
    };

    /* ---------------- ATTRIBUTES ---------------- */
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
        List<T>::MyIterator<T> pivot(_head);
        std::cout << "List has "<< _size << " elements:" << std::endl;
        for (size_type i = 0; i < _size - 1; i++) {
            std::cout << "  [" << *pivot << "]," << std::endl;
            // pivot = pivot->getNext();
        }
        std::cout << "  [" << *pivot << "].";
        std::cout << std::endl;
    }
};

int main() {
    List<std::string> list;
    list.insert("quarenta e dois");
    list.insert("quarenta e três");
    list.insert("quarenta e quatro");
    list.insert("quarenta e cinco");
    list.insert("quarenta e seis");
    list.insert("quarenta e sete");
    list.printElements();
}