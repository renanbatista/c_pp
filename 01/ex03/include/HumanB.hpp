#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "../include/Weapon.hpp"

class HumanB
{
  private:
    Weapon*     _weapon;
    std::string _name;

  public:
    HumanB(std::string name);
    ~HumanB(void);

    std::string getName(void) const;
    Weapon      getWeapon(void) const;

    void setName(std::string name);
    void setWeapon(Weapon& weapon);

    void attack(void);
};

#endif