#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat") {
    std::cout << YELLOW << "Cat was created." << std::endl << RESET;
    this->type   = "Cat";
    this->_brain = new Brain();
}

Cat::Cat(Cat const &copy) : Animal(copy) {
    std::cout << GRAY << "A copy Cat was created." << std::endl << RESET;
    this->type   = copy.type;
    this->_brain = new Brain(*copy._brain);
}

Cat::~Cat(void) {
    std::cout << RED << "Cat was destroyed." << std::endl << RESET;
    delete this->_brain;
}

Cat &Cat::operator=(Cat const &other) {
    std::cout << GREEN << "Cat copied by assignment operator." << std::endl << RESET;
    if (this != &other) {
        this->type   = other.type;
        this->_brain = new Brain(*other._brain);
    }
    return *this;
}

void Cat::makeSound(void) const {
    std::cout << CYAN << "Miau miau miau" << std::endl << RESET;
}

std::string Cat::getIdea(int n) const {
    return this->_brain->getIdea(n);
}