#include "../header/AMateria.hpp"

AMateria::AMateria(): type("")
{
	//std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type)
{
	this->type = type;
	//std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other)
{
	this->type = other.type;
    //std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria::~AMateria()
{
   //std::cout << "AMateria destructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other)
{
    //std::cout << "AMateria copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
	}
	return *this;
}

std::string const &AMateria::getType() const
{
	return type;
}

void AMateria::use (ICharacter &target)
{
	std::cout << target.getName() << ": try to use a Materia."<< std::endl;	
}