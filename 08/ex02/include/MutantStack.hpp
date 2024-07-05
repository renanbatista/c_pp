#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

#include "format.hpp"

template <typename T>
class MutantStack : public std::stack<T> {
    public:
        MutantStack(void);
        MutantStack(MutantStack const &copy);
        virtual ~MutantStack(void);

        MutantStack &operator=(MutantStack const &other);

        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator                                                 begin(void);
        iterator                                                 end(void);
};

template <typename T>
MutantStack<T>::MutantStack(void) : std::stack<T>()
{
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const &copy) : std::stack<T>(copy)
{
}

template <typename T>
MutantStack<T>::~MutantStack(void)
{
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack const &other)
{
    if (this != &other) {
        std::stack<T>::operator=(other);
    }
    return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void)
{
    return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void)
{
    return std::stack<T>::c.end();
}

#endif