#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "format.hpp"

class Animal {
    protected:
        std::string type;

    public:
        Animal(void);
        Animal(std::string typeInput);
        Animal(Animal const &copy);
        virtual ~Animal(void);

        Animal &operator=(Animal const &other);

        std::string  getType(void) const;
        virtual void makeSound(void) const;
};

#endif