#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(GRADE_MIN)
{
    std::cout << GREEN << "A bureaucrat has been created with default values" << std::endl << RESET;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name)
{
    if (grade < GRADE_MAX)
        throw GradeTooHighException();
    else if (grade > GRADE_MIN)
        throw GradeTooLowException();
    else
        this->_grade = grade;
    std::cout << GREEN << "A bureaucrat has been created\nwith name " << YELLOW << this->_name
              << GREEN << " and grade " << YELLOW << this->_grade << "\n"
              << std::endl
              << RESET;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy)
{
    std::cout << RESET << "Copy constructor called" << std::endl;
    *this = copy;
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << RED << "A bureaucrat has been destroyed\n" << std::endl << RESET;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
    std::cout << GREEN << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_grade = other._grade;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &actual)
{
    out << CYAN << actual.getName() << ", bureaucrat grade " << actual.getGrade() << "."
        << std::endl;
    return out;
}

std::string const Bureaucrat::getName(void) const
{
    return this->_name;
}

int Bureaucrat::getGrade(void) const
{
    return this->_grade;
}

void Bureaucrat::upGrade(void)
{
    if (this->_grade - 1 < GRADE_MAX)
        throw GradeTooHighException();
    else
    {
        this->_grade--;
        std::cout << BLUE << this->_name << " has been promoted to grade " << this->_grade << RESET
                  << std::endl;
    }
}

void Bureaucrat::downGrade(void)
{
    if (this->_grade + 1 > GRADE_MIN)
        throw GradeTooLowException();
    else
    {
        this->_grade++;
        std::cout << GRAY << this->_name << " has been demoted to grade " << this->_grade << RESET
                  << std::endl;
    }
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high!!!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low!!!";
}

void Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << GREEN << this->_name << BLUE << " signed ";
        std::cout << GREEN << form.getName() << RESET << std::endl << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << BLUE << this->_name << YELLOW << " couldn’t sign ";
        std::cout << BLUE << form.getName() << YELLOW << "  because " << CYAN;
        std::cout << e.what() << std::endl << std::endl << RESET;
    }
}
