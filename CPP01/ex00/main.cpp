#include "Zombie.hpp"

int	main()
{
	Zombie	zombie("zouzou");
    Zombie *zombeur = newZombie("zeuzeur");

    randomChump("zaza");
	zombie.announce();
	zombeur->announce();
	delete (zombeur);
	return 0;
}