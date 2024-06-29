#include "Data.hpp"

Data::Data(void) : _number(0), _name("Default") {
    std::cout << GREEN << "Data contructor called with default values!" << std::endl
              << std::endl
              << RESET;
}

Data::Data(int index, std::string name) : _number(index), _name(name) {
    std::cout << GREEN << "Data contructor called with index " << BLUE << this->_number
              << std::endl;
    std::cout << GREEN << "and name '" << BLUE << this->_name << GREEN << "' of index!" << std::endl
              << RESET;
}

Data::Data(Data const &copy) {
    *this = copy;
    std::cout << "Data copy constructor called" << std::endl;
}

Data::~Data(void) {
    std::cout << RED << "Data destroyed!" << std::endl << RESET;
}

Data &Data::operator=(Data const &other) {
    if (this != &other)
    {
        this->_number = other._number;
        this->_name = other._name;
    }
    std::cout << "Data copy assignment operator called" << std::endl;
    return *this;
}

std::ostream &operator<<(std::ostream &out, Data const &data) {
    out << GRAY << "Data Informations: " << std::endl;
    std::cout << "Number: " << BLUE << data.getIndex() << std::endl;
    std::cout << GRAY << "Name: " << BLUE << data.getName() << std::endl;
    std::cout << RESET;
    return out;
}

int Data::getIndex(void) const {
    return this->_number;
}

std::string Data::getName(void) const {
    return this->_name;
}

void Data::setIndex(int index) {
    this->_number = index;
}

void Data::setName(std::string name) {
    this->_name = name;
}
