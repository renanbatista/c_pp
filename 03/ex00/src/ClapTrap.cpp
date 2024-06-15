#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "Constructor called" << std::endl;
}

ClapTrap::ClapTrap() : _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &copy) {
    std::cout << "ClapTrap Copy constructor called" << std::endl;
    *this = (ClapTrap &)copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy) {
    std::cout << "ClapTrap Copy Assignment constructor called" << std::endl;
    if (this != &copy) {
        _name         = copy._name;
        _hitPoints    = copy._hitPoints;
        _energyPoints = copy._energyPoints;
        _attackDamage = copy._attackDamage;
    }
    return (*this);
}

void ClapTrap::attack(const std::string &target) {
    if (_hitPoints <= 0) {
        std::cout << "ClapTrap " << _name << " is dead. Could not attack" << std::endl;
        return;
    }
    if (_energyPoints <= 0) {
        std::cout << "ClapTrap " << _name << " has no energy points left. Could not attack"
                  << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _attackDamage
              << " points of damage!" << std::endl;
    _energyPoints -= 1;
    std::cout << "1 energy point spent on attacking" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoints < amount)
        _hitPoints = 0;
    else
        _hitPoints -= amount;
    std::cout << "ClapTrap " << _name << " was damaged by " << amount << ". Now has " << _hitPoints
              << " Hit points left" << std::endl;
    return;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_energyPoints <= 0) {
        std::cout << "ClapTrap " << _name << " has no energy points left. Could not be repaired"
                  << std::endl;
        return;
    } else if (_hitPoints <= 0) {
        std::cout << "ClapTrap " << _name << " is dead. Could not be repaired" << std::endl;
        return;
    }

    _hitPoints += amount;
    _energyPoints -= 1;

    std::cout << "ClapTrap " << _name << " repaired " << amount << " of Hit Points. Now has "
              << _hitPoints << " Hit points left" << std::endl;
    std::cout << "1 energy point spent on repairing. Now has " << _energyPoints << " left"
              << std::endl;
}

std::string ClapTrap::getName() {
    return (_name);
}

unsigned int ClapTrap::getHitPoints() {
    return (_hitPoints);
}

unsigned int ClapTrap::getEnergyPoints() {
    return (_energyPoints);
}

unsigned int ClapTrap::getAttackDamage() {
    return (_attackDamage);
}

void ClapTrap::setHitPoints(unsigned int amount) {
    _hitPoints = amount;
}

void ClapTrap::setEnergyPoints(unsigned int amount) {
    _energyPoints = amount;
}

void ClapTrap::setAttackDamage(unsigned int amount) {
    _attackDamage = amount;
}