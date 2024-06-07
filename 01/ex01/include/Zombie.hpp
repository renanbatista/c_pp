#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

// Color codes as global variables
const std::string RESET  = "\033[0m";
const std::string RED    = "\033[31;1m";
const std::string GREEN  = "\033[32;1m";
const std::string YELLOW = "\033[33;1m";
const std::string BLUE   = "\033[34;1m";
const std::string PURPLE = "\033[35;1m";
const std::string CYAN   = "\033[36;1m";
const std::string GRAY   = "\033[37;1m";

class Zombie
{
  private:
    std::string _name;

  public:
    Zombie(void);
    ~Zombie(void);
    void announce(void);
    void setName(std::string name);
};

Zombie*
zombieHorde(int N, std::string name);

#endif