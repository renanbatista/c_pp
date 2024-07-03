#ifndef _SPAN_HPP_
#define _SPAN_HPP_

#include <algorithm>
#include <iostream>
#include <vector>

#include "format.hpp"

class Span {
    private:
        size_t           _N;
        std::vector<int> _vec;
        Span(void);

    public:
        class SpanIsFullError : public std::exception {
                virtual const char* what() const throw();
        };
        class SpanIsOneOrNoneError : public std::exception {
                virtual const char* what() const throw();
        };

        Span(size_t N);
        Span(Span const& copy);
        ~Span(void);

        Span& operator=(Span const& other);

        void addNumber(int num);
        void addMulti(std::vector<int>::iterator begin, std::vector<int>::iterator end);

        int shortestSpan(void);
        int longestSpan(void);
};

#endif