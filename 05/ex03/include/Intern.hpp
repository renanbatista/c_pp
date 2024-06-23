#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
  public:
    class FormDoesNotExistException : public std::exception
    {
      public:
        virtual const char* what() const throw();
    };

    Intern(void);
    Intern(Intern const& copy);
    ~Intern(void);

    Intern& operator=(Intern const& other);

    AForm* makeForm(std::string nameForm, std::string targetForm);
};

#endif