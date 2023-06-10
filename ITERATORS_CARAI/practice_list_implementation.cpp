#include <cstddef> // NULL wtf
#include <iostream> // std::string, std::cout

class MyIterator;

template <typename T>
class List {
   public:
    /* --------------- ALIASES ----------------- */
    typedef size_t size_type;

   private:
    /* ----------- AUXILIAR CLASSES ------------ */
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

    class MyIterator {
       private:
        Node<T>  *_node;
       public:
        MyIterator(Node<T> *node) : _node(node) {};
        T &operator*(void) {
            return (_node->getContent());
        }
        MyIterator &operator++(void) {
            _node = _node->getNext();
            return (*this);
        }
        MyIterator operator++(int) {
            MyIterator temp(*this);
            ++(*this);
            return (temp);
        }
        // bool operator==(const MyIterator &rhs) {
        //     return (_node == rhs._node);
        // }
        // bool operator!=(const MyIterator &rhs) {
        //     return (!(*this == rhs));
        // }
    };

    /* --------------- ATTRIBUTES -------------- */
    Node<T>     *_head;
    size_type   _size;

   public:
    /* --------------- ALIASES ----------------- */
    typedef MyIterator iterator;
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

    iterator begin() {
        return (iterator(_head));
    };
    // iterator end() {
    //     if (_head == NULL)
    //         return (iterator(NULL));

    //     Node<T> *temp = _head->getNext();
    //     iterator last(temp);

    //     while (temp) {
    //         ++last;
    //     }

    //     return (last);
    // };
};

int main() {
    List<std::string> list;
    list.insert("quarenta e dois");
    list.insert("quarenta e três");
    list.insert("quarenta e quatro");
    list.insert("quarenta e cinco");
    list.insert("quarenta e seis");
    list.insert("quarenta e sete");

    List<std::string>::iterator it = list.begin();

    List<std::string>::size_type listSize = list.size();
    std::cout << "List has "<< listSize << " elements:" << std::endl;
    // while (it != list.end())
    for (List<std::string>::size_type i = 0; i < listSize; i++) {
        std::cout << "  [" << *it << "]," << std::endl;
        it++;
    }


    // List<std::string>::MyIterator
}