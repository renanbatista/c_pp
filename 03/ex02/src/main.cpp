
#include "../include/FragTrap.hpp"

int main(void) {
    std::cout << YELLOW << "\n-------> OBJECT CONSTRUCTORS\n" << RESET << std::endl;

    FragTrap goodFrag("GoodFrag");
    FragTrap evilFrag("EvilFrag");
    FragTrap frag3;

    frag3 = goodFrag;

    std::cout << YELLOW << "\n-------> OBJECT OWN METHODS\n" << RESET << std::endl;
    goodFrag.attack("EvilFrag");
    evilFrag.takeDamage(goodFrag.getAttackDamage());
    evilFrag.attack("GoodFrag");
    goodFrag.takeDamage(evilFrag.getAttackDamage());
    goodFrag.beRepaired(10);
    goodFrag.highFivesGuys();

    std::cout << YELLOW << "\n-------> OBJECT DESTRUCTOR\n" << RESET << std::endl;
    return (0);
}