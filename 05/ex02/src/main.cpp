#include "Bureaucrat.hpp"

int main(void)
{
    std::cout << MAGENTA << "----> FORM TEST" << RESET << std::endl << std::endl;
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
    catch (std::exception &e)
    {
        std::cout << RED << e.what() << RESET << std::endl << std::endl;
    }

    std::cout << RESET << "--------------------------------------------------------" << std::endl;
    std::cout << CYAN << "Start Try: " << RESET
              << "Creation of bureaucrat Brian with grade 149, downgrade x2" << std::endl;
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
    std::cout << CYAN << "Start Try: " << RESET << "Creation of bureaucrat Laura and grade 0"
              << std::endl;
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
    std::cout << CYAN << "Start Try: " << RESET << "Creation of bureaucrat Nicholas and grade 151"
              << std::endl;
    try
    {
        Bureaucrat b4("Nicholas", 151);
        std::cout << b4 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << RED << e.what() << RESET << std::endl << std::endl;
    }

    std::cout << RESET << "--------------------------------------------------------" << std::endl;
    std::cout << CYAN << "Start Try: " << RESET << "Creation of a form Default" << std::endl;
    try
    {
        Form f0;
        std::cout << f0;
    }
    catch (std::exception &e)
    {
        std::cout << RED << e.what() << RESET << std::endl << std::endl;
    }

    std::cout << RESET << "--------------------------------------------------------" << std::endl;
    std::cout << CYAN << "Start Try: " << RESET
              << "Creation of a form f1 with grade 151 and exec grade 2" << std::endl;
    try
    {
        Form f1("f1", 151, 2);
        std::cout << f1;
    }
    catch (std::exception &e)
    {
        std::cout << RED << e.what() << RESET << std::endl << std::endl;
    }

    std::cout << RESET << "--------------------------------------------------------" << std::endl;
    std::cout << CYAN << "Start Try: " << RESET
              << "Creation of a form f2 with grade 25 and exec grade 151" << std::endl;
    try
    {
        Form f2("f2", 25, 151);
        std::cout << f2;
    }
    catch (std::exception &e)
    {
        std::cout << RED << e.what() << RESET << std::endl << std::endl;
    }

    std::cout << RESET << "--------------------------------------------------------" << std::endl;
    std::cout << CYAN << "Start Try: " << RESET
              << "Creation of a form F3 with grade 0 and exec grade 0" << std::endl;
    try
    {
        Form f3("F3", 0, 0);
        std::cout << f3;
    }
    catch (std::exception &e)
    {
        std::cout << RED << e.what() << RESET << std::endl << std::endl;
    }

    std::cout << RESET << "--------------------------------------------------------" << std::endl;
    std::cout << CYAN << "Start Try: " << RESET
              << "Creation of a form F4 with grade 2 and exec grade 2" << std::endl;
    std::cout << "Creation of a Bureaucrat Oscar with grade 3" << std::endl;
    std::cout << "Oscar signForm F4, upGrade and signForm F4" << std::endl;
    try
    {
        Form f4("F4", 2, 2);
        std::cout << f4;
        Bureaucrat b5("Oscar", 3);
        std::cout << b5;
        b5.signForm(f4);
        std::cout << f4;
        b5.upGrade();
        std::cout << b5;
        b5.signForm(f4);
        std::cout << f4;
    }
    catch (std::exception &e)
    {
        std::cout << RED << e.what() << RESET << std::endl << std::endl;
    }

    std::cout << RESET << "--------------------------------------------------------" << std::endl;
    std::cout << CYAN << "Start Try: " << RESET
              << "Creation of a form F5 with grade 100 and exec grade 100" << std::endl;
    std::cout << "Creation of a Bureaucrat David with grade 90" << std::endl;
    std::cout << "David signForm F5, downGrade and signForm F5" << std::endl;
    try
    {
        Form f4("F5", 100, 100);
        std::cout << f4;
        Bureaucrat b5("David", 90);
        std::cout << b5;
        b5.signForm(f4);
        std::cout << f4;
        b5.downGrade();
        std::cout << b5;
        b5.signForm(f4);
        std::cout << f4;
    }
    catch (std::exception &e)
    {
        std::cout << RED << e.what() << RESET << std::endl << std::endl;
    }

    std::cout << MAGENTA << "----> END OF TEST" << RESET << std::endl;

    return 0;
}