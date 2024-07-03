#ifndef ITER_HPP
#define ITER_HPP

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "format.hpp"

template <typename T>
void iter(T* arr, size_t size, void (*func)(T&))
{
    for (size_t i = 0; i < size; ++i)
        func(arr[i]);
}

template <typename T>
void iter(T const* arr, size_t size, void (*func)(T const&))
{
    for (size_t i = 0; i < size; ++i)
        func(arr[i]);
}

template <typename T>
void colors(T const& a)
{
    std::string color[] = {RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN};

    std::cout << color[rand() % 6] << a << RESET << std::endl;
}

template <typename T>
void printMsg(T const& var)
{
    std::cout << var << std::endl;
}

#endif