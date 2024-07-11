#include "RPN.hpp"

RPN::RPN(void) {}

RPN::RPN(RPN const &copy)
{
    *this = copy;
}

RPN::~RPN(void) {}

RPN &RPN::operator=(RPN const &other)
{
    if (this != &other)
        this->_numbers = other._numbers;
    return *this;
}

double RPN::run(std::string arg)
{
    std::string regular = "0123456789 /*-+";
    std::string op = "/*-+";

    if (arg.find_first_not_of(regular) != std::string::npos)
        throw ErrorInvalidCharacter();
    for (size_t i = 0; i < arg.length(); ++i) {
        if (isdigit(arg[i])) {
            if (arg[i + 1] && isdigit(arg[i + 1]))
                throw ErrorOutRange();
            this->_numbers.push(arg[i] - '0');
        }
        else if (op.find(arg[i]) != std::string::npos)
            calculate(arg[i]);
    }
    if (_numbers.size() != 1)
        throw ErrorInvalidExpression();
    return this->_numbers.top();
}

void RPN::calculate(char oper)
{
    if (this->_numbers.size() < 2)
        throw ErrorTooFewOperators();

    double num1 = this->_numbers.top();
    this->_numbers.pop();

    double num2 = this->_numbers.top();
    this->_numbers.pop();

    switch (oper) {
        case '+':
            this->_numbers.push(num2 + num1);
            break;
        case '-':
            this->_numbers.push(num2 - num1);
            break;
        case '*':
            this->_numbers.push(num2 * num1);
            break;
        default:
            if (num1 == 0)
                throw ErrorDivisionByZero();
            this->_numbers.push(num2 / num1);
            break;
    }
}

const char *RPN::ErrorTooFewOperators::what() const throw()
{
    return "Too few operators.";
}

const char *RPN::ErrorInvalidCharacter::what() const throw()
{
    return "Invalid character.";
}

const char *RPN::ErrorDivisionByZero::what() const throw()
{
    return "Division by zero.";
}

const char *RPN::ErrorInvalidExpression::what() const throw()
{
    return "Invalid expression.";
}

const char *RPN::ErrorOutRange::what() const throw()
{
    return "Number is out of range.";
}