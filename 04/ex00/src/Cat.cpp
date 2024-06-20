#include "../include/Cat.hpp"

Cat::Cat(void) : Animal("Cat") {
    std::cout << YELLOW << "Cat was created." << std::endl << RESET;
    type = "Cat";
}

Cat::Cat(Cat const &copy) : Animal(copy) {
    std::cout << GRAY << "A copy Cat was created." << std::endl << RESET;
    *this = copy;
}

Cat::~Cat(void) {
    std::cout << RED << "Cat was destroyed." << std::endl << RESET;
}

Cat &Cat::operator=(Cat const &other) {
    std::cout << GREEN << "Cat copied by assignment operator." << std::endl << RESET;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

void Cat::makeSound(void) const {
    std::cout << CYAN << "Miau miau miau" << std::endl << RESET;
}