#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
   private:
    Brain* _brain;

   public:
    Cat(void);
    Cat(Cat const& copy);
    ~Cat(void);

    Cat& operator=(Cat const& other);

    void        makeSound(void) const;
    std::string getIdea(int n) const;
};

#endif