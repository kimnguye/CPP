#include <iostream>
#include <fstream>
#include <string>

int counter1 = 0;
int counter2 = 0;

/*
 set ARG "Lyrics"; set ARG1 "i"; set ARG2 "!"; ./ex04 $ARG $ARG1 $ARG2; ./tester $ARG $ARG1 $ARG2;
*/

/*Print the line with the str highlighted*/
void print_line1(std::string line, std::string str)
{
	/*find str in the line*/
	size_t pos = line.find(str);
	std::string line_c;
	std::string line_end;
	int i = 0;
	while (pos != std::string::npos)
	{
		counter1++;
		line_c += "\033[34m" + line.substr(i, pos - i) + "\033[0m" + "\033[41m" + str + "\033[0m";
		line_end = line.substr(pos + str.length());
		i = pos + str.length();
		pos = line.find(str, pos + str.length());
	}
	line_c += "\033[34m" + line_end + "\033[0m";
	std::cout << line_c << std::endl;
}

void print_line2(std::string line, std::string str)
{
	/*find str in the line*/
	size_t pos = line.find(str);
	std::string line_c;
	std::string line_end;
	int i = 0;
	while (pos != std::string::npos)
	{
		counter2++;
		line_c += "\033[34m" + line.substr(i, pos - i) + "\033[0m" + "\033[42m" + str + "\033[0m";
		line_end = line.substr(pos + str.length());
		i = pos + str.length();
		pos = line.find(str, pos + str.length());
	}
	line_c += "\033[34m" + line_end + "\033[0m";
	std::cout << line_c << std::endl;
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Expected: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	std::string filename1 = argv[1];
	std::string filename2 = filename1 + ".replace";

	std::ifstream infile1(filename1.c_str());
	std::ifstream infile2(filename2.c_str());
	if (!infile1.is_open() || !infile2.is_open())
	{
		std::cout << "❌ : could not open file" << std::endl;
		return (1);
	}

	/*Compare the two files*/
	std::string line1;
	std::string line2;
	bool diff = false;
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	while (std::getline(infile1, line1))
	{
		std::getline(infile2, line2);
		if (line1 != line2)
		{
			diff = true;
			print_line1(line1, s1);
			print_line2(line2, s2);
		}
	}
	if (!diff)
		std::cout << "Files are identical" << std::endl;

	/*Check if file2 still contains s1*/
	std::string line;
	while (std::getline(infile2, line))
	{
		if (line.find(s1) != std::string::npos)
		{
			std::cout << "❌ " << filename2 << "\033[34m still contains \033[0m" << s1 << std::endl;
			return (1);
		}
	}
	std::cout << std::endl;
	std::cout << "✅ " << filename2 << "\033[34m does not contain any \033[0m" << s1 << std::endl;
	std::cout << "✅ " << s1 << "\033[34m has been replaced with \033[0m" << s2 << std::endl;
	if (counter1 == counter2)
	{
		std::cout << "✅ " << counter1 << "\033[34m occurrences of \033[0m" << s1 <<  "\033[34m in \033[0m" << filename1 << std::endl;
		std::cout << "✅ " << counter2 << "\033[34m occurrences of \033[0m" << s2 << "\033[34m in \033[0m" << filename2 << std::endl;
	}
	else
	{
		std::cout << "❌ " << counter1 << "\033[34m occurrences of \033[0m" << s1 <<  "\033[34m in \033[0m" << filename1 << std::endl;
		std::cout << "❌ " << counter2 << "\033[34m occurrences of \033[0m" << s2 << "\033[34m in \033[0m" << filename2 << std::endl;
	}
	return (0);
}
