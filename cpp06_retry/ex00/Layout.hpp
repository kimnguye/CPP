#pragma once

#include <string>
#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RST "\033[0m"
#define BOLD "\033[1m"

void	print(std::string str);
void	printBlue(std::string str);
void	printTitle(std::string str);
