#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {
    std::cout << YELLOW << "WrongCat was created!" << std::endl << RESET;
    type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const &copy) : WrongAnimal(copy) {
    std::cout << GRAY << "A copy WrongCat was created!" << std::endl << RESET;
    *this = copy;
}

WrongCat::~WrongCat(void) {
    std::cout << RED << "WrongCat was destroyed!" << std::endl << RESET;
}

WrongCat &WrongCat::operator=(WrongCat const &other) {
    std::cout << GREEN << "WrongCat copied by assignment operator" << std::endl << RESET;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

void WrongCat::makeSound(void) const {
    std::cout << CYAN << "Miau? Or not?" << std::endl << RESET;
}