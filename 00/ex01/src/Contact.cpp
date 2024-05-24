#include "../include/Contact.hpp"

Contact::Contact(void){}

Contact::~Contact(void){}

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
    this->firstName_ = firstName;
}

void
Contact::setLastName(std::string lastName)
{
    this->lastName_ = lastName;
}

void
Contact::setNickname(std::string nickName)
{
    this->nickName_ = nickName;
}

void
Contact::setPhoneNumber(std::string phone)
{
    this->phone_ = phone;
}

void
Contact::setDarkestSecret(std::string darkestSecret)
{
    this->darkestSecret_ = darkestSecret;
}
