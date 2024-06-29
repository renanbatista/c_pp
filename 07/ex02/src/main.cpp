#include "Array.hpp"

int main(void)
{
    std::cout << MAGENTA "-----> ARRAY TESTS" << std::endl;
    std::cout << CYAN "Declaration of intArray(5), assign 0-4 and [] use" RESET << std::endl;
    {
        Array<int> intArray(5);

        for (unsigned int i = 0; i < intArray.size(); i++)
            intArray[i] = static_cast<int>(i);
        for (unsigned int i = 0; i < intArray.size(); i++)
            std::cout << "[" << i << "]: " << intArray[i] << std::endl;
    }

    std::cout << CYAN "\nDeclaration of intArray(5), assign 0-4 and print" RESET << std::endl;
    {
        Array<int> intArray(5);

        for (unsigned int i = 0; i < intArray.size(); i++)
            intArray[i] = static_cast<int>(i);

        for (unsigned int i = 0; i < intArray.size(); i++)
            std::cout << intArray[i] << std::endl;
    }

    std::cout << CYAN "\nDeclaration of floatArray(5), assign 0-4 + 0.5 and print" RESET
              << std::endl;
    {
        Array<float> floatArray(5);

        for (unsigned int i = 0; i < floatArray.size(); i++)
            floatArray[i] = static_cast<float>(i + 0.5f);

        for (unsigned int i = 0; i < floatArray.size(); i++)
            std::cout << floatArray[i] << "f" << std::endl;
    }

    std::cout << CYAN "\nDeclaration of charArray(5), assign A-E and print" RESET << std::endl;
    {
        Array<char> charArray(5);

        for (unsigned int i = 0; i < charArray.size(); i++)
            charArray[i] = static_cast<char>(i + 65);

        for (unsigned int i = 0; i < charArray.size(); i++)
            std::cout << charArray[i] << std::endl;
    }

    std::cout << CYAN "\nConstructor Copy Test" << std::endl;
    std::cout << RESET "Declaration of intArray(5), assign 0-4" << std::endl;
    std::cout << "Call copy constructor, assign 42 to position 0 to copy" << std::endl;
    std::cout << "Print original and copy array: original - copy" RESET << std::endl;
    {
        Array<int> intArray(5);

        for (unsigned int i = 0; i < intArray.size(); i++)
            intArray[i] = static_cast<int>(i);

        Array<int> intArrayCopy(intArray);
        intArrayCopy[0] = 42;

        for (unsigned int i = 0; i < intArrayCopy.size(); i++)
            std::cout << intArray[i] << " - " << intArrayCopy[i] << std::endl;
    }

    std::cout << CYAN "\nAssignment Copy Test" << std::endl;
    std::cout << RESET "Declaration of charArray(5), assign A-E" << std::endl;
    std::cout << "Copy array using =, assign Z to position 0" << std::endl;
    std::cout << "Print original and copy array: original - copy" RESET << std::endl;
    {
        Array<char> charArray(5);

        for (unsigned int i = 0; i < charArray.size(); i++)
            charArray[i] = static_cast<char>(i + 65);

        Array<char> charArrayAssign = charArray;
        charArrayAssign[0] = 'Z';

        for (unsigned int i = 0; i < charArrayAssign.size(); i++)
            std::cout << charArray[i] << " - " << charArrayAssign[i] << std::endl;
    }

    std::cout << CYAN "\nArray Out Of Bounds Test" << std::endl;
    std::cout << RESET "Inside the upper limit" << std::endl;
    {
        try {
            Array<float> floatArray(5);
            floatArray[10] = 42.42;
        }
        catch (const std::exception& e) {
            std::cout << RED << e.what() << std::endl;
        }
    }

    std::cout << RESET "Outside the lower limit" << std::endl;
    {
        try {
            Array<float> floatArray(5);
            floatArray[-5] = 42.42;
        }
        catch (const std::exception& e) {
            std::cout << RED << e.what() << std::endl;
        }
    }

    std::cout << RESET "Empty array." << std::endl;

    {
        Array<int> emptyArray;
        try {
            emptyArray[0] = 42;
        }
        catch (const std::exception& e) {
            std::cout << RED << e.what() << std::endl << RESET;
        }
    }

    // std::cout << CYAN "Declaration of const intArray(5), assign 0-4 and [] use" RESET << std::endl;
    // {
    //         const Array<int> intArray(5);

    //         for (unsigned int i = 0; i < intArray.size(); i++)
    //             intArray[i] = static_cast<int>(i);
    //         for (unsigned int i = 0; i < intArray.size(); i++)
    //             std::cout << "[" << i << "]: " << intArray[i] << std::endl;
    // }

    std::cout << MAGENTA "-----> END OF TEST" << RESET << std::endl;

    return 0;
}