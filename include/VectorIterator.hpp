
namespace ft {

template <typename Vector>
class VectorIterator {
   public:

    template <typename V>
    friend bool operator==(const VectorIterator<V> &lhs, const VectorIterator<V> &rhs);
    template <typename V>
    friend bool operator!=(const VectorIterator<V> &lhs, const VectorIterator<V> &rhs);
    template <typename V>
    friend bool operator<(const VectorIterator<V> &lhs, const VectorIterator<V> &rhs);
    template <typename V>
    friend bool operator<=(const VectorIterator<V> &lhs, const VectorIterator<V> &rhs);
    template <typename V>
    friend bool operator>(const VectorIterator<V> &lhs, const VectorIterator<V> &rhs);
    template <typename V>
    friend bool operator>=(const VectorIterator<V> &lhs, const VectorIterator<V> &rhs);

    typedef typename Vector::value_type value_type;
    typedef typename Vector::value_type* pointer_type;

    VectorIterator(pointer_type data) : _data(data) {};

    VectorIterator& operator++() {
        _data = _data + 1;
        return (*this);
    };

    VectorIterator operator++(int) {
        VectorIterator temp(*this);
        _data = _data + 1;
        return (temp);
    };

    value_type operator*(void) {
        return (*_data);
    }

   private:
    pointer_type _data;

};
// ++it
// it++
// --it
// it--
// it[]
// *it



template <typename Vector>
bool operator==(const VectorIterator<Vector> &lhs, const VectorIterator<Vector> &rhs) {
    return (lhs._data == rhs._data);
};

template <typename Vector>
bool operator!=(const VectorIterator<Vector> &lhs, const VectorIterator<Vector> &rhs) {
    return (!(lhs == rhs));
};

template <typename Vector>
bool operator<(const VectorIterator<Vector> &lhs, const VectorIterator<Vector> &rhs) {
    return (lhs._data < rhs._data);
};

template <typename Vector>
bool operator<=(const VectorIterator<Vector> &lhs, const VectorIterator<Vector> &rhs) {
    return (lhs < rhs || lhs == rhs);
};

template <typename Vector>
bool operator>(const VectorIterator<Vector> &lhs, const VectorIterator<Vector> &rhs) {
    return (!(lhs < rhs) && !(lhs == rhs));
};

template <typename Vector>
bool operator>=(const VectorIterator<Vector> &lhs, const VectorIterator<Vector> &rhs) {
    return (!(lhs < rhs));
};


}
