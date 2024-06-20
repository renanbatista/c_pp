#include "../include/Dog.hpp"

Dog::Dog(void) : Animal("Dog") {
    std::cout << YELLOW << "Dog was created." << std::endl << RESET;
    type = "Dog";
}

Dog::Dog(Dog const &copy) : Animal(copy) {
    std::cout << GRAY << "A copy Dog was created." << std::endl << RESET;
    *this = copy;
}

Dog::~Dog(void) {
    std::cout << RED << "Dog was destroyed." << std::endl << RESET;
}

Dog &Dog::operator=(Dog const &other) {
    std::cout << GREEN << "Dog copied by assignment operator." << std::endl << RESET;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

void Dog::makeSound(void) const {
    std::cout << CYAN << "Au au au" << std::endl << RESET;
}