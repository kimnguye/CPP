#include "Animal.hpp"

Animal::Animal(): type(GREEN "Animal" RST)
{
	std::cout << GREEN "Animal" RST " default constructor called" << std::endl;
}
Animal::Animal(const Animal& other)
{
	std::cout << GREEN "Animal" RST " copy constructor called" << std::endl;
	type = other.type;
}
Animal::~Animal()
{
	std::cout << GREEN "Animal" RST " destructor called" << std::endl;
}
Animal& Animal::operator=(const Animal& other)
{
	std::cout << GREEN "Animal" RST " assigment operator called" << std::endl;
	if (this != &other)
		type = other.type;
	return *this;
}

std::string Animal::getType() const
{
	return type;
}