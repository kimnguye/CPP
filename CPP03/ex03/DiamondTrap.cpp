#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap(), FragTrap(), ScavTrap()
{
	this->_name = "DiamondTrap";
	ClapTrap::_name = this->_name + "_clap_name";
	this->_hitPoints = FragTrap::defaultHitPoints;
	this->_energyPoints = ScavTrap::defaultEnergyPoints;
	this->_attackDamage = FragTrap::defaultAttackDamage;
	std::cout << get_class() << " default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name): ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap()
{
	this->_name = name;
	this->_hitPoints = FragTrap::get_hitPoints();
	this->_energyPoints = ScavTrap::defaultEnergyPoints;
	this->_attackDamage = FragTrap::defaultAttackDamage;
	std::cout << get_class() << " " << name << " constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << get_class() << " destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other): ClapTrap(other)
{
	std::cout <<  get_class() << " copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		ClapTrap::operator=(other);
	}
	std::cout << get_class() << " assignment operator called" << std::endl;
	return *this;
}

void 	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "I am " << this->_name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}

void	DiamondTrap::print()
{
	std::cout << get_class() << " " << _name << ":" << std::endl;
	std::cout << "hit points: " << get_hitPoints() << std::endl;
	std::cout << "energy points: " << get_energyPoints() << std::endl;
	std::cout << "attack damage: " << get_attackDamage() << std::endl;
}
std::string DiamondTrap::get_class()
{
    return (CYAN "DiamondTrap" RST);
}