#include "../include/PhoneBook.hpp"
#include <iostream>
#include <cstdlib>

int
main(void)
{
    PhoneBook   phonebook;
    std::string input = "";

    std::cout << "--------------------------------" << std::endl;
    std::cout << "Welcome to your Phone Book" << std::endl;
    std::cout << "--------------------------------" << std::endl;
    while (true)
    {
        std::cout << YELLOW <<"\nSelect: ADD or SEARCH or EXIT" << std::endl << RESET;
        std::cout << "> " << std::flush;
        
        std::cin >> input;
        if (input.compare("EXIT") == 0)
        {
            std::cout << PURPLE << "---> See you later ! <----" << std::endl;
            exit(0);
        }
        else if (input.compare("ADD") == 0)
            phonebook.addContact();
        // else if (input.compare("SEARCH"))
        // phonebook.searchContact();
        else
            std::cout << "\nWrong input !\n" << std::endl;


    }
    return (0);
}