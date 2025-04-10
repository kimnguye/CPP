#include "Harl.hpp"


int	check_args(std::string str)
{
	for (int i=0; i < 4; i++)
		if (!str.compare(lvl[i]))
			return i;
	return -1;
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	std::string	filter = argv[1];
	if (check_args(filter) == -1)
	{
		std::cout << "Probably complaining about insignificant problems...\n";
		return 1;
	}
	Harl	harl(filter);
	std::cout << std::endl;
	std::cout << std::setfill('-') << std::setw(50);
	std::cout << "-\n" << std::endl;
	harl.complain("ERROR");
	harl.complain("DEBUG");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("DEBUG");
	harl.complain("WARNING");
	harl.complain("INFO");
	harl.complain("ERROR");
	harl.complain("ERROR");
	harl.complain("DEBUG");
	harl.complain("WARNING");
	harl.complain("INFO");
	harl.complain("ERROR");
	harl.complain("INFO");
	harl.complain("ERROR");
	harl.complain("Stupid.");
	harl.complain("Nothing to worry.");
	std::cout << std::endl;
	std::cout << std::setfill('-') << std::setw(50);
	std::cout << "-\n" << std::endl;
	return 0;
}