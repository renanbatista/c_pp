#include "../include/HumanA.hpp"
#include "../include/HumanB.hpp"

int
main(void)
{
    std::cout << CYAN << "-----> UNNECESSARY VIOLENCE TEST <-----" << std::endl;

    std::cout << GRAY << "-----> Weapon as a Reference" << std::endl;
    std::cout << RESET << "Instance a Weapon of type 'crude spiked club'..." << std::endl;
    std::cout << "Instance a HumanA named Bob, with a crude spiked club Weapon..." << std::endl;
    std::cout << "HumanA Bob attack first time with the instancied Weapon..." << std::endl;
    std::cout << GRAY << "-----------------------------------------------------------------------"
              << RESET << std::endl;
    {
        Weapon club = Weapon("crude spiked club");

        HumanA bob("Bob", club);
        bob.attack();

        std::cout << GRAY
                  << "-----------------------------------------------------------------------"
                  << std::endl;
        std::cout << RESET << "Weapon type is changed to 'some other type of club' with setType..."
                  << std::endl;
        std::cout << "HumanA Bob attack again, with the Weapon type changed..." << std::endl;
        std::cout << GRAY
                  << "-----------------------------------------------------------------------"
                  << std::endl;
        std::cout << RESET;

        club.setType("some other type of club");
        bob.attack();

        std::cout << GRAY
                  << "-----------------------------------------------------------------------"
                  << std::endl;
        std::cout << "-----> Weapon as a Pointer <-----" << std::endl;
        std::cout << RESET << "Instance a Weapon of type 'crude spiked club'..." << std::endl;
        std::cout << "Instance a HumanB named Jim, with no Weapon..." << std::endl;
        std::cout << "HumanB Jim attack first time with no Weapon..." << std::endl;
        std::cout << GRAY
                  << "-----------------------------------------------------------------------"
                  << RESET << std::endl;
    }
    {
        Weapon club = Weapon("crude spiked club");

        HumanB jim("Jim");
        jim.attack();

        std::cout << GRAY
                  << "-----------------------------------------------------------------------"
                  << std::endl;
        std::cout << RESET
                  << "Set the Weapon of Jim to the instanciated Weapon 'crude spiked club'..."
                  << std::endl;
        std::cout << "HumanB Jim attack again with the setted Weapon..." << std::endl;
        std::cout << "-----------------------------------------------------------------------"
                  << RESET << std::endl;
        jim.setWeapon(club);
        jim.attack();

        std::cout << GRAY
                  << "-----------------------------------------------------------------------"
                  << std::endl;
        std::cout << RESET << "Weapon type is changed to 'some other type of club' with setType..."
                  << std::endl;
        std::cout << "HumanB Jim attack again, with the Wheapon type changed..." << std::endl;
        std::cout << GRAY
                  << "-----------------------------------------------------------------------"
                  << RESET << std::endl;
        club.setType("some other type of club");
        jim.attack();

        std::cout << GRAY
                  << "-----------------------------------------------------------------------"
                  << std::endl;
        std::cout << RESET << std::endl;
    }
    return (0);
}