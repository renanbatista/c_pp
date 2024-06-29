#ifndef _ARRAY_HPP_
#define _ARRAY_HPP_

#include <iostream>
#include <sstream>

#include "format.hpp"
template <typename T>
class Array {
    private:
        unsigned int _size;
        T*           _arrayList;

    public:
        class ErrorLimitsOfIndex : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        Array(void);
        Array(unsigned int size);
        Array(Array const& copy);
        ~Array(void);

        Array&   operator=(Array const& other);
        T&       operator[](unsigned int const index);
        const T& operator[](unsigned int const index) const;

        unsigned int size() const;
};

template <typename T>
Array<T>::Array(void) : _size(0), _arrayList(new T[0])
{
}

template <typename T>
Array<T>::Array(unsigned int size) : _size(size), _arrayList(new T[size])
{
    for (unsigned int i = 0; i < _size; ++i)
        _arrayList[i] = T();
}

template <typename T>
Array<T>::~Array(void)
{
    delete[] this->_arrayList;
}

template <typename T>
Array<T>::Array(Array const& copy) : _size(copy._size), _arrayList(new T[copy._size])
{
    for (unsigned int i = 0; i < this->_size; ++i)
        this->_arrayList[i] = copy._arrayList[i];
}

template <typename T>
Array<T>& Array<T>::operator=(Array const& other)
{
    if (this != &other) {
        if (this)
            delete[] this->_arrayList;
        this->_size = other._size;
        this->_arrayList = new T[other._size];
        for (unsigned int i = 0; i < this->_size; ++i)
            this->_arrayList[i] = other._arrayList[i];
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int const index)
{
    if (index >= this->_size)
        throw ErrorLimitsOfIndex();
    return this->_arrayList[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int const index) const
{
    if (index >= this->_size)
        throw ErrorLimitsOfIndex();
    return this->_arrayList[index];
}

template <typename T>
unsigned int Array<T>::size(void) const
{
    return this->_size;
}

template <typename T>
const char* Array<T>::ErrorLimitsOfIndex::what() const throw()
{
    return "Error: Index out of limits.";
}

#endif