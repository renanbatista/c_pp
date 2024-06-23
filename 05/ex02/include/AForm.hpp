#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
   private:
    std::string const _name;
    bool              _signed;
    int const         _gradeSign;
    int const         _gradeExec;

   public:
    AForm(void);
    AForm(std::string const &name, int gradeSign, int gradeExec);
    AForm(Form const &copy);
    virtual ~AForm(void);

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

    class FormNotSignedException : public std::exception
    {
       public:
        virtual const char *what() const throw();
    };

    virtual void execute(Bureaucrat const &executor) const
        throw(FormNotSignedException, GradeTooLowException) = 0;
};

std::ostream &operator<<(std::ostream &out, Form const &form);

#endif