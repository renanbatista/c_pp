#include "Animal.hpp"

Animal::Animal(void) {
    std::cout << YELLOW << "Animal was created." << std::endl << RESET;
}

Animal::Animal(std::string typeInput) : type(typeInput) {
    std::cout << GREEN << "Type of Animal: " << type << " was created." << std::endl << RESET;
}

Animal::Animal(Animal const &copy) {
    std::cout << GRAY << "A copy Animal was created." << std::endl << RESET;
    *this = copy;
}

Animal::~Animal(void) {
    std::cout << RED << "Animal was destroyed" << std::endl << RESET;
}

Animal &Animal::operator=(Animal const &copy) {
    std::cout << GREEN << "Animal copied by assignment operator" << std::endl << RESET;
    if (this != &copy) {
        type = copy.getType();
    }
    return *this;
}

std::string Animal::getType(void) const {
    return type;
}

void Animal::makeSound(void) const {
    std::cout << GRAY << "Animal sound." << std::endl << RESET;
}