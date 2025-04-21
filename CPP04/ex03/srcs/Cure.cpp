#include "../header/Cure.hpp"
#include "../header/Colors.hpp"

Cure::Cure(): AMateria("cure")
{
    //std::cout << "Cure default constructor called" << std::endl;
}

Cure::~Cure() 
{
    //std::cout << "Cure destructor called" << std::endl;
}

Cure::Cure(const Cure &other): AMateria(other)
{
	//std::cout << "Cure copy constructor called" << std::endl;
	*this = other;
}

Cure &Cure::operator=(const Cure &other)
{
   // std::cout << "Cure copy assignment operator called" << std::endl;
    if (this != &other)
		AMateria::operator=(other);
    return *this;
}

void Cure::use(ICharacter &target)
{
	std::cout << GREEN "* heals " << target.getName() << "'s wounds *" RST << std::endl;
}

AMateria* Cure::clone() const
{
	return new Cure(*this);
}