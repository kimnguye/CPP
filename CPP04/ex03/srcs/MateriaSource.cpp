#include "../header/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	idx = -1;
	//std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::~MateriaSource()
{
	//std::cout << "MateriaSource destructor called" << std::endl;
	for (int i=0; i <= idx; i++)
		if (_memory[i])
			delete _memory[i];
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	//std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i=0; i <= idx; i++)
		_memory[i] = other._memory[i];
	*this = other;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	//std::cout << "MateriaSource copy assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i=0; i <= idx; i++)
			_memory[i] = other._memory[i];
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* materia)
{
	if (idx < 3)
	{
		idx++;
		_memory[idx] = materia;
		std::cout << "Materia Source has learned " << materia->getType() << " in memory " << idx << "." << std::endl;
	}
	else
		std::cout << "Materia Source is full and cannot learn any new materia." << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i <= idx; i++)
		if (_memory[i]->getType().compare(type) == 0)
		{
			std::cout << "Materia Source has created " << type << "." << std::endl;
			return (_memory[i]->clone());
		}
	std::cout << "Materia Source cannot create " << type << "." << std::endl;
	return (0);
}
