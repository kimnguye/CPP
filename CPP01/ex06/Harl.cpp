#include "Harl.hpp"

Harl::Harl(std::string filter)
{
	this->filter = check_args(filter);
}

Harl::~Harl()
{
}

void Harl::debug( void ){
	std::cout << "DEBUG: I love having extra bacon for my burger. I really do!\n";
}
void Harl::info( void ){
	std::cout << "INFO: I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n";
}
void Harl::warning( void ){
	std::cout << "WARNING: I deserve to have some extra bacon for free. I've been coming for years!\n";
}
void Harl::error( void ){
	std::cout << "ERROR: his is unacceptable! I want to speak to the manager now.\n";
}

/*pointers to member functions*/
void	Harl::complain(std::string level)
{
	void	(Harl::*ptr[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int		n;

    switch (this->filter) {
        case 3:
			n = 3;
        	break;
		case 2:
			n = 2;
        	break;
		case 1:
			n = 1;
        	break;
		case 0:
			n = 0;
    		break;
	}

	for (int i=n; i < 4; i++)
	{
		if (!level.compare(lvl[i]))
		{
			(this->*(ptr[i]))();
			return ;
		}
	}
}