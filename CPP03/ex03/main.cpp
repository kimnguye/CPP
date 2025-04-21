#include "DiamondTrap.hpp"

int	main()
{
	std::cout << RED << "Creation of the players:" << RST << std::endl;
	DiamondTrap diam1("Ring");
	DiamondTrap diam2;
	ScavTrap scav("Scav");
	FragTrap frag("Frag");

	std::cout<< std::endl;
	std::cout << RED << "Presentation of the players:" << RST << std::endl;
	diam1.print();
	diam2.print();
	scav.print();
	frag.print();

	std::cout<< std::endl;
	std::cout << RED << "Actions:" << RST << std::endl;
	frag.attack("diamonds");
	diam1.takeDamage(frag.get_attackDamage());
	diam2.takeDamage(frag.get_attackDamage());

	std::cout<< std::endl;
	std::cout << RED << "Players state:" << RST << std::endl;
	frag.print();
	diam1.print();
	diam2.print();
	scav.print();

	std::cout<< std::endl;
	std::cout << RED << "Copy of ScavTrap:" << RST << std::endl;
	DiamondTrap copytrap;
	copytrap = diam1;
	ScavTrap copytrap1(scav);
	copytrap.set_name("copy");

	std::cout<< std::endl;
	std::cout << RED << "Presentation of the copies:" << RST << std::endl;
	scav.print();
	copytrap.print();

	std::cout<< std::endl;
	std::cout << RED << "Actions:" << RST << std::endl;
	copytrap.attack("Scav");
	scav.takeDamage(copytrap.get_attackDamage());
	copytrap.guardGate();
	frag.highFivesGuys();
	diam1.beRepaired(20);
	diam2.beRepaired(10);

	std::cout<< std::endl;
	std::cout << RED << "Players state:" << RST << std::endl;
	scav.print();
	copytrap.print();
	diam1.print();
	diam2.print();

	std::cout<< std::endl;
	std::cout << RED << "Who Am I:" << RST << std::endl;
	diam1.whoAmI();
	diam2.whoAmI();

	std::cout<< std::endl;
	std::cout << RED << "Destruction:" << RST << std::endl;

	return 0;
}
