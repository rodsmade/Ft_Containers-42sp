#ifndef FT_VECTOR_TPP
#define FT_VECTOR_TPP

namespace ft {

/*=============================================================================
===  MEMBER FUNCTIONS                                                       ===
=============================================================================*/
template <typename T>
typename vector<T>::size_type vector<T>::size(void) const { return _size; };

template <typename T>
typename vector<T>::size_type vector<T>::capacity(void) const { return _capacity; };

template <typename T>
void vector<T>::reserve(size_type newCapacity) {
    if (newCapacity <= _capacity) return;

    _capacity = newCapacity;
    T *temp = new T[_capacity];
    for (size_type i = 0; i < _size; i++)
        temp[i] = _elements[i];
    delete[] _elements;
    _elements = temp;
};

template <typename T>
void vector<T>::resize(size_type newSize) {
    if (newSize > _size)
        reserve(newSize);
    _size = newSize;
};

template <typename T>
void vector<T>::push_back(T newElem) {
    if (!_capacity)
        reserve(1);
    if (_size == _capacity)
        reserve(_capacity * 2);
    _elements[_size] = newElem;
    _size++;
};

template <typename T>
T &vector<T>::at(size_type index) {
    if (index < 0 || index >= _size) throw std::out_of_range(getOutOfRangeErrorMessage(index));
    return _elements[index];
};

template <typename T>
const T &vector<T>::at(size_type index) const {
    if (index < 0 || index >= _size) throw std::out_of_range(getOutOfRangeErrorMessage(index));
    return _elements[index];
};

/*=============================================================================
===  CONSTRUCTION / DESTRUCTION                                             ===
=============================================================================*/
template <typename T>
vector<T>::vector(void) : _elements(NULL), _size(0), _capacity(0){};

// TODO: e se size for < 0
template <typename T>
vector<T>::vector(size_type size) : _elements(new T[size]), _size(size), _capacity(size) {
    for (size_type i = 0; i < _size; i++)
        _elements[i] = 0;
};

template <typename T>
vector<T>::vector(const vector &other) : _elements(new T[other._size]), _size(other._size) {
    for (size_type i = 0; i < _size; i++)
        _elements[i] = other._elements[i];
};

template <typename T>
vector<T>::~vector(void) {
    delete[] _elements;
};

/*=============================================================================
===  OPERATOR OVERLOADS                                                     ===
=============================================================================*/
template <typename T>
vector<T> &vector<T>::operator=(const vector &other) {
    if (this == &other) return (*this);

    if (other._size <= _capacity) {
        for (size_type i = 0; i < other._size; i++) {
            _elements[i] = other[i];
            _size = other._size;
        }
    } else {
        T *tempElems = new T[other._size];
        for (size_type i = 0; i < other._size; i++) {
            tempElems[i] = other._elements[i];
        }

        delete[] _elements;
        _elements = tempElems;
        _capacity = _size = other._size;
    }

    return (*this);
};

template <typename T>
T &vector<T>::operator[](size_type index) {  // for non-const vectors
    return _elements[index];
};

template <typename T>
const T &vector<T>::operator[](size_type index) const {  // for const vectors
    return _elements[index];
};

/*=============================================================================
===  PRIVATE FUNCTIONS                                                      ===
=============================================================================*/
template <typename T>
std::string vector<T>::getOutOfRangeErrorMessage(size_type index) const {
    return ("vector::_M_range_check: __n (which is " + std::to_string((unsigned long int)index) + ") >= this->size() (which is " + std::to_string(_size) + ")");
};

/*=============================================================================
===  EXTRA FUNCTIONS                                                        ===
===  TODO: REMOVE BEFORE SUBMISSION                                         ===
=============================================================================*/
template <typename T>
void vector<T>::test(void) {
    std::cout << "calling Map member function, test " << BOLD LIGHT_GREEN "OK" RESET << std::endl;
};

template <typename T>
void vector<T>::printAll(void) {
    for (size_type i = 0; i < _size; i++)
        std::cout << _elements[i] << std::endl;
};

template <typename T>
void vector<T>::fill(vector<T> &vector, const T &value) {
    for (size_type i = 0; i < vector.size(); i++) {
        vector[i] = value;
    }
};

}  // namespace ft

#endif