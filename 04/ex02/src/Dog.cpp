#include "../include/Dog.hpp"

Dog::Dog(void) : AAnimal("Dog") {
    std::cout << YELLOW << "Dog was created." << std::endl << RESET;
    this->type   = "Dog";
    this->_brain = new Brain();
}

Dog::Dog(Dog const &copy) : AAnimal(copy) {
    std::cout << GRAY << "A copy Dog was created." << std::endl << RESET;
    this->type = copy.type;
	this->_brain = new Brain(*copy._brain);
}

Dog::~Dog(void) {   
    std::cout << RED << "Dog was destroyed." << std::endl << RESET;
    delete this->_brain;
}

Dog &Dog::operator=(Dog const &other) {
    std::cout << GREEN << "Dog copied by assignment operator." << std::endl << RESET;
    if (this != &other) {
        this->type   = other.type;
        delete _brain;
        this->_brain = new Brain(*other._brain);
    }
    return *this;
}

void Dog::makeSound(void) const {
    std::cout << CYAN << "Au au au" << std::endl << RESET;
}

std::string Dog::getIdea(int n) const {
    return this->_brain->getIdea(n);
}