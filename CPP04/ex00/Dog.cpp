#include "Dog.hpp"


Dog::Dog(): Animal()
{
	type = BLUE "Dog" RST;
	std::cout << getType() << " default constructor called" << std::endl;
}

Dog::Dog(const Dog& other): Animal(other)
{
	std::cout << getType() << " copy constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << getType() << " destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << getType() << " assigment operator called" << std::endl;
	Animal::operator=(other);
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "*Wouf Wouf*" << std::endl;
}