#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP

class FtVector {
   public:
    FtVector(int size);
    unsigned int getSize(void) const;

   private:
    double *_elements;
    unsigned int _size;
};

#endif