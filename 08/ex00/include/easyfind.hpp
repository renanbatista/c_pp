#ifndef _EASYFIND_HPP_
#define _EASYFIND_HPP_

#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <vector>

#include "format.hpp"

class LaunchException : public std::exception {
    public:
        virtual const char *what() const throw() { return ("Look elsewhere!"); }
};

template <typename T>
typename T::iterator easyfind(T &container, int value);

#endif

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator ret = find(container.begin(), container.end(), value);
    if (ret == container.end())
        throw LaunchException();
    else
        return ret;
}