#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) {
    std::cout << YELLOW << "WrongAnimal was created!" << std::endl << RESET;
}

WrongAnimal::WrongAnimal(std::string typeInput) : type(typeInput) {
    std::cout << GREEN << "WrongAnimal of the type " << typeInput << " was created!" << std::endl
              << RESET;
    type = typeInput;
}

WrongAnimal::WrongAnimal(WrongAnimal const &copy) {
    std::cout << GRAY << "A copy WrongAnimal was created!" << std::endl << RESET;
    *this = copy;
}

WrongAnimal::~WrongAnimal(void) {
    std::cout << RED << "WrongAnimal was destroyed!" << std::endl << RESET;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &other) {
    std::cout << GREEN << "WrongAnimal copied by assignment operator" << std::endl << RESET;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

std::string WrongAnimal::getType(void) const {
    return type;
}

void WrongAnimal::makeSound(void) const {
    std::cout << GRAY;
    if (type == "WrongCat")
        std::cout << "Miau? Or not?" << std::endl;
    else
        std::cout << "I don't know what to do" << std::endl << RESET;
}