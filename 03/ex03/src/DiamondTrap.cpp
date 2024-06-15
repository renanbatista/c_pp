#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap() {
    std::cout << "DiamondTrap default constructor called" << std::endl;
    ScavTrap::_energyPoints = 50;
}

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name), FragTrap(name) {
    std::cout << "DiamondTrap named constructor called" << std::endl;
    _name             = name;
    ScavTrap::_energyPoints = 50;
    ClapTrap::_name         = name + "_clap_name";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& copy) {
    _name         = copy._name;
    _hitPoints    = copy._hitPoints;
    _energyPoints = copy._energyPoints;
    _attackDamage = copy._attackDamage;
    return (*this);
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap default destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy) {
    *this = copy;
}

void DiamondTrap::whoAmI() {
    std::cout << _name << std::endl;
    std::cout << ClapTrap::_name << std::endl;
}