#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
}
Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}


Brain& Brain::operator=(const Brain& other)
{
	std::cout << "Brain assigment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	}
	return *this;
}

void	Brain::setIdea(unsigned int i, std::string idea)
{
	if (i < 100)
		ideas[i] = idea;
	else
		std::cout << "Error: couldn't set idea\n";
}

std::string	Brain::getIdea(unsigned int i) const
{
	if (i < 100)
		return (ideas[i]);
	else
		return ("");
}