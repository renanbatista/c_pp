#include <iomanip>  // Para std::fixed e std::setprecision
#include <iostream>

#include "PmergeMe.hpp"

int main(int argc, char* argv[])
{
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <number1> <number2> ... (only positive integers)"
                  << std::endl;
        return 1;
    }

    PmergeMe sorter;
    try {
        sorter.sort(argc, (const char**)argv);

        std::cout << "After: ";
        sorter.printData();
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
