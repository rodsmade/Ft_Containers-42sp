#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP

namespace ft {

class Vector {
   public:
    unsigned int size(void) const;
    static void test(void);

    double get(int index);
    void set(int index, double value);

    Vector(int size);
    ~Vector();

   private:
    double *_elements;
    unsigned int _size;
};

}  // namespace ft

#endif
