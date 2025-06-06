#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>
#include <iomanip>

const std::string	lvl[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

class Harl
{
private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
public:
	void complain( std::string level );
	Harl();
	~Harl();
};

#endif