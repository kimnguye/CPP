#ifndef	SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

/*notion de classe derivee (enfant) et heritage
on peut heriter avec public, private ou protected:
-public: les membres publiques restent publiques
-protected: les membres publiques deviennent protected
-private: les membres publiques deviennent prives
notion de methodes virtuelles (virtual et override)*/
class ScavTrap : public ClapTrap
{
private:
	bool _gateKeeperMode;

public:
	ScavTrap();
	~ScavTrap();
	ScavTrap(const ScavTrap& other);
	ScavTrap(const std::string& name);
	ScavTrap& operator=(const ScavTrap& other);

	void		attack(const std::string& target);
	void		beRepaired(unsigned int amount);
	void		takeDamage(unsigned int amount);
	void		guardGate();
	void		print();
	std::string	get_class();
};

#endif
