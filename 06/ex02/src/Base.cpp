#include "../include/Base.hpp"

#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"

Base::~Base(void) {}

void identify(Base *p) {
    std::cout << "func: identify(Base *p): "<< std::endl;
    if (dynamic_cast<A *>(p))
        std::cout << "The pointer is a A type." << std::endl;
    if (dynamic_cast<B *>(p))
        std::cout << "The pointer is a B type." << std::endl;
    if (dynamic_cast<C *>(p))
        std::cout << "The pointer is a C type." << std::endl;
}

void identify(Base &p) {
    std::cout << "func: identify(Base &p): "<< std::endl;
    try
    {
        A &a = dynamic_cast<A &>(p);
        (void)a;
        std::cout << "The pointer is a A type." << std::endl;
    } catch (const std::exception &e)
    {}
    try
    {
        B &b = dynamic_cast<B &>(p);
        (void)b;
        std::cout << "The pointer is a B type." << std::endl;
    } catch (const std::exception &e)
    {}
    try
    {
        C &c = dynamic_cast<C &>(p);
        (void)c;
        std::cout << "The pointer is a C type." << std::endl;
    } catch (const std::exception &e)
    {}
}

Base *generate() {
    switch (std::rand() % 3)
    {
        case 0:
            std::cout << "Class A is instanciated." << std::endl;
            return new A;
        case 1:
            std::cout << "Class B is instanciated." << std::endl;
            return new B;
        case 2:
            std::cout << "Class C is instanciated." << std::endl;
            return new C;
    }
    return NULL;
}