#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("presidential pardon", 25, 5)
{
    this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) : AForm(copy)
{
    *this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
    if (this != &other)
    {
        this->_target = other._target;
    }
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
    throw(FormNotSignedException, GradeTooLowException)
{
    AForm::execute(executor);
    std::cout << BLUE << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::cout << RESET << std::endl;
}