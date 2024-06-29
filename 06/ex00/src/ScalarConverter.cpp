#include "../include/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &src) {
    *this = src;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other) {
    if (this != &other)
    {
    }
    return *this;
}

void printChar(char c) {
    if (std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}

void printImpossible(const std::string &type) {
    std::cout << type << ": impossible" << std::endl;
}

void printFloat(float f, int decimalPrecision = 1) {
    if (f > std::numeric_limits<float>::max() || f < -std::numeric_limits<float>::max())
        printImpossible("float");
    else
        std::cout << "float: " << std::fixed << std::setprecision(decimalPrecision) << f << "f"
                  << std::endl;
}

void printDouble(double d, int decimalPrecision = 1) {
    if (d > std::numeric_limits<double>::max() || d < -std::numeric_limits<double>::max())
        printImpossible("double");
    else
        std::cout << "double: " << std::fixed << std::setprecision(decimalPrecision) << d
                  << std::endl;
}

void charConvert(const std::string &input) {
    char c = input[0];
    printChar(c);
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    printFloat(static_cast<float>(c));
    printDouble(static_cast<double>(c));
}

void intConvert(const std::string &input) {
    int n = atoi(input.c_str());
    if (errno == ERANGE)
    {
        printImpossible("int");
        return;
    }
    printChar(static_cast<char>(n));
    std::cout << "int: " << n << std::endl;
    printFloat(static_cast<float>(n));
    printDouble(static_cast<double>(n));
}

void floatConvert(const std::string &input, int decimalPrecision = 1) {
    float n = strtof(input.c_str(), NULL);
    if (errno == ERANGE)
    {
        printImpossible("float");
        return;
    }
    printChar(static_cast<char>(n));
    std::cout << "int: " << static_cast<int>(n) << std::endl;
    printFloat(n, decimalPrecision);
    printDouble(static_cast<double>(n), decimalPrecision);
}

void doubleConvert(const std::string &input, int decimalPrecision = 1) {
    double n = strtod(input.c_str(), NULL);
    if (errno == ERANGE)
    {
        printImpossible("double");
        return;
    }
    printChar(static_cast<char>(n));
    std::cout << "int: " << static_cast<int>(n) << std::endl;
    printFloat(static_cast<float>(n), decimalPrecision);
    printDouble(n, decimalPrecision);
}

void pseudoConvert(const std::string &input) {
    printImpossible("char");
    printImpossible("int");
    std::cout << "float: " << input << (input == "nan" ? "f" : "") << std::endl;
    std::cout << "double: " << input << std::endl;
}

bool isOthersLetters(const std::string &input) {
    for (std::string::const_iterator it = input.begin(); it != input.end(); ++it)
    {
        if (*it >= '0' && *it <= '9')
            continue;
        else if (*it != '.' && *it != 'f')
        {         
            std::cout << "Error: invalid parameter!!!" << std::endl;
            return true;
        }
    }
    return false;
}

void ScalarConverter::convert(std::string input) {
    size_t decimalPos = input.find('.');
    size_t floatPos = input.find('f');

    if (input == "-inf" || input == "+inf" || input == "nan" || input == "-inff" ||
        input == "+inff" || input == "nanf")
        pseudoConvert(input);
    else if (input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]))
        charConvert(input);
    else if (decimalPos != std::string::npos)
    {
        if (isOthersLetters(input))
            return;
            
        // calc decimal precision after point
        size_t decimalPrecision = input.length() - input.find('.') - 1;

        // test extra point
        if (input.find('.', decimalPos + 1) != std::string::npos)
        {
            std::cout << "Error: invalid parameter!!!" << std::endl;
            return;
        }

        // test extra f
        if (floatPos != std::string::npos)
        {
            if (input[input.length() - 1] != 'f' ||
                input.find('f', floatPos + 1) != std::string::npos)
            {
                std::cout << "Error: invalid parameter!!!" << std::endl;
                return;
            }
            floatConvert(input, decimalPrecision - 1);
        }
        else
            doubleConvert(input, decimalPrecision);
    }
    else if (std::isdigit(input[0]) || (input[0] == '-' && std::isdigit(input[1])))
        intConvert(input);
    else
        std::cout << "Error: invalid parameter!!!" << std::endl;
}