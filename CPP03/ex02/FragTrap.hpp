#ifndef	FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ScavTrap.hpp"

class FragTrap: public ClapTrap
{
public:
	FragTrap();
	~FragTrap();
	FragTrap(const FragTrap& other);
	FragTrap(const std::string name);
	FragTrap& operator=(const FragTrap& other);

	void		attack(const std::string& target);
	void		beRepaired(unsigned int amount);
	void		takeDamage(unsigned int amount);
	void		highFivesGuys(void);
	void		print();
	std::string	get_class();
};

#endif
