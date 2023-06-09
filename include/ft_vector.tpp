#ifndef FT_VECTOR_TPP
#define FT_VECTOR_TPP

namespace ft {

/*==============================================================================
===  MEMBER FUNCTIONS                                                        ===
==============================================================================*/
template <typename T, typename A>
template <class InputIt>
void vector<T, A>::assign(InputIt first, InputIt last) {
    this->clear();
    for (InputIt it = first; it != last; it++) {
        this->push_back(*it);
    }
};

template <typename T, typename A>
void vector<T, A>::assign(size_type count, const_reference value) {
    if (count <= _capacity) {
        for (size_type i = 0; i < _size; i++)
            _allocator.destroy(&_elements[i]);
        for (size_type i = 0; i < count; i++)
            _allocator.construct(&_elements[i], value);
        _size = count;
    } else {
        for (size_type i = 0; i < _size; i++)
            _allocator.destroy(&_elements[i]);
        _allocator.deallocate(_elements, _capacity);
        _elements = _allocator.allocate(count);
        for (size_type i = 0; i < count; i++)
            _allocator.construct(&_elements[i], value);
        _size = _capacity = count;
    }
    return ;
};

template <typename T, typename A>
typename vector<T, A>::reference vector<T, A>::at(size_type index) {
    if (index >= _size) throw std::out_of_range(getOutOfRangeErrorMessage(index));
    return _elements[index];
};

template <typename T, typename A>
typename vector<T, A>::const_reference vector<T, A>::at(size_type index) const {
    if (index >= _size) throw std::out_of_range(getOutOfRangeErrorMessage(index));
    return _elements[index];
};

template <typename T, typename A>
typename vector<T, A>::reference vector<T, A>::back() {
    return _elements[_size - 1];
};

template <typename T, typename A>
typename vector<T, A>::const_reference vector<T, A>::back() const {
    return _elements[_size - 1];
};

template <typename T, typename A>
typename vector<T, A>::iterator vector<T, A>::begin() {
    return (iterator(_elements));
};

template <typename T, typename A>
typename vector<T, A>::const_iterator vector<T, A>::begin() const {
    return (_elements);
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
typename vector<T, A>::value_type* vector<T, A>::data() {
    return (&_elements[0]);
};

template <typename T, typename A>
const typename vector<T, A>::value_type* vector<T, A>::data() const {
    return (&_elements[0]);
};

template <typename T, typename A>
bool vector<T, A>::empty() const {
    if (_size == 0) return true;
    else return false;
};

template <typename T, typename A>
typename vector<T, A>::iterator vector<T, A>::end() {
    return (_elements + _size);
};

template <typename T, typename A>
typename vector<T, A>::const_iterator vector<T, A>::end() const {
    return (_elements + _size);
};

template <typename T, typename A>
typename vector<T, A>::iterator vector<T, A>::erase(iterator pos) {
    iterator returningIt(pos);
    iterator pivot(pos);
    iterator next(++pos);

    while (pivot != this->end()) {
        _allocator.destroy(&*pivot);
        if (next != this->end()) {
            _allocator.construct(&*pivot, *next);
            next++;
        }
        pivot++;
    }

    _size--;

    return (returningIt);
};

template <typename T, typename A>
typename vector<T, A>::iterator vector<T, A>::erase(iterator first, iterator last) {
    iterator returningIt(first);

    iterator pivot(first);
    iterator pivotPastRange(last);
    size_type oldSize = _size;

    while (pivot != last) {
        _allocator.destroy(&*pivot);
        oldSize--;
        _allocator.construct(&*pivot, *pivotPastRange);
        pivot++;
        pivotPastRange++;
    }
    while (pivot != this->end()) {
        _allocator.destroy(&*pivot);
        pivot++;
    }

    _size = oldSize;
    return (returningIt);
};

template <typename T, typename A>
typename vector<T, A>::reference vector<T, A>::front() {
    return _elements[0];
};

template <typename T, typename A>
typename vector<T, A>::const_reference vector<T, A>::front() const {
    return _elements[0];
};

template <typename T, typename A>
typename vector<T, A>::allocator_type vector<T, A>::get_allocator() const {
    return (_allocator);
};

template <typename T, typename A>
typename vector<T, A>::iterator vector<T, A>::insert(const_iterator pos, const_reference value) {

    iterator relationalPos(pos);

    if (_size == _capacity) {
        size_t offset = 0;
        iterator oldBegin = this->begin();
        while (oldBegin++ != pos)
            offset++;

        this->reserve(_capacity * 2);

        relationalPos = this->begin();
        while (offset--)
            relationalPos++;
    }

    iterator pivot(this->end());
    iterator previous(this->end());
    previous--;
    for (; pivot != relationalPos;) {
        _allocator.destroy(&*pivot);
        _allocator.construct(&*pivot, *previous);
        pivot--;
        previous--;
    }
    _allocator.destroy(&*pivot);
    _allocator.construct(&*pivot, value);

    _size++;

    return (relationalPos);
};

template <typename T, typename A>
typename vector<T, A>::iterator vector<T, A>::insert(const_iterator pos, size_type count, const_reference value) {
    if (count == 0)
        return pos;

    iterator relationalPos(pos);

    if (_size + count > _capacity) {
        size_t offset = 0;
        iterator oldBegin = this->begin();
        while (oldBegin++ != pos)
            offset++;

        this->reserve(_size + count);

        relationalPos = this->begin();
        while (offset--)
            relationalPos++;
    }

    iterator pivot(this->end());
    pivot--;
    iterator copyHead(this->end());
    copyHead--;
    for (size_type i = 0; i < count; i++)
        copyHead++;

    iterator halt(relationalPos);
    halt--;

    while (pivot != halt) {
        if (copyHead < this->end())
            _allocator.destroy(&*copyHead);
        _allocator.construct(&*copyHead, *pivot);
        pivot--;
        copyHead--;
    }

    for (size_type i = 0; i < count; i++) {
        _allocator.destroy(&*(++pivot));
        _allocator.construct(&*pivot, value);
    }

    _size += count;

    return (relationalPos);
};

template <typename T, typename A>
template< class InputIt >
typename vector<T, A>::iterator vector<T, A>::insert(const_iterator pos, InputIt first, InputIt last) {
    if (first == last)
        return pos;

    iterator relationalPos(pos);

    size_type count = 0;
    {
        iterator temp(first);
        while (temp++ != last)
            count++;
    }

    if (_size + count > _capacity) {
        size_t offset = 0;
        iterator oldBegin = this->begin();
        while (oldBegin++ != pos)
            offset++;

        this->reserve(_size + count);

        relationalPos = this->begin();
        while (offset--)
            relationalPos++;
    }

    iterator pivot(this->end());
    pivot--;
    iterator copyHead(this->end());
    copyHead--;
    for (size_type i = 0; i < count; i++)
        copyHead++;

    iterator halt(relationalPos);
    halt--;

    while (pivot != halt) {
        if (copyHead < this->end())
            _allocator.destroy(&*copyHead);
        _allocator.construct(&*copyHead, *pivot);
        pivot--;
        copyHead--;
    }

    for (size_type i = 0; i < count; i++) {
        _allocator.destroy(&*(++pivot));
        _allocator.construct(&*pivot, *(first++));
    }

    _size += count;

    return (pos);
};

template <typename T, typename A>
typename vector<T, A>::size_type vector<T, A>::max_size() const {
    return (_allocator.max_size());
};

template <typename T, typename A>
void vector<T, A>::pop_back() {
    _size--;
    return;
};

template <typename T, typename A>
void vector<T, A>::push_back(const_reference newElem) {
    if (!_capacity)
        reserve(1);
    if (_size == _capacity)
        reserve(_capacity * 2);
    _allocator.construct(&_elements[_size], newElem);
    _size++;
};

template <typename T, typename A>
typename vector<T, A>::reverse_iterator vector<T, A>::rbegin() {
    reverse_iterator it(_elements + _size);
    return (it);
};

template <typename T, typename A>
typename vector<T, A>::const_reverse_iterator vector<T, A>::rbegin() const {
    const_reverse_iterator it(_elements + _size);
    return (it);
};

template <typename T, typename A>
typename vector<T, A>::reverse_iterator vector<T, A>::rend() {
    reverse_iterator it(_elements);
    return (it);
};

template <typename T, typename A>
typename vector<T, A>::const_reverse_iterator vector<T, A>::rend() const {
    const_reverse_iterator it(_elements);
    return (it);
};

template <typename T, typename A>
void vector<T, A>::reserve(size_type newCapacity) {
    if (newCapacity <= _capacity) return;

    T *temp;

    temp = _allocator.allocate(newCapacity); // Allocate more (uninitialized) memory
    for (size_type i = 0; i < _size; i++) {
        _allocator.construct(&temp[i], _elements[i]); // Construct (initialize) allocated memory
        _allocator.destroy(&_elements[i]); // Destroy (return back to unitialized state?) old memory
    }
    if (_capacity)
        _allocator.deallocate(_elements, _capacity);

    _capacity = newCapacity;
    _elements = temp;
};

template <typename T, typename A>
void vector<T, A>::resize(size_type newSize, value_type value) {
    size_type oldSize = _size;

    if (newSize > oldSize) {
        reserve(newSize);
        for (size_type i = oldSize; i < newSize; i++)
            _elements[i] = value;
    }
    else {
        for (size_type i = newSize; i < oldSize; i++)
            _allocator.destroy(&_elements[i]);
    }
    _size = newSize;
};

template <typename T, typename A>
typename vector<T, A>::size_type vector<T, A>::size(void) const { return _size; };

template <typename T, typename A>
void vector<T, A>::swap(vector& other){
    if (this == &other) { return; };

    value_type* temp = _elements;
    size_type temp_size = _size;
    size_type temp_capacity = _capacity;

    _elements = other._elements;
    _size = other._size;
    _capacity = other._capacity;

    other._elements = temp;
    other._size = temp_size;
    other._capacity = temp_capacity;

    return ;
};

/*==============================================================================
===  CONSTRUCTION / DESTRUCTION                                              ===
==============================================================================*/
// Default
template <typename T, typename A>
vector<T, A>::vector(const allocator_type& alloc) : _allocator(alloc), _elements(NULL), _size(0), _capacity(0) {};

// Fill
template <typename T, typename A>
vector<T, A>::vector(size_type size, const_reference value, const allocator_type& allocator) {
    if (size > this->max_size())
        throw std::length_error("cannot create std::vector larger than max_size()");

    _size = size;
    _capacity = size;
    _allocator = allocator;

    T *temp = _allocator.allocate(_size);
    for (size_type i = 0; i < _size; i++) {
        _allocator.construct(&temp[i], value);
    }
    _elements = temp;
};

// Range
template <typename T, typename A>
template <class InputIt>
vector<T, A>::vector(InputIt first, InputIt last, const allocator_type& allocator) : _allocator(allocator), _elements(NULL), _size(0), _capacity(0) {

    if (first == last)
        return;

    iterator copyOfFirst(first);
    size_type ogSize = 0;
    for (; copyOfFirst != last; copyOfFirst++)
        ogSize++;

    this->reserve(ogSize);
    _size = _capacity;

    for (size_type i = 0; first != last; i++) {
        this->at(i) = *first;
        first++;
    }
    return;
};

// Copy
template <typename T, typename A>
vector<T, A>::vector(const vector &other) {
    _size = other._size;
    _capacity = other._size;

    T *temp = _allocator.allocate(_size);
    for (size_type i = 0; i < _size; i++) {
        _allocator.construct(&temp[i], other._elements[i]);
    }
    _elements = temp;

};

template <typename T, typename A>
vector<T, A>::~vector(void) {
    for (size_type i = 0; i < _size; i++) // Destroy (return back to unitialized state?) old memory
        _allocator.destroy(&_elements[i]);
    _allocator.deallocate(_elements, _capacity);
};

/*==============================================================================
===  OPERATOR OVERLOADS                                                      ===
==============================================================================*/
template <typename T, typename A>
vector<T, A> &vector<T, A>::operator=(const vector &other) {
    if (this == &other) return (*this);

    if (other._size <= _capacity) {
        for (size_type i = 0; i < other._size; i++) {
            _elements[i] = other[i];
            _size = other._size;
        }
    } else {
        T *tempElems = _allocator.allocate(other._size);
        for (size_type i = 0; i < other._size; i++) {
            _allocator.construct(&tempElems[i], other._elements[i]);
        }

        for (size_type i = 0; i < _size; i++)
            _allocator.destroy(&_elements[i]);
        _allocator.deallocate(_elements, _capacity);

        _elements = tempElems;
    }
    _capacity = _size = other._size;

    return (*this);
};

template <typename T, typename A>
typename vector<T, A>::reference vector<T, A>::operator[](size_type index) {
    return _elements[index];
};

template <typename T, typename A>
typename vector<T, A>::const_reference vector<T, A>::operator[](size_type index) const {
    return _elements[index];
};

/*==============================================================================
===  PRIVATE FUNCTIONS                                                       ===
==============================================================================*/
template <typename T, typename A>
std::string vector<T, A>::getOutOfRangeErrorMessage(size_type index) const {
    std::ostringstream oss;

    oss << "vector::_M_range_check: __n (which is " << index << ") >= this->size() (which is " << _size << ")";

    return oss.str();
};

/*=============================================================================
===  NON-MEMBER FUNCTIONS                                                   ===
=============================================================================*/
/*****************************************************************************/
/*   OPERATOR OVERLOADS                                                      */
/*****************************************************************************/
template< class T, class Alloc >
bool operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
    // lexicographical comparison means comparing elements one by one.
    for (typename vector<T, Alloc>::size_type i = 0; i < lhs.size(); i++) {
        if (i == rhs.size())
            break ;
        if (lhs.at(i) != rhs.at(i))
            return (false);
    }

    // if all comparable elements are the same, resolve comparison by size.
    return (lhs.size() == rhs.size()); // capacity is irrelevant to this comparison.
};

template< class T, class Alloc >
bool operator!=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs){
    return (!(lhs == rhs));
};

template< class T, class Alloc >
bool operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
    for (typename vector<T, Alloc>::size_type i = 0; i < lhs.size(); i++) {
        if (i == rhs.size())
            break ;
        if (lhs.at(i) < rhs.at(i))
            return (true);
        else if (lhs.at(i) > rhs.at(i))
            return (false);
    }

    return (lhs.size() < rhs.size());
};

template< class T, class Alloc >
bool operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
    return (!(rhs < lhs));
};

template< class T, class Alloc >
bool operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
    return (rhs < lhs);
};

template< class T, class Alloc >
bool operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
    return (!(lhs < rhs));
};

/*********************************************/
/*                  OTHER                    */
/*********************************************/
template < class T, class Alloc >
void swap(vector<T, Alloc>& lhs, vector<T, Alloc>& rhs) {
    lhs.swap(rhs);
};

}  // namespace ft

#endif