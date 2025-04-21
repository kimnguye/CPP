#pragma once

#include <string.h>
#include <iostream>
#include "Colors.hpp"

/*virtual destructor needed if the class has virtual functions*/
/*abstract class: pure virtual function in the class*/
class Animal
{
protected:
	std::string type;
public:
	Animal();
	Animal(const Animal& other);
	virtual ~Animal();

	Animal& operator=(const Animal& other);

	virtual void	makeSound() const = 0;
	std::string		getType() const;
};