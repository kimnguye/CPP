#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
private:
	Brain	*brain;
public:
	Cat();
	Cat(const Cat& other);
	~Cat();

	Cat& operator=(const Cat& other);

	void	makeSound() const;
	Brain	*getBrain() const;
};

