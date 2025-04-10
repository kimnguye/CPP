#include "Zombie.hpp"

Zombie::Zombie( std::string name )
{
	this->name = name;
	std::cout << this->name <<" is created\n";
}

Zombie::Zombie()
{
	
}

Zombie::~Zombie()
{
	std::cout << this->name <<" is destroyed\n";
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}