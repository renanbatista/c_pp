#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

const std::string RESET  = "\033[0m";
const std::string RED    = "\033[31;1m";
const std::string GREEN  = "\033[32;1m";
const std::string YELLOW = "\033[33;1m";
const std::string BLUE   = "\033[34;1m";
const std::string PURPLE = "\033[35;1m";
const std::string CYAN   = "\033[36;1m";
const std::string GRAY   = "\033[37;1m";

class Weapon
{
  private:
    std::string _type;

  public:
    Weapon(std::string type);
    Weapon(void);
    ~Weapon(void);

    std::string const& getType(void) const;
    void               setType(std::string type);
};

#endif