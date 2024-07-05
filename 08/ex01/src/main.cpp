#include "Span.hpp"

void testsOfSubject(void)
{
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
}

int main(void)
{
    std::cout << MAGENTA "-----> SPAN TESTS" << std::endl;
    std::cout << CYAN "# SUBJECT TEST" RESET << std::endl << RESET;

    testsOfSubject();

    std::cout << std::endl << CYAN "# DEFAULT TESTS" << std::endl;
    std::cout << "Create a Span with 5 spaces" << std::endl;
    std::cout << "Add 100, 2, 41, 17, 12 to Span" << std::endl << RESET;
    {
        Span sp = Span(5);
        sp.addNumber(100);
        sp.addNumber(2);
        sp.addNumber(41);
        sp.addNumber(17);
        sp.addNumber(12);

        std::cout << GREEN "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl << RESET;
    }

    std::cout << CYAN "\n# 10001 NUMBERS TESTS" << std::endl;
    std::cout << "Create a Span with 10001 spaces" << std::endl;
    std::cout << "Add 10001 random numbers to Span using addMulti" << std::endl << RESET;
    {
        Span             sp = Span(10001);
        std::vector<int> vec;
        for (int i = 0; i < 10001; i++)
            sp.addNumber(i);
        sp.addMulti(vec.begin(), vec.end());

        std::cout << GREEN "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl << RESET;
    }

    std::cout << MAGENTA "\n-----> EXCEPTION TESTS" << std::endl;
    std::cout << CYAN "Create a Span with 5 spaces" << std::endl;
    std::cout << "Add 100, 2, 41, 17, 12 to Span" << std::endl;
    std::cout << "Add 1 to Span" << std::endl << RESET;
    {
        Span sp = Span(5);
        sp.addNumber(100);
        sp.addNumber(2);
        sp.addNumber(41);
        sp.addNumber(17);
        sp.addNumber(12);

        try {
            sp.addNumber(1);
        }
        catch (const std::exception& e) {
            std::cout << RED << e.what() << std::endl << std::endl << RESET;
        }
    }

    std::cout << CYAN "Create a Span with 5 spaces" << std::endl;
    std::cout << "Find shortest and longest span" << std::endl << RESET;
    {
        Span sp = Span(5);

        try {
            std::cout << GREEN "Shortest span: " << sp.shortestSpan() << std::endl;
            std::cout << "Longest span: " << sp.longestSpan() << std::endl;
        }
        catch (const std::exception& e) {
            std::cout << RED << e.what() << std::endl << std::endl << RESET;
        }
    }

    std::cout << CYAN "Create a Span with 5 spaces" << std::endl;
    std::cout << "Add only 1 number to Span" << std::endl;
    std::cout << "Try to find shortest and longest span" << std::endl << RESET;
    {
        Span sp = Span(5);

        sp.addNumber(10);
        try {
            std::cout << GREEN "Shortest span: " << sp.shortestSpan() << std::endl;
            std::cout << "Longest span: " << sp.longestSpan() << std::endl;
        }
        catch (const std::exception& e) {
            std::cout << RED << e.what() << std::endl << std::endl << RESET;
        }
    }

    std::cout << MAGENTA "-----> END OF TEST" RESET << std::endl;
    return 0;
}