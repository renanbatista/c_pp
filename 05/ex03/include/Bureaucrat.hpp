#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <cstdlib>
#include <ctime>
#include <exception>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

#include "AForm.hpp"
#include "format.hpp"

#define GRADE_MAX 1
#define GRADE_MIN 150

class AForm;

class Bureaucrat
{
  private:
    std::string const _name;
    int               _grade;

  public:
    class GradeTooHighException : public std::exception
    {
      public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
      public:
        virtual const char* what() const throw();
    };

    Bureaucrat(void);
    Bureaucrat(std::string const& name, int grade) throw(GradeTooHighException,
                                                         GradeTooLowException);
    Bureaucrat(Bureaucrat const& copy);
    ~Bureaucrat(void);

    Bureaucrat& operator=(Bureaucrat const& other);

    std::string const getName(void) const;
    int               getGrade(void) const;
    void              upGrade(void);
    void              downGrade(void);
    void              signForm(AForm& form);
    void              executeForm(AForm const& form);
};

std::ostream&
operator<<(std::ostream& out, Bureaucrat const& actual);
Add also a beSigned() member function to the Form that takes a Bureaucrat as
parameter.
#endif