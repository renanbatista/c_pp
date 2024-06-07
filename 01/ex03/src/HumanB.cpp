#include "../include/HumanB.hpp"

HumanB::HumanB(std::string name)
  : _name(name)
{
    this->_weapon = NULL;
}

HumanB::~HumanB(void) {}

std::string
HumanB::getName(void) const
{
    return (_name);
}

Weapon
HumanB::getWeapon(void) const
{
    return (*_weapon);
}

void
HumanB::setName(std::string name)
{
    this->_name = name;
}

void
HumanB::setWeapon(Weapon& weapon)
{
    this->_weapon = &weapon;
}

void
HumanB::attack(void)
{
    std::cout << YELLOW;
    std::cout << _name << " attacks with their ";
    if (!_weapon)
        std::cout << "your hands" << std::endl;
    else
        std::cout << this->_weapon->getType() << std::endl;
}