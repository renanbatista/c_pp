#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
   private:
    std::string const _name;
    bool              _signed;
    int const         _gradeSign;
    int const         _gradeExec;

   public:
    Form(void);
    Form(std::string const &name, int gradeSign, int gradeExec);
    Form(Form const &copy);
    ~Form(void);

    Form &operator=(Form const &other);

    std::string getName(void) const;
    bool        getSigned(void) const;
    int         getGradeSign(void) const;
    int         getGradeExec(void) const;

    void beSigned(Bureaucrat &bureaucrat);

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

std::ostream &operator<<(std::ostream &out, Form const &form);

#endif