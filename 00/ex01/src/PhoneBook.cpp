#include "../include/PhoneBook.hpp"
#include "../include/Contact.hpp"

PhoneBook::PhoneBook(void)
{
    currentContact = 0;
    for (int i = 0; i < 8; i++)
        contacts[i] = Contact();
}

PhoneBook::~PhoneBook(void) {}

void
PhoneBook::addContact(Contact contact)
{
    if (currentContact >= 8)
        currentContact = 0;
    contacts[currentContact].setFirstName(contact.getFirstName());
    contacts[currentContact].setLastName(contact.getLastName());
    contacts[currentContact].setNickname(contact.getNickname());
    contacts[currentContact].setPhoneNumber(contact.getPhoneNumber());
    contacts[currentContact].setDarkestSecret(contact.getDarkestSecret());
    currentContact++;
}

Contact
PhoneBook::getContact(int i)
{
    return contacts[i];
}
