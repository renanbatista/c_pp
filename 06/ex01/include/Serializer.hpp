#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>

#include <iostream>

#include "Data.hpp"

class Serializer {
    private:
        Serializer(void);
        Serializer(Serializer const& copy);
        ~Serializer(void);
        Serializer& operator=(Serializer const& other);

    public:
        static uintptr_t serialize(Data* ptr);
        static Data*     deserialize(uintptr_t raw);
};

#endif