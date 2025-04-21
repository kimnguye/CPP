#ifndef	FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ScavTrap.hpp"

/*ajout du mot cle virtual pour n'avoir qu'une seule instance de ClapTrap dans DiamondTrap*/
class FragTrap: virtual public ClapTrap
{

protected:
	static const unsigned int defaultHitPoints = 100;
	static const unsigned int defaultEnergyPoints = 100;
	static const unsigned int defaultAttackDamage = 30;
public:
	FragTrap();
	FragTrap(const FragTrap& other);
	FragTrap(const std::string name);
	~FragTrap();
	FragTrap& operator=(const FragTrap& other);

	void		attack(const std::string& target);
	void		highFivesGuys(void);
	void		print();
	std::string	get_class();
};

#endif
