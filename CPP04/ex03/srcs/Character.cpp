#include "../header/Character.hpp"

Character::Character(std::string name): _name(name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if (_inventory[i])
			delete _inventory[i];
}

Character::Character(const Character &other)
{
	this->_name = other._name;
	*this = other;
}

Character &Character::operator=(const Character &other)
{
	if (this != &other)
		this->_name = other._name;
	return *this;
}

std::string const& Character::getName() const
{
	return _name;
}

void Character::equip(AMateria* m)
{
	int	i = 0;
	while (i < 4 && _inventory[i])
		i++;
	if (i < 4)
	{
		if (m)
		{
			_inventory[i] = m;
			std::cout << _name << " added " << m->getType() << " to inventory "<< i << "." << std::endl;		
		}
	}
	else
		std::cout << _name << "'s inventory is full. Cannot equip item." << std::endl;		
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3 && _inventory[idx])
	{
		std::cout << _name << " removed " << _inventory[idx]->getType() << " from inventory " << idx << "."  << std::endl;		
		_inventory[idx] = NULL;
	}
	else
		std::cout << _name << "'s inventory " << idx << " is empty or does not exist." << std::endl;		
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx <= 3 && _inventory[idx])
	{
		std::cout << _name << " uses " << _inventory[idx]->getType() << ":" << std::endl;		
		_inventory[idx]->use(target);
	}
	else
		std::cout << _name << " tried to use item " << idx << ": Item not found." << std::endl;		
}

AMateria* Character::getMateria(int idx)
{
	return _inventory[idx];
}