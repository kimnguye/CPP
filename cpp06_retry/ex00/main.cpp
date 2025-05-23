#include "ScalarConverter.hpp"

int main_test()
{
	printTitle("TESTS: ");
	ScalarConverter::convert("0");
	ScalarConverter::convert("nan");
	ScalarConverter::convert("42.0f");
	ScalarConverter::convert("3.40282e+38f");
	ScalarConverter::convert("-5.40282e+38f");
	ScalarConverter::convert("+inff");
	ScalarConverter::convert("2147483647");
	ScalarConverter::convert("-2147483648");
	ScalarConverter::convert("a");
	ScalarConverter::convert("    +1");
	ScalarConverter::convert("    -1");
	ScalarConverter::convert("    -b");
	ScalarConverter::convert("42.0c");
	ScalarConverter::convert("2147483648");
	ScalarConverter::convert("-2147483649");
	return 0;
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	ScalarConverter::convert(argv[1]);
	//main_test();
	return 0;
}


