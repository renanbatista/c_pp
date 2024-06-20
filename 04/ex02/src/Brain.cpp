#include "../include/Brain.hpp"

Brain::Brain( void )
{
	std::string ideas[4] = {"Coding a big program.", "Play a game.", "Sleep a lot.", "Eat a pizza."};
	for (int i = 0; i < 100; i++)
		this->ideas[i] = ideas[rand() % 4];

	std::cout << CYAN << "Brain was created!\n" << std::endl << RESET;
}

Brain::Brain( Brain const &copy )
{
	std::cout << GRAY << "A copy Brain was created!" << std::endl << RESET;
	*this = copy;
}

Brain::~Brain( void )
{
	std::cout << RED << "Brain was destroyed!" << std::endl << RESET;
}

Brain& Brain::operator=( Brain const &other )
{
	std::cout << GREEN << "Brain copied by assignment operator" << std::endl << RESET;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = other.getIdea(i);
	}
	return *this;
}

std::string Brain::getIdea( int n ) const
{
	return this->ideas[n];
}