#pragma once

#include "ICharacter.hpp"

class ICharacter;

/*virtual destructor needed if the class has virtual functions*/
/*abstract class: pure virtual function in the class*/
class AMateria
{
protected:
	std::string type;
public:
	AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria& other);
	virtual ~AMateria();

	AMateria& operator=(const AMateria& other);

	std::string	const	&getType() const;
	
	virtual AMateria*	clone() const = 0;
	virtual void use (ICharacter &target);
};