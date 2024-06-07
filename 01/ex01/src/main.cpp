#include "../include/Zombie.hpp"

int
main(void)
{
    int numberOfZombies = 5;

    std::cout << CYAN << "-----> HEAP ALOCCATION <-----" << RESET << std::endl << std::endl;

    Zombie* horde = zombieHorde(numberOfZombies, "Vitor");

    std::cout << GRAY;
    std::cout << GREEN << "\nCalling announce for all zombies" << std::endl;

    for (int i = 0; i < numberOfZombies; i++)
        horde[i].announce();

    std::cout << GRAY;
    std::cout << GREEN << "\nExplicit delete all zombies of the horde" << std::endl;

    delete[] horde;

    std::cout << RESET << std::endl;
    return (0);
}