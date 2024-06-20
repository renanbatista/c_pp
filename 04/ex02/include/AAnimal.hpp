#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

#include "format.hpp"

class AAnimal {
    protected:
        std::string type;

    public:
        AAnimal(void);
        AAnimal(std::string type);
        AAnimal(AAnimal const &copy);
        virtual ~AAnimal(void);

        AAnimal &operator=(AAnimal const &other);

        std::string  getType(void) const;
        virtual void makeSound(void) const = 0;
};

#endif