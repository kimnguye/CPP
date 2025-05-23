#pragma once

#include <string>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <iomanip>
/*lib iomanip to use fixed (decimal point notation) + setprecision (nb of decimal)*/

#include "Layout.hpp"

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
	~ScalarConverter();
public:
	static void convert(const std::string &literal);
};

enum ScalarType
{
	OTHER = 0,
	CHAR = 1,
	INT = 2,
	FLOAT = 3,
	DOUBLE = 4
};

ScalarType	type(const std::string &literal);
