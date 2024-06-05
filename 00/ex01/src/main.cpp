#include "../include/PhoneBook.hpp"
int
main(void)
{
    PhoneBook   phonebook;
    std::string input = "";

    std::cout << std::endl;
    std::cout << CYAN << "--------------------------------" << std::endl;
    std::cout << "Welcome to your Phone Book" << std::endl;
    std::cout << "--------------------------------" << RESET << std::endl;
    while (true)
    {
        std::cout << YELLOW <<"\nSelect: ADD or SEARCH or EXIT" << std::endl << RESET;
        std::getline(std::cin, input);
        if (input.compare("EXIT") == 0)
        {
            std::cout << std::endl << PURPLE << "---> See you later ! <----" << std::endl;
            exit(0);
        }
        else if (input.compare("ADD") == 0)
            phonebook.addContact();
        else if (input.compare("SEARCH") == 0)
            phonebook.printAllContacts();
        else
            std::cout << RED << "\nWrong input !\n" << RESET << std::endl;
    }
    return (0);
}