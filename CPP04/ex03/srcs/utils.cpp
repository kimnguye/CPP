#include <iostream>
#include <iomanip>
#include <string>
#include "../header/Colors.hpp"

void	printTitle(std::string str)
{
	const int	width = 30;
	int			padding = (width - str.length()) / 2;
	std::cout << std::endl;
	std::cout << std::setfill('-') << std::setw(width) <<  "-" << std::endl;
	std::cout << std::endl;
	std::cout << std::string(padding, ' ') << str << std::endl;
	std::cout << std::endl;
	std::cout << std::setfill('-') << std::setw(width) <<  "-" << std::endl;
	std::cout << std::endl;

}

void	printSeperate(std::string str)
{
	std::cout << YELLOW << str << RST << std::endl;
}
void	print(std::string str)
{
	std::cout << str << std::endl;
}