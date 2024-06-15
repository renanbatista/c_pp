
#include "../include/ScavTrap.hpp"

int main(void) {
    std::cout << YELLOW << "\n-------> OBJECT CONSTRUCTORS\n" << RESET << std::endl;

    ScavTrap goodScav("GoodScav");
    ScavTrap evilScav("EvilScav");
    ScavTrap scav3;

    scav3 = goodScav;

    std::cout << YELLOW << "\n-------> OBJECT OWN METHODS\n" << RESET << std::endl;
    goodScav.attack("EvilScav");
    evilScav.takeDamage(goodScav.getAttackDamage());
    evilScav.attack("GoodScav");
    goodScav.takeDamage(evilScav.getAttackDamage());
    goodScav.beRepaired(10);
    goodScav.guardGate();

    std::cout << YELLOW << "\n-------> OBJECT DESTRUCTOR\n" << RESET << std::endl;
    return (0);
}