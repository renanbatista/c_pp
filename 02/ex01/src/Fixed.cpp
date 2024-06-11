#include "Fixed.hpp"

#include <math.h>

Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const& src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::Fixed(const int iNumber) {
    std::cout << "Int constructor called" << std::endl;
    _value = iNumber << _bits;
}

Fixed::Fixed(const float fNumber) {
    std::cout << "Float constructor called" << std::endl;
    _value = roundf(fNumber * (1 << _bits));
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(Fixed const& obj) {
    std::cout << "Copy assignement operator called" << std::endl;
    if (this != &obj)
        _value = obj._value;
    return *this;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return _value;
}

void Fixed::setRawBits(int const raw) {
    _value = raw;
}

float Fixed::toFloat() const {
    return (float)_value / (float)(1 << _bits);
}

int Fixed::toInt() const {
    return _value >> _bits;
}

std::ostream& operator<<(std::ostream& o, Fixed const& obj) {
    o << obj.toFloat();
    return o;
}