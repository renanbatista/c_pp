#include "../include/ClapTrap.hpp"

int main(void) {
    std::cout << YELLOW << "\n-------> OBJECT CONSTRUCTORS\n" << RESET << std::endl;

    ClapTrap none;
    ClapTrap player_I("player_I");
    ClapTrap player_II("player_II");
    ClapTrap copy_player(player_I);

    none = player_II;

    std::cout << YELLOW << "\n-------> OBJECT OWN METHODS\n" << RESET << std::endl;
    player_I.attack("player_II");

    player_II.takeDamage(player_I.getAttackDamage());
    player_II.beRepaired(20);
    std::cout << GRAY << "Player II Hit Point = " <<player_II.getHitPoints() << RESET << std::endl<< std::endl;
    player_II.attack("player_I");
    player_I.takeDamage(player_II.getAttackDamage());
    player_I.beRepaired(30);
    player_I.attack("player_II");
    std::cout << YELLOW << "\n-------> OBJECT DESTRUCTOR\n" << RESET << std::endl;
    return (0);
}