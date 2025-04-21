#pragma once

#include <string.h>
#include <iostream>

class Brain
{
private:
	std::string ideas[100];
public:
	Brain();
	Brain(const Brain&);
	~Brain();
	Brain& operator=(const Brain&);

	void		setIdea(unsigned int i, std::string idea);
	std::string	getIdea(unsigned int i) const;
};


