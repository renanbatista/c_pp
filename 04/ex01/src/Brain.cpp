#include "../include/Brain.hpp"

Brain::Brain(void) {
    std::cout << "Default Brain constructor is created." << std::endl;
}

Brain::Brain(Brain const &copy) {
    std::cout << "Copy Brain constructor is created." << std::endl;
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = copy._ideas[i];
}

Brain::~Brain(void) {
    std::cout << "Default Brain of destructor is called." << std::endl;
}

Brain &Brain::operator=(const Brain &copy) {
    std::cout << "Brain assignment operator is called." << std::endl;
    if (this != &copy) {
        for (int i = 0; i < 100; i++)
            this->_ideas[i] = copy._ideas[i];
    }
    return (*this);
}

std::string *Brain::getIdeas(void) {
    return _ideas;
}