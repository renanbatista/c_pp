#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "../include/Weapon.hpp"

class HumanA
{
  private:
    std::string _name;
    Weapon&     _weapon;

  public:
    HumanA(std::string name, Weapon& weapon);
    ~HumanA(void);

    std::string getName(void) const;
    Weapon      getWeapon(void) const;

    void setName(std::string name);
    void setWeapon(Weapon& weapon);

    void attack(void);
};

#endif