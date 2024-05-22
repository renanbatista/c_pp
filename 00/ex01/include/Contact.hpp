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
};

#endif