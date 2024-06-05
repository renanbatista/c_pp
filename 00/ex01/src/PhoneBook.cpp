#include "../include/PhoneBook.hpp"
#include "../include/Contact.hpp"
#include "../include/Utils.hpp"

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

    while (true)
    {
        do
        {
            std::cout << GRAY << text << RESET << std::endl;
            std::getline(std::cin, input);
            if (input.empty())
                std::cout << RED << "Empty input" << RESET << std::endl;
        } while (input.empty());
        if (text.compare("Phone number: ") == 0)
        {
            if (all_is_digits(input) && (input.size() == 10 || input.size() == 11))
                break;
            std::cout << RED << "Invalid input, must be a number and must be 10 or 11 digits."
                      << RESET << std::endl;
        }
        else
            break;
    }
    return (input);
}

void
PhoneBook::printAllContacts(void)
{
    std::cout << std::setw(10) << std::right << "Index" << "|";
    std::cout << std::setw(10) << std::right << "First name" << "|";
    std::cout << std::setw(10) << std::right << "Last name" << "|";
    std::cout << std::setw(10) << std::right << "Nickname" << std::endl;
    for (int i = 0; i < 8; i++)
    {
        if (contacts[i].getFirstName().empty() == 0)
        {
            std::cout.clear();
            std::cout << std::setw(10) << std::right << i << "|";
            std::cout << std::setw(10) << std::right
                      << contacts[i].getFirstName().substr(0, 9) +
                           (contacts[i].getFirstName().size() > 9 ? "." : "")
                      << "|";
            std::cout << std::setw(10) << std::right
                      << contacts[i].getLastName().substr(0, 9) +
                           (contacts[i].getLastName().size() > 9 ? "." : "")
                      << "|";
            std::cout << std::setw(10) << std::right
                      << contacts[i].getNickname().substr(0, 9) +
                           (contacts[i].getNickname().size() > 9 ? "." : "")
                      << std::endl;
        }
    }
    int index;
    std::cout << "Enter the index of the contact to display: " << std::endl;
    std::cin >> index;

    if (std::cin.fail() || (index < 0 || index > 7))
        std::cout << RED << "Invalid index" << std::endl;
    else
    {
        if (contacts[index].getFirstName().empty() == 0)
            contacts[index].printContact();
        else
            std::cout << RED << std::endl << "Contact not found" << std::endl;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}