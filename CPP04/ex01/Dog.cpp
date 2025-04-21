#include "Dog.hpp"


Dog::Dog(): Animal(), brain(new Brain())
{
	type = BLUE "Dog" RST;
	std::cout << getType() << " default constructor called" << std::endl;
}

Dog::Dog(const Dog& other): Animal(other), brain(new Brain(*other.brain))
{

	std::cout << getType() << " copy constructor called" << std::endl;
}

Dog::~Dog()
{
	delete brain;
	std::cout << getType() << " destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << getType() << " assigment operator called" << std::endl;
	Animal::operator=(other);
	brain = other.brain;
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "*Wouf Wouf*" << std::endl;
}

Brain*	Dog::getBrain() const
{
	return (this->brain);
}
