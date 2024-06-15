#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    std::cout << "ScavTrap default constructor called" << std::endl;
    _name         = "Scavie";
    _hitPoints    = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap default destructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    std::cout << "ScavTrap named constructor called" << std::endl;
    _name         = name;
    _hitPoints    = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy) {
    std::cout << "ScavTrap Copy Assignment constructor called" << std::endl;
    _name         = copy._name;
    _hitPoints    = copy._hitPoints;
    _energyPoints = copy._energyPoints;
    _attackDamage = copy._attackDamage;
    return (*this);
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy) {
    *this = copy;
}

void ScavTrap::attack(const std::string& target) {
    if (_energyPoints == 0) {
        std::cout << "ScavTrap " << _name << " has no will to attack." << std::endl;
        return;
    } else if (_hitPoints == 0) {
        std::cout << "ScavTrap " << _name << " already died and can't attack." << std::endl;
        return;
    }
    std::cout << "ScavTrap " << _name << " atack " << target << " causing damage: " << _attackDamage
              << " hit points." << std::endl;
    _energyPoints--;
}

void ScavTrap::guardGate(void) {
    std::cout << _name << " is now guarding." << std::endl;
}