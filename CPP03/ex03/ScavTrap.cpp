#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	set_hitPoints(100);
	set_energyPoints(50);
	set_attackDamage(20);
	_gateKeeperMode = false;
	std::cout << get_class() << " default constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << get_class() << " destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	_gateKeeperMode = other._gateKeeperMode;
	std::cout << get_class() << " copy constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	set_hitPoints(100);
	set_energyPoints(50);
	set_attackDamage(20);
	_gateKeeperMode = false;
	 std::cout << get_class() << " " << name << " constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		_gateKeeperMode = other._gateKeeperMode;
	}
	std::cout << get_class() << " assignment operator called" << std::endl;
	return *this;
}

void ScavTrap::attack(const std::string& target)
{
	if (get_hitPoints() <= 0)
	{
		std::cout << get_class() << get_name() << " is dead and cannot attack!" << std::endl;
		return;
	}
	if (get_energyPoints() <= 0)
	{
		std::cout << get_class() << get_name() << " has no energy points left!" << std::endl;
		return;
	}
	set_energyPoints(get_energyPoints() - 1);
	std::cout << get_class() << " " << get_name() << " attacks " << target << ", causing " << get_attackDamage() << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	if (get_hitPoints() <= 0)
	{
		std::cout << get_class() << " " << get_name() << " is dead and cannot guard the gate!" << std::endl;
		return;
	}
	_gateKeeperMode = true;
	std::cout << get_class() << " " << get_name() << " is now in Gate keeper mode!" << std::endl;
}

void	ScavTrap::print()
{
	std::cout << get_class() << " " << get_name() << ":" << std::endl;
	std::cout << "hit points: " << get_hitPoints() << std::endl;
	std::cout << "energy points: " << get_energyPoints() << std::endl;
	std::cout << "attack damage: " << get_attackDamage() << std::endl;
	std::cout << "gate keeper mode: " << _gateKeeperMode << std::endl;
}

std::string	ScavTrap::get_class()
{
    return (MAGENTA "ScavTrap" RST);
}
