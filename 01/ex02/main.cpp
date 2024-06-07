#include <iostream>

const std::string BLUE = "\033[34;1m";
const std::string GRAY = "\033[37;1m";
const std::string CYAN   = "\033[36;1m";

int	main( void )
{
	std::string	name = "HI THIS IS BRAIN";
	std::string* stringPTR = &name;
	std::string& stringREF = name;

	std::cout << CYAN << "---------------> HI THIS IS BRAIN TEST <---------------" << std::endl;

	std::cout << BLUE << "Memory address of the string variable:\t";
	std::cout << GRAY << &name << std::endl;

	std::cout << BLUE << "Memory address held by stringPTR:\t";
	std::cout << GRAY << stringPTR << std::endl;

	std::cout << BLUE << "Memory address held by stringREF:\t";
	std::cout << GRAY << &stringREF << std::endl;

	std::cout << GRAY;
	std::cout << "------------------------------------------------------" << std::endl;

	std::cout << BLUE << "The value of the string variable:\t";
	std::cout << GRAY << name << std::endl;

	std::cout << BLUE << "The value pointed to by stringPTR:\t";
	std::cout << GRAY << *stringPTR << std::endl;

	std::cout << BLUE << "The value pointed to by stringREF:\t";
	std::cout << GRAY << stringREF << std::endl;
	std::cout << GRAY;
	std::cout << "------------------------------------------------------" << std::endl;

	return (0);
}