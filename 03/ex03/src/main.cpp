#include "DiamondTrap.hpp"

int main(void) {
    std::cout << YELLOW << "\n-------> OBJECT CONSTRUCTORS\n" << RESET << std::endl;

    DiamondTrap dTrap("Maria");

    std::cout << YELLOW << "\n-------> OBJECT OWN METHODS\n" << RESET << std::endl;

    dTrap.whoAmI();
    dTrap.attack("target");
    dTrap.guardGate();
    dTrap.highFivesGuys();
    dTrap.takeDamage(dTrap.getAttackDamage());
    dTrap.beRepaired(10);

    std::cout << YELLOW << "\n-------> OBJECT DESTRUCTOR\n" << RESET << std::endl;
    return (0);
}