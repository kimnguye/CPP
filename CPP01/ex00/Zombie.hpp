#ifndef ZOMBIE_CLASS_H
#define ZOMBIE_CLASS_H
#include <string>

class Zombie
{
	public:
		void		announce(void);
		Zombie( std::string name );
		~Zombie();
	private:
		std::string	name;
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif