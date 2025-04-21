#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
	type = YELLOW "WrongCat" RST;
	std::cout << getType() << " default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other)
{
	std::cout << getType() << " copy constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << getType() << " destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << getType() << " assigment operator called" << std::endl;
	WrongAnimal::operator=(other);
	return *this;
}
