#ifndef _FIXED_HPP_
#define _FIXED_HPP_

#include <iostream>

class Fixed {
    public:
        Fixed();
        Fixed(Fixed const& src);
        Fixed(const int number);
        Fixed(const float f);
        ~Fixed();

        Fixed& operator=(Fixed const& rSym);
        int    getRawBits() const;
        void   setRawBits(int const raw);
        float  toFloat() const;
        int    toInt() const;

    private:
        int              _value;
        static const int _bits = 8;
};

std::ostream& operator<<(std::ostream& o, Fixed const& rSym);

#endif