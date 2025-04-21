#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

#define hp_max 200

class ClapTrap
{
private:
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
	void			attack(const std::string& target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	int				get_attackDamage() const;
	int				get_energyPoints() const;
	int				get_hitPoints() const;
	std::string		get_name() const;
	void			set_attackDamage(unsigned int amount);
	void			set_energyPoints(unsigned int amount);
	void			set_hitPoints(unsigned int amount);
	void			set_name(std::string name);
	void			print();
};

#endif
