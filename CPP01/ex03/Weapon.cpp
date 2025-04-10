#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::~Weapon()
{
}

std::string const &Weapon::getType() const
{
	return (type);
}

void Weapon::setType(std::string const &type)
{
	this->type = type;
}
