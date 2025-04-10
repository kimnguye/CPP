#include "Zombie.hpp"

int	main()
{
	Zombie	zouzou("zouzou");
	Zombie	*horde = zombieHorde(5, "cinq");

	for (int i = 0; i < 5; i++)
		horde[i].announce();
	delete []horde;
	return 0;
}