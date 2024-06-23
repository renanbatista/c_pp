#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("robotomy request", 72, 45)
{
    this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) : AForm(copy)
{
    *this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
    if (this != &other)
    {
        this->_target = other._target;
    }
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
    throw(FormNotSignedException, GradeTooLowException)
{
    AForm::execute(executor);
    
    if (rand() % 2 == 0)
    {
        std::cout << BLUE << this->_target << " - RobotomyRequestForm  successfully!" << RESET
                  << std::endl;
    }
    else
    {
        std::cout << YELLOW << this->_target;
        std::cout << " - RobotomyRequestForm failed" << RESET << std::endl;
    }
}