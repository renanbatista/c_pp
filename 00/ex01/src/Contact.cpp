#include "../include/Contact.hpp"

Contact::Contact(std::string firstName,
                 std::string lastName,
                 std::string nickName,
                 std::string phone,
                 std::string darkestSecret)
{
    firstName_     = firstName;
    lastName_      = lastName;
    nickName_      = nickName;
    phone_         = phone;
    darkestSecret_ = darkestSecret;
}

std::string
Contact::getFirstName(void)
{
    return (firstName_);
};

std::string
Contact::getLastName(void)
{
    return (lastName_);
};