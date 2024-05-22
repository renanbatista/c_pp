#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
  private:
    Contact contacts[8];
    int     currentContact;

  public:
    PhoneBook(void);
    ~PhoneBook(void);

    void    addContact(void);
    Contact getContact(int i);
};

#endif