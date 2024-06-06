#include "Zombie.hpp"

int
main(void)
{
    std::cout << CYAN << "---------> HEAP ALOCCATION <---------" << std::endl;
    std::cout << GREEN << "\nCalling newZombie" << std::endl;

    Zombie* boo = newZombie("Victor");

    std::cout << GREEN << "\nExplicit announce" << std::endl;

    boo->announce();

    std::cout << GREEN << "\nExplicit delete" << std::endl;

    delete boo;

    std::cout << "\n" << std::endl;

    std::cout << CYAN << "---------> TESTING STACK ALOCCATION <---------" << std::endl;
    std::cout << "\nCalling randomChump" << std::endl;
    std::cout << "Implicit announce in randomChump function" << std::endl;
    std::cout << "Implicit delete in randomChump function\n" << std::endl;

    randomChump("Paulo");

    std::cout << "\n" << std::endl;

    std::cout << CYAN << "---------> TESTING STACK ALOCCATION <---------" << std::endl;
    std::cout << "\nInstance of zombie" << std::endl;

    Zombie foo("Foo");

    std::cout << GREEN << "\nExplicit announce" << std::endl;

    foo.announce();

    std::cout << GREEN << "\nImplicit delete with the end of the program" << std::endl;
    std::cout << RESET;

    return (0);
}