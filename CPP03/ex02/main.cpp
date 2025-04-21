#include "FragTrap.hpp"

int	main()
{
	std::cout << RED << "Creation of the players:" << RST << std::endl;
	ClapTrap trap2("Clap");
	ScavTrap trap("Scav");
	FragTrap trap1("Frag");
	trap1.set_attackDamage(1);

	std::cout<< std::endl;
	std::cout << RED << "Presentation of the players:" << RST << std::endl;
	trap1.print();
	trap2.print();
	trap.print();

	std::cout<< std::endl;
	std::cout << RED << "Actions:" << RST << std::endl;
	trap1.attack("Clap");
	trap2.takeDamage(trap1.get_attackDamage());

	std::cout<< std::endl;
	std::cout << RED << "Players state:" << RST << std::endl;
	trap1.print();
	trap2.print();
	trap.print();

	std::cout<< std::endl;
	std::cout << RED << "Copy of ScavTrap:" << RST << std::endl;
	ScavTrap copytrap;
	copytrap = trap;
	ScavTrap copytrap1(trap);
	copytrap.set_name("copy");
	copytrap1.set_name("copy1");

	std::cout<< std::endl;
	std::cout << RED << "Presentation of the copies:" << RST << std::endl;
	trap.print();
	copytrap.print();
	copytrap1.print();

	std::cout<< std::endl;
	std::cout << RED << "Actions:" << RST << std::endl;
	copytrap.attack("Scav");
	trap.takeDamage(copytrap.get_attackDamage());
	copytrap.guardGate();
	trap1.highFivesGuys();
	trap2.beRepaired(1);

	std::cout<< std::endl;
	std::cout << RED << "Players state:" << RST << std::endl;
	trap.print();
	copytrap.print();
	trap2.print();

	std::cout<< std::endl;
	std::cout << RED << "Destruction:" << RST << std::endl;

	return 0;
}
