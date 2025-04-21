#ifndef	DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap
{
private:
	std::string	_name;
public:
	DiamondTrap();
	DiamondTrap(const DiamondTrap &other);
	DiamondTrap(const std::string name);
	~DiamondTrap();
	DiamondTrap &operator=(const DiamondTrap &other);

	void 		attack(const std::string &target);
	void		print();
	std::string	get_class();
	void		whoAmI();
};


#endif