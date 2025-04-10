#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon)
{
	this->name = name;
	this->weapon = &weapon;
}

HumanA::~HumanA()
{
}

void HumanA::attack() const
{
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

