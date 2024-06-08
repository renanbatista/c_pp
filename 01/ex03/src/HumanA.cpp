#include "../include/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon)
  : _name(name)
  , _weapon(weapon)
{
}

HumanA::~HumanA(void) {}

std::string
HumanA::getName(void) const
{
    return (_name);
}

Weapon
HumanA::getWeapon(void) const
{
    return (_weapon);
}

void
HumanA::setName(std::string name)
{
    _name = name;
}

void
HumanA::setWeapon(Weapon& weapon)
{
    _weapon = weapon;
}

void
HumanA::attack(void)
{
    std::cout << YELLOW;
    std::cout << _name << " attacks with their ";
    std::cout << _weapon.getType() << std::endl;
}