/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD12-arthur.decaen
** File description:
** Array
*/

#include <iostream>
#include <stdexcept>
#include <functional>

#ifndef ARRAY_HPP_
#define ARRAY_HPP_

template <typename T, size_t Size>
class Array
{
public:
    T *_array;
    Array() { _array = new T[Size]; }
    ~Array(){};

    std::size_t size() const { return Size; }
    void forEach(const std::function<void(const T &)> &task) const
    {
        for (size_t j = 0; j < Size; j++)
            task(_array[j]);
    }

    template <typename U>
    Array<U, Size> convert(const std::function<U(const T &)> &converter) const
    {
        Array<U, Size> result;

        for (size_t j = 0; j < Size; j++)
            result[j] = converter(_array[j]);
        return result;
    }

    T &operator[](size_t pos) const
    {
        if (pos >= Size)
            throw std::out_of_range("Out of range");
        return _array[pos];
    }
};

template <typename T, size_t Size>
std::ostream &operator<<(std::ostream &stream, Array<T, Size> const &array)
{
    size_t j = 0;

    if (Size == 0)
    {
        stream << "[]" << std::endl;
        return stream;
    }

    stream << "[";
    for (; j < Size - 1; j++)
        stream << array._array[j] << ", ";
    stream << array._array[j];
    stream << "]";
    return stream;
}

#endif /* !ARRAY_HPP_ */
