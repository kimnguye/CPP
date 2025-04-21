#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string.h>
#include "ICharacter.hpp"

class Character: public ICharacter
{
	private:
	std::string _name;
	AMateria*	_inventory[4];

	public:
		Character(std::string name);
		~Character();
		Character(const Character &other);
		Character &operator=(const Character &other);

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		AMateria* getMateria(int idx);
};

#endif
