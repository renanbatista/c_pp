#include "../include/ScalarConverter.hpp"

static void charConvert(std::string input) {
    char c = input[0];
    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f"
              << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c)
              << std::endl;
}

static void intConvert(std::string input) {
    int n = atoi(input.c_str());

    if (n < 0 || n > 127)
        std::cout << "char: impossible" << std::endl;
    else if (n < 32 || n == 127)
        std::cout << "char: non-displayable" << std::endl;
    else
        std::cout << "char: " << static_cast<char>(n) << std::endl;

    std::cout << "int: " << n << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(n) << "f"
              << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(n)
              << std::endl;
}

static void floatConvert(std::string input) {
    float n = strtof(input.c_str(), NULL);

    if (n < 0 || n > 127)
        std::cout << "char: impossible" << std::endl;
    else if (n < 32 || n == 127)
        std::cout << "char: non-displayable" << std::endl;
    else
        std::cout << "char: " << static_cast<char>(n) << std::endl;

    std::cout << "int: " << static_cast<int>(n) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << n << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(n)
              << std::endl;
}

static void doubleConvert(std::string input) {
    double n = strtod(input.c_str(), NULL);

    if (n < 0 || n > 127)
        std::cout << "char: impossible" << std::endl;
    else if (n < 32 || n == 127)
        std::cout << "char: non-displayable" << std::endl;
    else
        std::cout << "char: " << static_cast<char>(n) << std::endl;

    std::cout << "int: " << static_cast<int>(n) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(n) << "f"
              << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << n << std::endl;
}

static void pseudoConvert(std::string input) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << input << (input == "nan" ? "f" : "") << std::endl;
    std::cout << "double: " << input << std::endl;
}

void ScalarConverter::convert(std::string input) {
    if (input == "-inf" || input == "+inf" || input == "nan" || input == "-inff" ||
        input == "+inff" || input == "nanf")
    {
        pseudoConvert(input);
    }
    else if (input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]))
    {
        charConvert(input);
    }
    else if (input.find('.') != std::string::npos)
    {
        if (input[input.length() - 1] == 'f')
            floatConvert(input);
        else
            doubleConvert(input);
    }
    else if (std::isdigit(input[0]) || (input[0] == '-' && std::isdigit(input[1])))
    {
        intConvert(input);
    }
    else
    {
        std::cout << "Error: invalid parameter!!!" << std::endl;
    }
}
