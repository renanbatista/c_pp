#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int
main(void)
{
    std::cout << MAGENTA << "----> BUREAUCRAT TEST" << RESET << std::endl << std::endl;
    std::cout << CYAN << "Start Try: " << RESET
              << "Creation of bureaucrat Mark with grade 2, upgrade x2" << std::endl;

    try
    {
        Bureaucrat b1("Mark", 2);
        std::cout << b1;
        b1.upGrade();
        std::cout << b1;
        b1.upGrade();
        std::cout << "High grade ?" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << RED << e.what() << RESET << std::endl << std::endl;
    }

    std::cout << RESET << "--------------------------------------------------------" << std::endl;
    std::cout << std::endl << MAGENTA << "----> SHRUBBERY TEST" << RESET << std::endl << std::endl;
    std::cout << CYAN << "Start Try: " << RESET
              << "Creation of ShrubberyCreationForm F1 and a bureaucrat Tomas with grade 138"
              << std::endl;
    std::cout << "Execute F1 - Assigning with Tomas - Execute F1 - Thomas upgrade - Execute F1"
              << std::endl;
    try
    {
        ShrubberyCreationForm form("F1");
        std::cout << form;

        Bureaucrat bureaucrat("Tomas", 138);
        std::cout << bureaucrat;

        bureaucrat.executeForm(form);

        bureaucrat.signForm(form);
        std::cout << form;

        bureaucrat.executeForm(form);

        bureaucrat.upGrade();
        std::cout << bureaucrat;

        bureaucrat.executeForm(form);
        
    }
    catch (std::exception& e)
    {
        std::cout << RED << std::endl;
        std::cout << e.what() << RESET << std::endl;
    }

    std::cout << RESET << "--------------------------------------------------------" << std::endl;
    std::cout << std::endl << MAGENTA << "----> ROBOTOMY TEST" << RESET << std::endl << std::endl;
    std::cout << CYAN << "Start Try: " << RESET
              << "Creation of RobotomyRequestForm F2 and a bureaucrat Ana with grade 46"
              << std::endl;
    std::cout << "Assigning with Ana - Execute F2 - Ana upgrade - Execute F2" << std::endl;

    try
    {
        RobotomyRequestForm form("F2");
        std::cout << form;

        Bureaucrat bureaucrat("Ana", 46);
        std::cout << bureaucrat;

        bureaucrat.signForm(form);
        std::cout << form;

        bureaucrat.executeForm(form);

        bureaucrat.upGrade();
        std::cout << bureaucrat;

        bureaucrat.executeForm(form);
        bureaucrat.executeForm(form);
        bureaucrat.executeForm(form);
    }
    catch (std::exception& e)
    {
        std::cout << RED << std::endl;
        std::cout << e.what() << RESET << std::endl;
    }

    std::cout << RESET << "--------------------------------------------------------" << std::endl;
    std::cout << std::endl
              << MAGENTA << "----> PRESIDENTIAL TEST" << RESET << std::endl
              << std::endl;
    std::cout << CYAN << "Start Try: " << RESET
              << "Creation of RobotomyRequestForm F3 and a bureaucrat Victoria with grade 26"
              << std::endl;
    std::cout << "Execute F3 - Assigning with Victoria - Victoria upgrade - Assigning with Victoria - Execute F3 - upgrade 20x - Execute F3 " << std::endl;

    try
    {
        Bureaucrat bureaucrat("Victoria", 26);
        std::cout << bureaucrat;

        PresidentialPardonForm form("F3");
        std::cout << form;

        bureaucrat.executeForm(form);
        bureaucrat.signForm(form);
        std::cout << form;

        bureaucrat.upGrade();
        std::cout << bureaucrat;

        bureaucrat.signForm(form);
        bureaucrat.executeForm(form);
        for (int i = 0; i < 20; i++)
            bureaucrat.upGrade();

        std::cout << bureaucrat;
        bureaucrat.executeForm(form);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << MAGENTA << "----> END OF TEST" << RESET << std::endl;

    // AForm form("F4", 1, 1);
    return 0;
}