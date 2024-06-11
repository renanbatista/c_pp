#include "Fixed.hpp"

// int main(void) {
//     Fixed       a;
//     Fixed const b(10);
//     Fixed const c(121.35f);
//     Fixed const d(b);

//     a = Fixed(1234.4321f);

//     std::cout << "a= " << a << std::endl;
//     std::cout << "b= " << b << std::endl;
//     std::cout << "c= " << c << std::endl;
//     std::cout << "d= " << d << std::endl;

//     std::cout << "b+d : " << (b + d) << std::endl;
//     std::cout << "b-c : " << (b - c) << std::endl;
//     std::cout << "b*c : " << (b * c) << std::endl;

//     if (c < b)
//         std::cout << "c < b" << std::endl;
//     else
//         std::cout << "c >= b" << std::endl;
//     if (b == d)
//         std::cout << "b = d" << std::endl;
//     else
//         std::cout << "b != d" << std::endl;
//     std::cout << a << " " << ++a << std::endl;
//     std::cout << Fixed::min(b, c) << std::endl;
//     std::cout << Fixed::max(b, c) << std::endl;
//     return 0;
// }

int main(void) {
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