#include "../include/Weapon.hpp"

Weapon::Weapon( std::string type )
{
	this->_type = type;
}

Weapon::Weapon( void )
{
}

Weapon::~Weapon(void)
{
}

std::string const	&Weapon::getType(void) const
{
	return (this->_type);
}


void	Weapon::setType(std::string type)
{
	this->_type = type;
}