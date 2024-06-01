#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <algorithm>

// Color codes as global variables
const std::string RESET  = "\033[0m";
const std::string RED    = "\033[31;1m";
const std::string GREEN  = "\033[32;1m";
const std::string YELLOW = "\033[33;1m";
const std::string BLUE   = "\033[34;1m";
const std::string PURPLE = "\033[35;1m";
const std::string CYAN   = "\033[36;1m";
const std::string GRAY   = "\033[37;1m";

class Contact
{
  private:
    std::string firstName_;
    std::string lastName_;
    std::string nickName_;
    std::string phone_;
    std::string darkestSecret_;

  public:
    Contact(void);
    ~Contact(void);

    std::string getFirstName(void) const;
    std::string getLastName(void) const;
    std::string getNickname(void) const;
    std::string getPhoneNumber(void) const;
    std::string getDarkestSecret(void) const;

    void setFirstName(std::string firstName_);
    void setLastName(std::string lastName_);
    void setNickname(std::string nickName_);
    void setPhoneNumber(std::string phone_);
    void setDarkestSecret(std::string darkestSecret_);
    void printContact(void);
};

#endif