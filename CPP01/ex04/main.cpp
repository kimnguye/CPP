#include <iostream> /*input and output stream*/
#include <fstream> /*input and output file stream*/
#include <string> /*string*/

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "❌ : " << argv[0] << "<filename> <s1> <s2>" << std::endl;
		return (1);
	}

	std::string filename = argv[1];
	std::ifstream infile(filename.c_str());
	if (!infile.is_open())
	{
		std::cout << "❌ : could not open file" << std::endl;
		return (1);
	}

	std::string output_filename = filename + ".replace";
	std::ofstream outfile(output_filename.c_str());
	if (!outfile.is_open())
	{
		std::cout << "❌ : could not open file" << std::endl;
		return (1);
	}

	std::string line;
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::string bout1;
	std::string bout2;
	while (std::getline(infile, line))
	{
		size_t pos = line.find(s1);
		while (pos != std::string::npos)
		{
			bout1 = line.substr(0, pos);
			bout2 = line.substr(pos + s1.length(), line.length() - pos - s1.length());
			line = bout1 + s2 + bout2;
			pos = line.find(s1, pos + s2.length());
		}
		outfile << line << std::endl;
	}
	infile.close();
	outfile.close();
	return (0);
}
