#include "Fixed.hpp"

#include <math.h>

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(Fixed const &src) {
    *this = src;
}

Fixed::Fixed(const int n) {
    _value = n << _bits;
}

Fixed::Fixed(const float f) : _value(f) {
    _value = roundf(f * (1 << _bits));
}

Fixed::~Fixed() {}

Fixed &Fixed::operator=(Fixed const &obj) {
    if (this != &obj)
        _value = obj.getRawBits();
    return *this;
}

Fixed Fixed::operator+(Fixed const &obj) const {
    return Fixed(toFloat() + obj.toFloat());
}

Fixed Fixed::operator-(Fixed const &obj) const {
    return Fixed(toFloat() - obj.toFloat());
}

Fixed Fixed::operator*(Fixed const &obj) const {
    return Fixed(toFloat() * obj.toFloat());
}

Fixed Fixed::operator/(Fixed const &obj) const {
    return Fixed(toFloat() / obj.toFloat());
}

bool Fixed::operator<(Fixed const &obj) const {
    if (getRawBits() < obj.getRawBits())
        return true;
    return false;
}

bool Fixed::operator>(Fixed const &obj) const {
    if (getRawBits() > obj.getRawBits())
        return true;
    return false;
}

bool Fixed::operator<=(Fixed const &obj) const {
    if (getRawBits() <= obj.getRawBits())
        return true;
    return false;
}

bool Fixed::operator>=(Fixed const &obj) const {
    if (getRawBits() >= obj.getRawBits())
        return true;
    return false;
}

bool Fixed::operator==(Fixed const &obj) const {
    if (getRawBits() == obj.getRawBits())
        return true;
    return false;
}

bool Fixed::operator!=(Fixed const &obj) const {
    if (getRawBits() != obj.getRawBits())
        return true;
    return false;
}

Fixed &Fixed::operator++() {
    _value++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp(*this);

    operator++();
    return tmp;
}

Fixed &Fixed::operator--() {
    _value--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);

    operator--();
    return tmp;
}

int Fixed::getRawBits() const {
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

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    if (a < b)
        return a;
    return b;
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b) {
    if (a < b)
        return a;
    return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    if (a > b)
        return a;
    return b;
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b) {
    if (a > b)
        return a;
    return b;
}

std::ostream &operator<<(std::ostream &o, Fixed const &obj) {
    o << obj.toFloat();
    return o;
}