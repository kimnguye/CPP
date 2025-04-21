#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>
#include "Colors.hpp"

#define hp_max 200

/*protected: accessible par les classes derivees mais pas par l'exterieur (comme private)*/
class ClapTrap
{
protected:
	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;

public:
	ClapTrap();
	~ClapTrap();
	ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);
	virtual void		attack(const std::string& target);
	void				takeDamage(unsigned int amount);
	void				beRepaired(unsigned int amount);
	unsigned int		get_attackDamage() const;
	unsigned int		get_energyPoints() const;
	unsigned int		get_hitPoints() const;
	std::string			get_name() const;
	void				set_attackDamage(unsigned int amount);
	void				set_energyPoints(unsigned int amount);
	void				set_hitPoints(unsigned int amount);
	void				set_name(std::string name);
	virtual void		print();
	virtual std::string	get_class();
};

#endif
