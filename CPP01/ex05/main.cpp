#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	Harl	harl;
	std::cout << std::endl;
	harl.complain(argv[1]);
	std::cout << std::endl;
	std::cout << std::setfill('-') << std::setw(50);
	std::cout << "-\n" << std::endl;
	harl.complain("Nothing to worry.");
	harl.complain("ERROR");
	harl.complain("DEBUG");
	harl.complain("WARNING");
	harl.complain("INFO");
	harl.complain("Stupid.");
	harl.complain("ERROR");
	return 0;
}