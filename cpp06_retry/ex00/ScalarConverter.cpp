#include "ScalarConverter.hpp"

/*coplien*/

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {(void) other;}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void) other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

/*print*/
/*lib iomanip to use fixed (decimal point notation) + setprecision (nb of decimal)*/

void		printChar(const char &c, const double &value)
{
	if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max() || value != value)
		std::cout << "char: impossible" << std::endl;
	else if (c < 32 || c > 126)
		std::cout << "char:  Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
}

void		printInt(const int &i, const double &value)
{
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max() || value != value)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
}

/*choix de laisser le double pouvoir devenir infini*/
void		printDouble(const double &d)
{
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

/*choix de laisser le float pouvoir devenir infini*/
void		printFloat(const float &f)
{
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

/*methode*/

/*j'utilise static_cast pour caster des types de bases
attention, il peut y avoir des imprecisions du int vers float*/
void ScalarConverter::convert(const std::string &literal)
{
	char	c;
	int		i;
	float	f;
	double	d;
	double value = strtod(literal.c_str(), NULL);

	switch (type(literal))
	{
		case INT:
			//std::cout << "✅ " << literal << " is an integer!" << std::endl;
			i = atoi(literal.c_str());
			c = static_cast<char>(i);
			f = static_cast<float>(i);
			d = static_cast<double>(i);
			break;
		case DOUBLE:
			//std::cout << "✅ " << literal << " is a double!" << std::endl;
			d = strtod(literal.c_str(), NULL);
			i = static_cast<int>(d);
			c = static_cast<char>(d);
			f = static_cast<float>(d);
			break;
		case FLOAT:
			//std::cout << "✅ " << literal << " is a float!" << std::endl;
			f = strtof(literal.c_str(), NULL);
			d = static_cast<double>(f);
			i = static_cast<int>(f);
			c = static_cast<char>(f);
			break;
		case CHAR:
			//std::cout << "✅ '" << literal << "' is a character!" << std::endl;
			c = literal.c_str()[0];
			i = static_cast<int>(c);
			f = static_cast<float>(c);
			d = static_cast<double>(c);
			break;
		default:
			//std::cout << "❌ " << literal << " is not a scalar type!" << std::endl;
		return ;
	}
	printChar(c, value);
	printInt(i, value);
	printFloat(f);
	printDouble(d);
}
