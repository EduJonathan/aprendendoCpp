#ifndef TARRAY_TPP
#define TARRAY_TPP

#include <cstddef>

template <class T, std::size_t size>
class Array
{
    T array[size];

public:
    Array();
    T &operator[](int i);
};

#endif
