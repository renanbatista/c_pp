#include <list>

#include "MutantStack.hpp"

void testsOfSubject(void)
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();
    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator itb = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++itb;
    --itb;

    while (itb != ite) {
        std::cout << *itb << std::endl;
        ++itb;
    }

    std::stack<int> s(mstack);
}

int main(void)
{
    std::cout << MAGENTA "------> MUTANT STACK TESTS" << std::endl;
    std::cout << CYAN "# SUBJECT TEST" << YELLOW << std::endl;

    testsOfSubject();

    std::cout << CYAN "\n## OTHERS TESTS" << std::endl;
    std::cout << WHITE "Create a MutantStack of int" << std::endl;
    std::cout << "Add 1, 27, 3" << std::endl;
    std::cout << "Display top of stack" YELLOW << std::endl;

    MutantStack<int> mutant;

    mutant.push(1);
    mutant.push(27);
    mutant.push(3);

    std::cout << "top: " << mutant.top() << std::endl;
    std::cout << "size: " << mutant.size() << std::endl;

    std::cout << WHITE "Add 541, 1, 237, 0" << std::endl;
    std::cout << "Create iterator itb = begin" << std::endl;
    std::cout << "Create iterator ite = end" << std::endl;
    std::cout << "Use ++itb" << std::endl;
    std::cout << "Display the value of itb" YELLOW << std::endl;

    mutant.push(541);
    mutant.push(1);
    mutant.push(237);
    mutant.push(0);

    MutantStack<int>::iterator itb = mutant.begin();
    MutantStack<int>::iterator ite = mutant.end();

    ++itb;

    std::cout << "itb: " << *itb << std::endl << std::endl;

    std::cout << WHITE "Use --itb" << std::endl;
    std::cout << "Display the value of itb" YELLOW << std::endl;

    --itb;
    std::cout << "itb: " << *itb << std::endl << std::endl;

    std::cout << WHITE "Display the mutant stack using iterators" YELLOW << std::endl;

    std::cout << "stack: ";
    while (itb != ite) {
        ++itb;
        std::cout << *itb << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << WHITE "-----> Test list";
    std::cout << "Push 2, 17, 8" << std::endl;
    std::cout << "Display back os list" << std::endl;
    std::cout << YELLOW;

    std::list<int> list;
    list.push_back(2);
    list.push_back(17);
    list.push_back(8);
    std::cout << "back: " << list.back() << std::endl << std::endl;

    std::cout << WHITE "Create iterator itb2 = list.begin" << std::endl;
    std::cout << "Create iterator ite2 = list.end" << std::endl;
    std::cout << "++itb2" << std::endl;
    std::cout << "Display the value of itb2" YELLOW << std::endl;

    std::list<int>::iterator itb2 = list.begin();
    std::list<int>::iterator ite2 = list.end();

    ++itb2;

    std::cout << "itb2: " << *itb2 << std::endl << std::endl;

    std::cout << WHITE "Decrement 'itb2'" << std::endl;
    std::cout << "Display the value of itb2" YELLOW << std::endl;
    std::cout << YELLOW;

    --itb2;
    std::cout << "itb2: " << *itb2 << std::endl << std::endl;

    std::cout << WHITE "Display the list using iterators" YELLOW << std::endl;

    std::cout << "list: ";
    while (itb2 != ite2) {
        std::cout << *itb2 << " ";
        ++itb2;
    }
    std::cout << std::endl << std::endl;

    std::cout << MAGENTA "-----> END OF TEST ----------------------\n";
    std::cout << RESET << std::endl;
    return 0;
}