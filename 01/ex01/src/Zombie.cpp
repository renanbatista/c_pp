#include "../include/Zombie.hpp"

Zombie::Zombie( void )
{
	std::cout << GRAY << "Zombie created " << std::endl;
}

Zombie::~Zombie( void )
{
	std::cout << GRAY << _name << ": zombie destroyed" << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << GRAY << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName( std::string name )
{
	_name = name;
}