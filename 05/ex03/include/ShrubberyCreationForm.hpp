#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
   private:
    std::string _target;

   public:
    ShrubberyCreationForm(std::string fileName);
    ShrubberyCreationForm(ShrubberyCreationForm const &copy);
    virtual ~ShrubberyCreationForm(void);

    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);

    void execute(Bureaucrat const &executor) const
        throw(FormNotSignedException, GradeTooLowException);
};

#endif