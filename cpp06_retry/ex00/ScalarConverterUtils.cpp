#include "ScalarConverter.hpp"

std::string deleteSpace(const std::string &literal)
{
	int i = 0;
	while (literal[i] && literal[i] == ' ')
		i++;
	int	n = literal.length();
	while (literal[n] && literal[n] == ' ')
		n--;
	n-= i;
	return literal.substr(i, n);
}

bool	isInteger(const std::string &literal)
{
	int		i = atoi(literal.c_str());
	long	l = atol(literal.c_str());

	if (literal.find(".") != std::string::npos)
		return 0;
	if (i == 0 && literal.compare("0"))
		return 0;
	if (i == l)
		return 1;
	return 0;
}

bool	isFloat(const std::string &literal)
{
	if (literal.compare("-inff") == 0 ||
		literal.compare("+inff") == 0 ||
		literal.compare("inff") == 0 ||
		literal.compare("nanf") == 0)
		return 1;
	size_t	sep = literal.find(".");
	if (sep == std::string::npos)
		return 0;
	//printBlue("on a bien trouve un point");
	if (!isdigit(literal[1]) && literal[1] != '.')
		return 0;
	//printBlue("2e char est bien un digit ou un point");
	std::string integer = literal.substr(0, sep);
	std::string decimal = literal.substr(sep + 1);
	if (integer.find_first_not_of("0123456789-+") != std::string::npos)
		return 0;
	//printBlue("partie entiere ok");
	if (decimal.find_first_not_of("0123456789e+-") != (decimal.length() - 1))
		return 0;
	if (decimal[decimal.length() - 1] != 'f')
		return 0;
	//printBlue("partie decimale ok");
	return 1;
}

bool	isDouble(const std::string &literal)
{
	if (literal.compare("-inf") == 0 ||
		literal.compare("+inf") == 0 ||
		literal.compare("inf") == 0 ||
		literal.compare("nan") == 0)
		return 1;
	size_t	sep = literal.find(".");
	if (sep == std::string::npos)
		return 0;
	//printBlue("on a bien trouve un point");
	if (!isdigit(literal[1]) && literal[1] != '.')
		return 0;
	//printBlue("2e char est bien un digit ou un point");
	std::string integer = literal.substr(0, sep);
	std::string decimal = literal.substr(sep + 1);
	if (integer.find_first_not_of("0123456789-+") != std::string::npos)
		return 0;
	//printBlue("partie entiere ok");
	if (decimal.find_first_not_of("0123456789e+-") != std::string::npos)
		return 0;
	//printBlue("partie decimale ok");
	return 1;
}

bool	isChar(const std::string &literal)
{
	if (literal.length() != 1)
		return 0;
	char c = literal.c_str()[0];
	if (c >= 32 && c <= 126)
		return 1;
	return 0;
}

ScalarType	type(const std::string &literal)
{
	std::string str = deleteSpace(literal);
	if (isInteger(str))
		return INT;
	if (isChar(str))
		return CHAR;
	if (isDouble(str))
		return DOUBLE;
	if (isFloat(str))
		return FLOAT;
	return OTHER;
}

