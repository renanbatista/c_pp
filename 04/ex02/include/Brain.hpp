#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <format.hpp>
#include <iostream>
#include <stdlib.h>

class Brain {
    public:
        Brain();
        ~Brain();
        Brain(Brain const &copy);

        Brain      &operator=(Brain const &copy);
        std::string getIdea(int n) const;

    protected:
        std::string ideas[100];
};

#endif