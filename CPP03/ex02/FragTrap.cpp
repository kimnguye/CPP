#include "FragTrap.hpp"

FragTrap::FragTrap():ClapTrap()
{
	set_hitPoints(100);
	set_energyPoints(100);
	set_attackDamage(30);
	std::cout << get_class() << " default constructor called" << std::endl;

}
FragTrap::~FragTrap()
{
	std::cout << get_class() << " destructor called" << std::endl;

}
FragTrap::FragTrap(const FragTrap& other): ClapTrap(other)
{
	std::cout <<  get_class() << " copy constructor called" << std::endl;
}
FragTrap::FragTrap(const std::string name):ClapTrap(name)
{
	set_hitPoints(100);
	set_energyPoints(100);
	set_attackDamage(30);
	std::cout << get_class() << " " << name << " constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	std::cout << get_class() << " assignment operator called" << std::endl;
	return *this;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << get_class() << " requests a positive high-five!" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
    if (get_hitPoints() > 0)
    {
        if (get_hitPoints() < amount)
        {
			set_hitPoints(0);
			std::cout << get_class() << " " << get_name() << " takes " << amount
			<< " damage and died! ☠️" << std::endl;
		}
        else
            set_hitPoints(get_hitPoints() - amount);
        std::cout << get_class() << " " << get_name() << " takes " << amount << " damage! Hit points: " << get_hitPoints() << std::endl;
    }
    else
        std::cout << get_class() << " " << get_name() << " is already dead!" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
    if (get_energyPoints() > 0)
    {
        set_hitPoints(get_hitPoints() + amount);
		set_energyPoints(get_energyPoints() - 1);
		if (get_hitPoints() > hp_max)
		{
			std::cout << get_class() << " " << get_name() << " repairs itself and recovers all his hit points! Current hit points: " << get_hitPoints() << std::endl;
			set_hitPoints(hp_max);
		}
		else
        	std::cout << get_class() << " " << get_name() << " repairs itself for " << amount << " hit points! Current hit points: " << get_hitPoints() << std::endl;
    }
    else
        std::cout << get_class() << " " << get_name() << " can't repair! No energy left." << std::endl;
}

void	FragTrap::attack(const std::string& target)
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
	std::cout << get_class() << get_name() << " attacks " << target << ", causing " << get_attackDamage() << " points of damage!" << std::endl;
}

void	FragTrap::print()
{
	std::cout << get_class() << " " << get_name() << ":" << std::endl;
	std::cout << "hit points: " << get_hitPoints() << std::endl;
	std::cout << "energy points: " << get_energyPoints() << std::endl;
	std::cout << "attack damage: " << get_attackDamage() << std::endl;
}

std::string	FragTrap::get_class()
{
    return (YELLOW "FragTrap" RST);
}
