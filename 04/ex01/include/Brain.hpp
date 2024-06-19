#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
    private:
        std::string _ideas[100];

    public:
        Brain(void);
        Brain(const Brain &source);
        ~Brain(void);

        Brain &operator=(const Brain &other);

        std::string *getIdeas(void);
};

#endif