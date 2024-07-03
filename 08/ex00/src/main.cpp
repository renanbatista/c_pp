#include "easyfind.hpp"

int main(void)
{
    std::cout << MAGENTA "-----> EASYFIND TESTS" << std::endl << std::endl;
    std::cout << CYAN "## VECTOR TEST" << std::endl;
    std::cout << "Add 2, 17, 5, 47, 9 in vector. Print all elements" << std::endl; /*  */
    std::cout << "Find element 17 in vector" << std::endl << YELLOW;
    try {
        std::vector<int> vec;

        vec.push_back(2);
        vec.push_back(17);
        vec.push_back(5);
        vec.push_back(47);
        vec.push_back(9);

        std::cout << RESET << "Vetor elements:" << std::endl;
        for (size_t i = 0; i < vec.size(); ++i)
            std::cout << vec[i] << " ";
        std::cout << YELLOW << std::endl << std::endl;

        std::cout << *easyfind(vec, 17) << " found" << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << RED "Error: Invalid param" RESET << std::endl;
    }

    std::cout << std::endl;
    std::cout << CYAN "## LIST TEST" << std::endl;
    std::cout << "Add 2, 17, 5, 47, 9 in list." << std::endl;
    std::cout << "Find element 47 in list" << std::endl;
    ;
    std::cout << YELLOW;

    try {
        std::list<int> lst;

        lst.push_back(2);
        lst.push_back(17);
        lst.push_back(5);
        lst.push_back(47);
        lst.push_back(9);

        std::cout << *easyfind(lst, 47) << " found" << std::endl;
        std::cout << std::endl << CYAN "Find element 22 in list" << std::endl;
        std::cout << *easyfind(lst, 22) << " found" << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << RED << "Error: Parameter not found!!!" << std::endl;
    }

    std::cout << MAGENTA "-----> END OF TEST" RESET << std::endl;

    return 0;
}