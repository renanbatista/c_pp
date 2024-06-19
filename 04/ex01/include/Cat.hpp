#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
    public:
        Cat(void);
        ~Cat(void);
        Cat(Cat const &copy);
        
        Cat &operator=(Cat const &copy);

        void makeSound(void) const;

    private:
        Brain *CatBrain;
};

#endif