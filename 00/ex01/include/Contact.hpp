#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
  private:
    std::string firstName_;
    std::string lastName_;
    std::string nickName_;
    std::string phone_;
    std::string darkestSecret_;

  public:
    Contact(std::string firstName, std::string lastName, std::string nickName, std::string phone, std::string darkestSecret);
    ~Contact(void);

    std::string getFirstName(void);
    std::string getLastName(void);
    std::string getNickname(void);
    std::string getPhoneNumber(void);
    std::string getDarkestSecret(void);

    void setFirstName(std::string firstName_);
    void setLastName(std::string lastName_);
    void setNickname(std::string nickName_);
    void setPhoneNumber(std::string phone_);
    void setDarkestSecret(std::string darkestSecret_);
};

#endif