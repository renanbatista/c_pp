#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>

#include "format.hpp"

#define GRADE_MAX 1
#define GRADE_MIN 150

class Bureaucrat
{
   private:
    std::string const _name;
    int               _grade;

   public:
    Bureaucrat(void);
    Bureaucrat(std::string const &name, int grade);
    Bureaucrat(Bureaucrat const &copy);
    ~Bureaucrat(void);

    Bureaucrat &operator=(Bureaucrat const &other);

    std::string const getName(void) const;
    int               getGrade(void) const;
    void              upGrade(void);
    void              downGrade(void);

    class GradeTooHighException : public std::exception
    {
       public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
       public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &actual);

#endif