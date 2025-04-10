#ifndef ZOMBIE_CLASS_H
#define ZOMBIE_CLASS_H
#include <string>
#include <iostream>

class Zombie
{
	public:
		void		announce(void);
		void		setName(std::string name);
		Zombie( std::string name );
		Zombie();
		~Zombie();
	private:
		std::string	name;
};

Zombie* zombieHorde( int N, std::string name );
#endif