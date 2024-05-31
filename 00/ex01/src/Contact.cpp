#include "../include/Contact.hpp"

Contact::Contact(void) {}

Contact::~Contact(void) {}

std::string
Contact::getFirstName(void) const
{
    return firstName_;
}

std::string
Contact::getLastName(void) const
{
    return lastName_;
}

std::string
Contact::getNickname(void) const
{
    return nickName_;
}

std::string
Contact::getPhoneNumber(void) const
{
    return phone_;
}

std::string
Contact::getDarkestSecret(void) const
{
    return darkestSecret_;
}

void
Contact::setFirstName(std::string firstName)
{
    firstName_ = firstName;
}

void
Contact::setLastName(std::string lastName)
{
    lastName_ = lastName;
}

void
Contact::setNickname(std::string nickName)
{
    nickName_ = nickName;
}

void
Contact::setPhoneNumber(std::string phone)
{
    phone_ = phone;
}

void
Contact::setDarkestSecret(std::string darkestSecret)
{
    darkestSecret_ = darkestSecret;
}

void
Contact::printContact(void)
{
    std::cout << std::endl << RESET << "First name:       " << BLUE << firstName_ << std::endl;
    std::cout << RESET << "Last name:        " << BLUE << lastName_ << std::endl;
    std::cout << RESET << "Nickname:         " << BLUE << nickName_ << std::endl;
    std::cout << RESET << "Phone number:     " << BLUE << phone_ << std::endl;
    std::cout << RESET << "Darkest secret:   " << BLUE << darkestSecret_ << std::endl;
}