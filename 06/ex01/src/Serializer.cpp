#include "Serializer.hpp"

Serializer::Serializer(void) {
    std::cout << "Serializer default constructor called" << std::endl;
}

Serializer::Serializer(Serializer const& copy) {
    *this = copy;
    std::cout << "Serializer copy constructor called" << std::endl;
}

Serializer::~Serializer(void) {
    std::cout << "Serializer destructor called" << std::endl;
}

Serializer& Serializer::operator=(Serializer const& other) {
    if (this != &other)
        *this = other;
    std::cout << "Serializer copy assignment operator called" << std::endl;
    return *this;
}

uintptr_t Serializer::serialize(Data* ptr) {
    std::cout << GREEN << "Serializing!" << RESET << std::endl;
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    std::cout << YELLOW << "Deserializing!" << RESET << std::endl;
    return reinterpret_cast<Data*>(raw);
}