#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
    private:
        Brain* _brain;

    public:
        Dog(void);
        Dog(Dog const& copy);
        ~Dog(void);

        Dog& operator=(Dog const& other);

        void        makeSound(void) const;
        std::string getIdea(int n) const;
};

#endif