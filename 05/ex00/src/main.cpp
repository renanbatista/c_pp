#include "Bureaucrat.hpp"

int main(void)
{
    std::cout << MAGENTA << "----> BUREAUCRAT TEST" << RESET << std::endl << std::endl;
    std::cout << CYAN << "Start Try: "<< RESET << "Creation of bureaucrat Mark and grade 2, upgrade x2" << std::endl;
    try
    {
        Bureaucrat b1("Mark", 2);
        std::cout << b1;
        b1.upGrade();
        std::cout << b1;
        b1.upGrade();
        std::cout << "High grade ?" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << RED << e.what() << RESET << std::endl << std::endl;
    }

    std::cout << RESET << "--------------------------------------------------------" << std::endl;
    std::cout << CYAN << "Start Try: "<< RESET << "Creation of bureaucrat 'Default'" << std::endl;
    try
    {
        Bureaucrat d;
        std::cout << d << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << RED << e.what() << RESET << std::endl << std::endl;
    }

    std::cout << RESET << "--------------------------------------------------------" << std::endl;
    std::cout << CYAN << "Start Try: "<< RESET << "Creation of bureaucrat Brian and grade 149, downgrade x2" << std::endl;
    try
    {
        Bureaucrat b2("Brian", 149);
        std::cout << b2;
        b2.downGrade();
        std::cout << b2;
        b2.downGrade();
        std::cout << b2 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << RED << e.what() << RESET << std::endl << std::endl;
    }

    std::cout << RESET << "--------------------------------------------------------" << std::endl;
    std::cout << CYAN << "Start Try: "<< RESET << "Creation of bureaucrat Laura and grade 0" << std::endl;
    try
    {
        Bureaucrat b3("Laura", 0);
        std::cout << b3 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << RED << e.what() << RESET << std::endl << std::endl;
    }

    std::cout << RESET << "--------------------------------------------------------" << std::endl;
    std::cout << CYAN << "Start Try: "<< RESET << "Creation of bureaucrat Nicholas and grade 151" << std::endl;
    try
    {
        Bureaucrat b4("Nicholas", 151);
        std::cout << b4 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << RED << e.what() << RESET << std::endl << std::endl;
    }

    std::cout << MAGENTA << "----> END OF TEST" << RESET << std::endl;

    return 0;
}