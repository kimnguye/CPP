#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		int			idx;
		AMateria*	_memory[4]; 
	public:
		MateriaSource();                  
		~MateriaSource();                           
		MateriaSource(const MateriaSource &other);  
		MateriaSource &operator=(const MateriaSource &other);

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const &type);
};

#endif
