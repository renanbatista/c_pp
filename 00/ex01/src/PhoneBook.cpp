#include "../include/PhoneBook.hpp"
#include "../include/Contact.hpp"
#include <iostream>

PhoneBook::PhoneBook(void)
{
    currentContact = 0;
    for (int i = 0; i < 8; i++)
        contacts[i] = Contact();
}

PhoneBook::~PhoneBook(void) {}

void
PhoneBook::addContact(void)
{
    if (currentContact >= 8)
        currentContact = 0;
    contacts[currentContact].setFirstName(getInfo("First name: "));
    std::cout<< contacts[currentContact].getFirstName() <<std::endl;
    contacts[currentContact].setLastName(getInfo("Last name: "));
    contacts[currentContact].setNickname(getInfo("Nickname: "));
    contacts[currentContact].setPhoneNumber(getInfo("Phone number: "));
    contacts[currentContact].setDarkestSecret(getInfo("Darkest secret: "));
    currentContact++;
}

Contact
PhoneBook::getContact(int i)
{
    return contacts[i];
}

std::string
PhoneBook::getInfo(std::string text) const
{
    std::string input;
    std::cout << GRAY << text << std::endl << RESET << "           ";
    do
    {
        std::cin.ignore();
        std::getline(std::cin, input);
        if (input.empty())
            std::cout << RED << "Invalid input" << std::endl;
    } while (input.empty());
    return (input);
}
