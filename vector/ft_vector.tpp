#ifndef FT_VECTOR_TPP
#define FT_VECTOR_TPP

namespace ft {

// __ MEMBER FUNCTIONS ________________________________________________________
template <typename T>
unsigned int Vector<T>::size(void) const { return _size; };

template <typename T>
unsigned int Vector<T>::capacity(void) const { return _capacity; };

template <typename T>
void Vector<T>::reserve(unsigned int newCapacity) {
    if (newCapacity <= _capacity) return ;
    _capacity = newCapacity;
    T *temp = new T[_capacity];
    for (unsigned int i = 0; i < _size; i++)
        temp[i] = _elements[i];
    delete[] _elements;
    _elements = temp;
};

template <typename T>
void Vector<T>::resize(unsigned int newSize) {
    _size = newSize;
};

template <typename T>
void Vector<T>::push_back(T newElem) {
    if (!_capacity)
        reserve(8);
    if (_size == _capacity)
        reserve(_capacity * 2);
    _elements[_size] = newElem;
    _size++;
};

// __ CONSTRUCTION/DESTRUCTION ________________________________________________
template <typename T>
Vector<T>::Vector(void) : _elements(NULL), _size(0), _capacity(0) {};

// TODO: e se size for < 0
template <typename T>
Vector<T>::Vector(int size) : _elements(new T[size]), _size(size), _capacity(size) {
    for (unsigned int i = 0; i < _size; i++)
        _elements[i] = 0;
};

template <typename T>
Vector<T>::Vector(const Vector&other) : _elements(new T[other._size]), _size(other._size) {
    for (unsigned int i = 0; i < _size; i++)
        _elements[i] = other._elements[i];
};

template <typename T>
Vector<T>::~Vector(void) {
    delete[] _elements;
};

// __ OPERATOR OVERLOADS ______________________________________________________
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& other) {
    if (this == &other) return (*this);

    if (other._size <= _capacity) {
        for (unsigned int i = 0; i < other._size; i++) {
            _elements[i] = other[i];
            _size = other._size;
        }
    } else {
        T *tempElems = new T[other._size];
        for (unsigned int i = 0; i < other._size; i++) {
            tempElems[i] = other._elements[i];
        }

        delete[] _elements;
        _elements = tempElems;
        _capacity = _size = other._size;
    }

    return (*this);
};

template <typename T>
T &Vector<T>::operator[](int index) { // for non-const Vectors
    return _elements[index];
};

template <typename T>
const T &Vector<T>::operator[](int index) const { // for const Vectors
    return _elements[index];
};

// __ EXTRA FUNCTIONS _________________________________________________________
//TODO: REMOVE BEFORE SUBMISSION
template <typename T>
void Vector<T>::test(void) {
    std::cout << "calling Map member function, test " << BOLD LIGHT_GREEN "OK" RESET << std::endl;
};

template <typename T>
void Vector<T>::printAll(void) {
    for (unsigned int i = 0; i < _size; i++)
        std::cout << _elements[i] << std::endl;
};

template <typename T>
void Vector<T>::fill(Vector<T> &vector, const T& value) {
    for (unsigned int i = 0; i < vector.size(); i++) {
        vector[i] = value;
    }
};

}  // namespace ft

#endif