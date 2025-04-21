#include "Cat.hpp"

Cat::Cat(): Animal()
{
	type = YELLOW "Cat" RST;
	std::cout << getType() << " default constructor called" << std::endl;
}

Cat::Cat(const Cat& other): Animal(other)
{
	std::cout << getType() << " copy constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << getType() << " destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << getType() << " assigment operator called" << std::endl;
	Animal::operator=(other);
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "*Meow meow*" << std::endl;
}