#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
   private:
    std::string _target;

   public:
    PresidentialPardonForm(std::string fileName);
    PresidentialPardonForm(PresidentialPardonForm const &copy);
    virtual ~PresidentialPardonForm(void);

    PresidentialPardonForm &operator=(PresidentialPardonForm const &other);

    void execute(Bureaucrat const &executor) const
        throw(FormNotSignedException, GradeTooLowException);
};

#endif