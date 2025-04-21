#include "../header/Ice.hpp"
#include "../header/Colors.hpp"

Ice::Ice():AMateria("ice")
{
	//std::cout << "Ice default constructor called" << std::endl;
}

Ice::~Ice()
{
	//std::cout << "Ice destructor called" << std::endl;
}

Ice::Ice(const Ice &other):AMateria(other)
{
	//std::cout << "Ice copy constructor called" << std::endl;
	*this = other;
}

Ice &Ice::operator=(const Ice &other)
{
	//std::cout << "Ice copy assignment operator called" << std::endl;
	if (this != &other)
		AMateria::operator=(other);
	return *this;
}


void Ice::use(ICharacter &target)
{
	std::cout << BLUE "* shoots an ice bolt at " << target.getName() << " *" RST << std::endl;
}

AMateria* Ice::clone() const
{
	return new Ice(*this);
}