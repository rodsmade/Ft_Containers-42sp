#include <iterator>

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
    typedef typename Vector::difference_type difference_type;
    typedef typename Vector::value_type* pointer;
    typedef typename Vector::value_type& reference;
    typedef typename std::random_access_iterator_tag iterator_category;

    VectorIterator(pointer data) : _data(data) {};

    VectorIterator& operator++() {
        _data = _data + 1;
        return (*this);
    };

    VectorIterator operator++(int) {
        VectorIterator temp(*this);
        _data = _data + 1;
        return (temp);
    };

    VectorIterator& operator--() {
        _data = _data - 1;
        return (*this);
    };

    VectorIterator operator--(int) {
        VectorIterator temp(*this);
        _data = _data - 1;
        return (temp);
    };

    reference operator*(void) {
        return (*_data);
    }

    reference operator*(void) const {
        return (*_data);
    }

// TODO:
//  - operator->

   private:
    pointer _data;

};

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
