#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
   private:
    std::string _target;

   public:
    RobotomyRequestForm(std::string fileName);
    RobotomyRequestForm(RobotomyRequestForm const &copy);
    virtual ~RobotomyRequestForm(void);

    RobotomyRequestForm &operator=(RobotomyRequestForm const &other);

    void execute(Bureaucrat const &executor) const
        throw(FormNotSignedException, GradeTooLowException);
};

#endif