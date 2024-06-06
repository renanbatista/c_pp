#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    _name = name;
    std::cout << GRAY << _name << ": zombie created " << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << GRAY << _name << ": zombie destroyed\n" << std::endl;
}

void
Zombie::announce(void)
{
    std::cout << GRAY << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}