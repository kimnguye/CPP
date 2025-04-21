#ifndef	SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"


/*ajout du mot cle virtual pour n'avoir qu'une seule instance de ClapTrap dans DiamondTrap*/
class ScavTrap : virtual public ClapTrap
{
protected:
	bool _gateKeeperMode;
	static const unsigned int defaultHitPoints = 100;
	static const unsigned int defaultEnergyPoints = 50;
	static const unsigned int defaultAttackDamage = 20;
public:
	ScavTrap();
	~ScavTrap();
	ScavTrap(const ScavTrap& other);
	ScavTrap(const std::string& name);
	ScavTrap& operator=(const ScavTrap& other);

	void		attack(const std::string& target);
	void		guardGate();
	void		print();
	std::string	get_class();
};

#endif
