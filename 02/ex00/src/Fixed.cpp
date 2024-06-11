#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &rSym) {
    std::cout << "Copy assignement operator called" << std::endl;
    _value = rSym.getRawBits();
    return *this;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return _value;
}

void Fixed::setRawBits(int const raw) {
    _value = raw;
}