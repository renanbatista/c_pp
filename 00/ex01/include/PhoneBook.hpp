#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

class PhoneBook
{
  private:
    Contact contacts[8];
    int     currentContact;

  public:
    PhoneBook(void);
    ~PhoneBook(void);

    void        addContact(void);
    Contact     getContact(int i);
    std::string getInfo(std::string text) const;
    void        printAllContacts(void);
};

#endif