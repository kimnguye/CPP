#include "Layout.hpp"

void	print(std::string str)
{
	std::cout << str << std::endl;
}

void	printBlue(std::string str)
{
	std::cout << BLUE << str << RST << std::endl;
}

void	printTitle(std::string str)
{
	std::cout << std::endl;
	std::cout << BLUE << BOLD << str << RST << std::endl;
	std::cout << std::endl;
}
