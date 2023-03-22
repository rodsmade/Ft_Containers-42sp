#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP

class FtVector {
   public:
    unsigned int size(void) const;

    double get(int index);
    void set(int index, double value);  

    FtVector(int size);
    ~FtVector();

   private:
    double *_elements;
    unsigned int _size;
};

#endif