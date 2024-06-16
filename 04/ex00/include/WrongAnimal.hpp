#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include  "format.hpp"
class WrongAnimal {
    protected:
        std::string type;

    public:
        WrongAnimal(void);
        WrongAnimal(std::string typeInput);
        WrongAnimal(WrongAnimal const &copy);
        virtual ~WrongAnimal(void);

        WrongAnimal &operator=(WrongAnimal const &other);

        std::string getType(void) const;
        void        makeSound(void) const;
};

#endif