#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
    public:
        Fixed();
        Fixed(Fixed const &src);
        Fixed(const int n);
        Fixed(const float f);
        ~Fixed();

        Fixed &operator=(Fixed const &rSym);
        Fixed  operator+(Fixed const &rSym) const;
        Fixed  operator-(Fixed const &rSym) const;
        Fixed  operator*(Fixed const &rSym) const;
        Fixed  operator/(Fixed const &rSym) const;
        bool   operator<(Fixed const &rSym) const;
        bool   operator>(Fixed const &rSym) const;
        bool   operator<=(Fixed const &rSym) const;
        bool   operator>=(Fixed const &rSym) const;
        bool   operator==(Fixed const &rSym) const;
        bool   operator!=(Fixed const &rSym) const;
        Fixed &operator++();
        Fixed  operator++(int);
        Fixed &operator--();
        Fixed  operator--(int);

        int   getRawBits() const;
        void  setRawBits(int const raw);
        float toFloat() const;
        int   toInt() const;

        static Fixed       &min(Fixed &a, Fixed &b);
        static Fixed const &min(Fixed const &a, Fixed const &b);
        static Fixed       &max(Fixed &a, Fixed &b);
        static Fixed const &max(Fixed const &a, Fixed const &b);

    private:
        int              _value;
        static const int _bits = 8;
};

std::ostream &operator<<(std::ostream &o, Fixed const &rSym);

#endif