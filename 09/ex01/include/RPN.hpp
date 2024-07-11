#ifndef RPN_HPP
#define RPN_HPP

#include <algorithm>
#include <iostream>
#include <stack>

#include "format.hpp"

class RPN {
    private:
        std::stack<double> _numbers;
        void               calculate(char oper);

    public:
        RPN(void);
        ~RPN(void);
        RPN(RPN const& copy);
        RPN&   operator=(RPN const& other);
        double run(std::string arg);
        class ErrorTooFewOperators : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class ErrorInvalidCharacter : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class ErrorDivisionByZero : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class ErrorInvalidExpression : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class ErrorOutRange : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

#endif