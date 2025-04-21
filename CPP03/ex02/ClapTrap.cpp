#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: _name("no name"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << get_class() << " default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << get_class() << " " << _name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
    std::cout << get_class() << " copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << get_class() << " copy assignment operator called" << std::endl;
    if (this != &other)
    {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << get_class() << " destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (_energyPoints > 0 && _hitPoints > 0)
    {
        std::cout << get_class() << " " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!\n";
        _energyPoints--;
    }
    else
        std::cout << get_class() << " " << _name << " can't attack! No energy or hit points left.\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints > 0)
    {
        if (_hitPoints < amount)
        {
			_hitPoints = 0;
			std::cout << get_class() << " " << _name << " takes " << amount
			<< " damage and died! ☠️" << std::endl;
		}
        else
            _hitPoints -= amount;
        std::cout << get_class() << " " << _name << " takes " << amount << " damage! Hit points: " << _hitPoints << std::endl;
    }
    else
        std::cout << get_class() << " " << _name << " is already dead!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints > 0)
    {
        _hitPoints += amount;
		_energyPoints--;
		if (_hitPoints > hp_max)
		{
			std::cout << get_class() << " " << _name << " repairs itself and recovers all his hit points! Current hit points: " << _hitPoints << std::endl;
			_hitPoints = hp_max;
		}
		else
        	std::cout << get_class() << " " << _name << " repairs itself for " << amount << " hit points! Current hit points: " << _hitPoints << std::endl;
    }
    else
        std::cout << get_class() << " " << _name << " can't repair! No energy left." << std::endl;
}

unsigned int ClapTrap::get_attackDamage() const
{
	return _attackDamage;
}

unsigned int ClapTrap::get_energyPoints() const
{
	return _energyPoints;
}

unsigned int ClapTrap::get_hitPoints() const
{
	return _hitPoints;
}

std::string		ClapTrap::get_name() const
{
	return _name;
}

void	ClapTrap::set_attackDamage(unsigned int amount)
{
	this->_attackDamage = amount;
}

void	ClapTrap::set_energyPoints(unsigned int amount)
{
	this->_energyPoints = amount;
}

void	ClapTrap::set_hitPoints(unsigned int amount)
{
	this->_hitPoints = amount;
}

void	ClapTrap::set_name(std::string name)
{
	this->_name = name;
}

void	ClapTrap::print()
{
	std::cout << get_class() << " " << get_name() << ":" << std::endl;
	std::cout << "hit points: " << get_hitPoints() << std::endl;
	std::cout << "energy points: " << get_energyPoints() << std::endl;
	std::cout << "attack damage: " << get_attackDamage() << std::endl;
}

std::string	ClapTrap::get_class()
{
    return (GREEN "ClapTrap" RST);
}

