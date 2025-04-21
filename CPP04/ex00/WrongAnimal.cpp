#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type(RED "WrongAnimal" RST)
{
	std::cout << getType() << " default constructor called" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << getType() << " copy constructor called" << std::endl;
	type = other.type;
}
WrongAnimal::~WrongAnimal()
{
	std::cout << getType() << " destructor called" << std::endl;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << getType() << " assigment operator called" << std::endl;
	type = other.type;
	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << "*WrongAnimal sound*" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return type;
}