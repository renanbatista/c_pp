#include "../include/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    std::cout << "FragTrap default constructor called" << std::endl;
    _name         = "Fragie";
    _hitPoints    = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    std::cout << "FragTrap named constructor called" << std::endl;
    _name         = name;
    _hitPoints    = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap default destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& copy) {
    std::cout << "FragTrap Copy Assignment constructor called" << std::endl;
    _name         = copy._name;
    _hitPoints    = copy._hitPoints;
    _energyPoints = copy._energyPoints;
    _attackDamage = copy._attackDamage;
    return (*this);
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy) {
    std::cout << "FragTrap copy constructor called" << std::endl;
	*this = copy;
}

void FragTrap::highFivesGuys(void) {
    std::cout << _name << " high fives all." << std::endl;
}