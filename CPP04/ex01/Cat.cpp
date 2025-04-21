#include "Cat.hpp"

Cat::Cat(): Animal()
{
	type = YELLOW "Cat" RST;
	brain = new Brain();
	std::cout << getType() << " default constructor called" << std::endl;
}

Cat::Cat(const Cat& other): Animal(other)
{
	brain = new Brain(*other.brain);
	std::cout << getType() << " copy constructor called" << std::endl;
}

Cat::~Cat()
{
	delete brain;
	std::cout << getType() << " destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << getType() << " assigment operator called" << std::endl;
	Animal::operator=(other);
	brain = other.brain;
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "*Meow meow*" << std::endl;
}

Brain*	Cat::getBrain() const
{
	return (this->brain);
}