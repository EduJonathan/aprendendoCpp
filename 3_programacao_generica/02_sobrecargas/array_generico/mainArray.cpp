#include "Tarray.tpp"
#include <stdexcept>
#include <iostream>
#include <iomanip>

template <class T, std::size_t size>
Array<T, size>::Array()
{
    for (std::size_t ind = 0; ind < size; ++ind)
    {
        array[ind] = T(); // Default initialize
    }
}

template <class T, std::size_t size>
T &Array<T, size>::operator[](int i)
{
    if (i < 0 || static_cast<std::size_t>(i) >= size)
        throw std::out_of_range("Index out of bounds");
    return array[i];
}

int main(int argc, char **argv)
{
    Array<int, 5> arr;

    for (int i = 0; i < 5; ++i)
    {
        arr[i] = i * 10;
    }

    for (int i = 0; i < 5; ++i)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';

    Array<double, 5> array;

    for (int i = 0; i < 5; ++i)
    {
        array[i] = i * 10.5;
    }

    for (int i = 0; i < 5; ++i)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << '\n';

    return 0;
}
