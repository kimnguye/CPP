#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
	private:
		std::string type;
	public:
		Weapon(std::string type);
		~Weapon();
		std::string const &getType() const;
		void setType(std::string const &type);
};

#endif
