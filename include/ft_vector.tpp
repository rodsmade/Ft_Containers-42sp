#ifndef FT_VECTOR_TPP
#define FT_VECTOR_TPP

namespace ft {

/*=============================================================================
===  MEMBER FUNCTIONS                                                       ===
=============================================================================*/
template <typename T, typename A>
T &vector<T, A>::at(size_type index) {
    if (index < 0 || index >= _size) throw std::out_of_range(getOutOfRangeErrorMessage(index));
    return _elements[index];
};

template <typename T, typename A>
const T &vector<T, A>::at(size_type index) const {
    if (index < 0 || index >= _size) throw std::out_of_range(getOutOfRangeErrorMessage(index));
    return _elements[index];
};

template <typename T, typename A>
void vector<T, A>::clear() {
    for (size_type i = 0; i < _capacity; i++) // Destroy (return back to unitialized state?) old memory
        _allocator.destroy(&_elements[i]);
    _size = 0;
};

template <typename T, typename A>
typename vector<T, A>::size_type vector<T, A>::capacity(void) const { return _capacity; };

template <typename T, typename A>
bool vector<T, A>::empty() const {
    if (_size == 0) return true;
    else return false;
};

template <typename T, typename A>
typename vector<T, A>::size_type vector<T, A>::max_size() const {
    return (LONG_MAX);
};

template <typename T, typename A>
void vector<T, A>::push_back(const T& newElem) {
    if (!_capacity)
        reserve(1);
    if (_size == _capacity)
        reserve(_capacity * 2);
    _allocator.construct(&_elements[_size], newElem);
    _size++;
};

template <typename T, typename A>
void vector<T, A>::reserve(size_type newCapacity) {
    if (newCapacity <= _capacity) return;

    // T *temp = new T[_capacity];
    T *temp = _allocator.allocate(newCapacity); // Allocate more (uninitialized) memory
    for (size_type i = 0; i < _size; i++) // Construct (initialize) allocated memory
        // temp[i] = _elements[i];
        _allocator.construct(&temp[i], _elements[i]);
    // delete[] _elements;
    for (size_type i = 0; i < _size; i++) // Destroy (return back to unitialized state?) old memory
        _allocator.destroy(&_elements[i]);
    _allocator.deallocate(_elements, _capacity);

    _capacity = newCapacity;
    _elements = temp;
};

template <typename T, typename A>
void vector<T, A>::resize(size_type newSize) {
    if (newSize > _size)
        reserve(newSize);
    _size = newSize;
};

template <typename T, typename A>
typename vector<T, A>::size_type vector<T, A>::size(void) const { return _size; };

/*=============================================================================
===  CONSTRUCTION / DESTRUCTION                                             ===
=============================================================================*/
template <typename T, typename A>
vector<T, A>::vector(void) : _elements(NULL), _size(0), _capacity(0){};

template <typename T, typename A>
vector<T, A>::vector(size_type size) {
    if (size > this->max_size())
        throw std::length_error("cannot create std::vector larger than max_size()");

    _elements = new T[size];
    _size = size;
    _capacity = size;
};

template <typename T, typename A>
vector<T, A>::vector(const vector &other) : _elements(new T[other._size]), _size(other._size) {
    for (size_type i = 0; i < _size; i++)
        _elements[i] = other._elements[i];
};

template <typename T, typename A>
vector<T, A>::~vector(void) {
    for (size_type i = 0; i < _size; i++) // Destroy (return back to unitialized state?) old memory
        _allocator.destroy(&_elements[i]);
    _allocator.deallocate(_elements, _capacity);
};

/*=============================================================================
===  OPERATOR OVERLOADS                                                     ===
=============================================================================*/
template <typename T, typename A>
vector<T, A> &vector<T, A>::operator=(const vector &other) {
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

template <typename T, typename A>
T &vector<T, A>::operator[](size_type index) {  // for non-const vectors
    return _elements[index];
};

template <typename T, typename A>
const T &vector<T, A>::operator[](size_type index) const {  // for const vectors
    return _elements[index];
};

/*=============================================================================
===  PRIVATE FUNCTIONS                                                      ===
=============================================================================*/
template <typename T, typename A>
std::string vector<T, A>::getOutOfRangeErrorMessage(size_type index) const {
    std::ostringstream oss;

    oss << "vector::_M_range_check: __n (which is " << index << ") >= this->size() (which is " << _size << ")";

    return oss.str();
};

/*=============================================================================
===  EXTRA FUNCTIONS                                                        ===
===  TODO: REMOVE BEFORE SUBMISSION                                         ===
=============================================================================*/
template <typename T, typename A>
void vector<T, A>::test(void) {
    std::cout << "calling Map member function, test " << BOLD LIGHT_GREEN "OK" RESET << std::endl;
};

template <typename T, typename A>
void vector<T, A>::printAll(void) {
    for (size_type i = 0; i < _size; i++)
        std::cout << _elements[i] << std::endl;
};

template <typename T, typename A>
void vector<T, A>::fill(vector<T, A> &vector, const T &value) {
    for (size_type i = 0; i < vector.size(); i++) {
        vector[i] = value;
    }
};

}  // namespace ft

#endif