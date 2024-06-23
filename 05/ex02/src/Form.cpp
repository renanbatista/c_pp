#include "Form.hpp"

Form::Form(void) : _name("Default"), _gradeSign(GRADE_MAX), _gradeExec(GRADE_MAX)
{
    this->_signed = false;
    std::cout << GREEN << "A form has been created with default values." << std::endl << RESET;
}

Form::Form(std::string const &name, int gradeSign, int gradeExec)
    : _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
    if (gradeSign < GRADE_MAX || gradeExec < GRADE_MAX)
        throw GradeTooHighException();
    else if (gradeSign > GRADE_MIN || gradeExec > GRADE_MIN)
        throw GradeTooLowException();
    else
        this->_signed = false;
    std::cout << GREEN << "Form create. Name: " << BLUE << this->_name << std::endl;
    std::cout << GREEN << ", gradeSign: " << BLUE << this->_gradeSign << GREEN
              << ", gradeExec: " << BLUE << this->_gradeExec << std::endl
              << std::endl
              << RESET;
}

Form::Form(Form const &copy)
    : _name(copy._name), _gradeSign(copy._gradeSign), _gradeExec(copy._gradeExec)
{
    *this = copy;
    std::cout << RESET << "Form copy constructor called" << std::endl;
}

Form::~Form(void)
{
    std::cout << RED << "Form has been destroyed" << std::endl << RESET;
}

Form &Form::operator=(Form const &other)
{
    if (this != &other)
    {
        this->_signed = other._signed;
    }
    std::cout << RESET << "Form copy assignment operator called" << std::endl;
    return *this;
}

std::string Form::getName(void) const
{
    return this->_name;
}

bool Form::getSigned(void) const
{
    return this->_signed;
}

int Form::getGradeSign(void) const
{
    return this->_gradeSign;
}

int Form::getGradeExec(void) const
{
    return this->_gradeExec;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (this->_signed)
    {
        std::cout << YELLOW << "The form " << BLUE << this->_name << YELLOW;
        std::cout << " has already been signed !!" << std::endl << std::endl << RESET;
    }
    if (bureaucrat.getGrade() > this->_gradeSign)
        throw Form::GradeTooLowException();
    std::cout << GREEN << "The form " << BLUE << this->_name << GREEN;
    std::cout << " has been signed !!" << std::endl << std::endl << RESET;
    this->_signed = true;
}

std::ostream &operator<<(std::ostream &out, Form const &form)
{
    out << GRAY << "The form " << BLUE << form.getName() << GRAY << " is ";
    if (form.getSigned())
        out << GREEN << "signed" << GRAY;
    else
        out << RED << "not signed" << GRAY;
    out << " and require grade " << BLUE << form.getGradeSign();
    std::cout << GRAY << " to sign and grade ";
    out << BLUE << form.getGradeExec() << GRAY << " to execute." << std::endl << std::endl << RESET;
    return out;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade too high!!!";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade too low!!!";
}