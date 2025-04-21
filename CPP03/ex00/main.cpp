#include "ClapTrap.hpp"

int	main()
{
	ClapTrap trap1("un"), trap2("deux"), trap3("trois");
	ClapTrap trap;
	trap1.set_attackDamage(1);
	trap1.print();
	trap2.print();
	trap3.print();
	trap.print();
	trap1.attack("deux");
	trap2.takeDamage(trap1.get_attackDamage());
	trap1.print();
	trap2.print();
	trap3.print();
	trap.print();
	ClapTrap copytrap;
	copytrap = trap1;
	ClapTrap copytrap1(trap1);
	copytrap.print();
	copytrap1.print();
	trap2.beRepaired(1);
	trap2.print();
	return 0;
}