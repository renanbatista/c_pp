#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << GREEN << "Constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap() : _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << RED << "Destructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
    std::cout << BLUE << "ClapTrap Copy constructor called" << RESET << std::endl;
    *this = (ClapTrap &)copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy) {
    std::cout << MAGENTA << "ClapTrap Copy Assignment constructor called" << RESET << std::endl;
    if (this != &copy) {
        this->_name         = copy._name;
        this->_hitPoints    = copy._hitPoints;
        this->_energyPoints = copy._energyPoints;
        this->_attackDamage = copy._attackDamage;
    }
    return (*this);
}

void ClapTrap::attack(const std::string &target) {
    if (_hitPoints <= 0) {
        std::cout << YELLOW << "ClapTrap " << _name << " is dead. Could not attack" << RESET
                  << std::endl;
        return;
    }
    if (_energyPoints <= 0) {
        std::cout << YELLOW << "ClapTrap " << _name
                  << " has no energy points left. Could not attack" << RESET << std::endl;
        return;
    }
    std::cout << YELLOW << "ClapTrap " << _name << " attacks " << target << " causing "
              << _attackDamage << " points of damage!" << RESET << std::endl;
    _energyPoints -= 1;
    std::cout << YELLOW << "1 energy point spent on attacking" << RESET << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoints < amount)
        _hitPoints = 0;
    else
        _hitPoints -= amount;
    std::cout << RED << "ClapTrap " << _name << " was damaged by " << amount << ". Now has "
              << _hitPoints << " Hit points(health) left" << RESET << std::endl;
    return;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_energyPoints <= 0) {
        std::cout << CYAN << "ClapTrap " << _name
                  << " has no energy points left. Could not be repaired" << RESET << std::endl;
        return;
    } else if (_hitPoints <= 0) {
        std::cout << CYAN << "ClapTrap " << _name << " is dead. Could not be repaired" << RESET
                  << std::endl;
        return;
    }

    _hitPoints += amount;
    _energyPoints -= 1;

    std::cout << CYAN << "ClapTrap " << _name << " repaired " << amount
              << " of Hit Points(health). Now has " << _hitPoints << " Hit points(health) left"
              << std::endl;
    std::cout << CYAN << "1 energy point spent on repairing. Now has " << _energyPoints << " left"
              << RESET << std::endl;
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