#include "Intern.hpp"

Intern::Intern(void)
{
    std::cout << MAGENTA << "A intern has been created!" << RESET << std::endl;
}

Intern::Intern(Intern const& copy)
{
    *this = copy;
    std::cout << "Intern copy constructor called" << std::endl;
}

Intern::~Intern(void)
{
    std::cout << RED << "A intern has been destroyed!" << std::endl << RESET;
}

Intern&
Intern::operator=(Intern const& other)
{
    (void)other;
    std::cout << "Intern copy assignment operator called" << std::endl;
    return *this;
}

AForm*
Intern::makeForm(std::string nameForm, std::string targetForm)
{
    const std::string formList[3] = { "shrubbery creation",
                                      "robotomy request",
                                      "presidential pardon" };
    for (int i = 0; i < 3; i++)
    {
        if (nameForm == formList[i])
        {
            std::cout << GREEN << "Intern creates " << CYAN << nameForm << std::endl << RESET;
            switch (i)
            {
                case 0:
                    return new ShrubberyCreationForm(targetForm);
                case 1:
                    return new RobotomyRequestForm(targetForm);
                case 2:
                    return new PresidentialPardonForm(targetForm);
                default:
                    throw Intern::FormDoesNotExistException();
            }
        }
    }
    throw Intern::FormDoesNotExistException();
    return NULL;
}

const char*
Intern::FormDoesNotExistException::what() const throw()
{
    return ("Undefined form");
}