#ifndef _BASE_HPP_
#define _BASE_HPP_

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdexcept>
#include <string>

#include "format.hpp"
typedef std::string str;

class Base {
    public:
        virtual ~Base();
};

Base* generate(void);
void  identify(Base* p);
void  identify(Base& p);

#endif