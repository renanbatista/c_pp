#include "AAnimal.hpp"

AAnimal::AAnimal(void) {
    std::cout << YELLOW << "AAnimal was created." << std::endl << RESET;
}

AAnimal::AAnimal(std::string typeInput) : type(typeInput) {
    std::cout << GREEN << "Type of AAnimal: " << type << " was created." << std::endl << RESET;
}

AAnimal::AAnimal(AAnimal const &copy) {
    std::cout << GRAY << "A copy AAnimal was created." << std::endl << RESET;
    *this = copy;
}

AAnimal::~AAnimal(void) {
    std::cout << RED << "AAnimal was destroyed" << std::endl << RESET;
}

AAnimal &AAnimal::operator=(AAnimal const &copy) {
    std::cout << GREEN << "AAnimal copied by assignment operator" << std::endl << RESET;
    if (this != &copy) {
        type = copy.getType();
    }
    return *this;
}

std::string AAnimal::getType(void) const {
    return type;
}

void AAnimal::makeSound(void) const {
    std::cout << GRAY << "AAnimal sound." << std::endl << RESET;
}