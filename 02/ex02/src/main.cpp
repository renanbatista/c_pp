#include "Fixed.hpp"

int main(void) {
    {
        Fixed       a;
        Fixed const b(2);
        Fixed const c(3);
        Fixed const d(b);

        a = Fixed(1234.43f);

        std::cout << std::endl << "a= " << a << std::endl;
        std::cout << "b= " << b << std::endl;
        std::cout << "c= " << c << std::endl;
        std::cout << "d= " << d << std::endl;

        std::cout << "b + d : " << (b + d) << std::endl;
        std::cout << "b - c : " << (b - c) << std::endl;
        std::cout << "b * c : " << (b * c) << std::endl;
        std::cout << "c / b : " << (c / b) << std::endl;

        if (c < b)
            std::cout << "c < b" << std::endl;
        else if (c > b)
            std::cout << "c > b" << std::endl;
        else
            std::cout << "c >= b" << std::endl;
        if (b == d)
            std::cout << "b = d" << std::endl;
        else
            std::cout << "b != d" << std::endl;
        std::cout << "min(b, c) = " << Fixed::min(b, c) << std::endl;
        std::cout << "max(b, c) = " << Fixed::max(b, c) << std::endl;
    }
    {
        Fixed e;

        std::cout << "  e = " << e << std::endl;
        std::cout << "  --e = " << --e << std::endl;
        std::cout << "  e-- = " << e-- << std::endl;
        std::cout << "  e = " << e << std::endl;
    }
    {
        std::cout << std::endl << "------> PDF TESTS <------" << std::endl;
        Fixed       a;
        Fixed const b(Fixed(5.05f) * Fixed(2));
        std::cout << a << std::endl;
        std::cout << ++a << std::endl;
        std::cout << a << std::endl;
        std::cout << a++ << std::endl;
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << Fixed::max(a, b) << std::endl;
        return 0;
    }
    return 0;
}