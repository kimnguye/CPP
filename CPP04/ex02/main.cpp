#include "Dog.hpp"
#include "Cat.hpp"

int main ()
{
	std::cout << MAGENTA << "Construction:" << RST << std::endl;
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout<< std::endl;
	std::cout << MAGENTA << "Sounds:" << RST << std::endl;
	std::cout << dog->getType() << ": ";
	dog->makeSound();
	std::cout << cat->getType() << ": ";
	cat->makeSound();

	std::cout<< std::endl;
	std::cout << MAGENTA << "Destruction" << RST << std::endl;
	delete dog;
	delete cat;

	std::cout<< std::endl;
	std::cout << MAGENTA << "Tab:" << RST << std::endl;
	const Animal *(tab[10]);

	for (int i=0; i < 5; i++)
		tab[i] = new Dog();
	for (int i=5; i < 10; i++)
		tab[i] = new Cat();

	std::cout<< std::endl;
	std::cout << MAGENTA << "Tab Sounds:" << RST << std::endl;

	for (int i=0; i < 10; i++)
	{
		std::cout << tab[i]->getType() << ": ";
		tab[i]->makeSound();
	}
	
	std::cout<< std::endl;
	std::cout << MAGENTA << "Destruction" << RST << std::endl;
	for (int i=0; i < 10; i++)
		delete tab[i];
	
	std::cout<< std::endl;
	std::cout << MAGENTA << "Deep copies:" << RST << std::endl;

	Dog	*doberman = new Dog();
	Cat	*kitty = new Cat();

	kitty->getBrain()->setIdea(0, "mouse");
	doberman->getBrain()->setIdea(0, "eat");
	doberman->getBrain()->setIdea(1, "play");
	
	Dog	*doberman_bis = new Dog(*doberman);
	Cat	*kitty_bis = new Cat(*kitty);

	std::cout<< std::endl;
	std::cout << MAGENTA << "Delete kitty:" << RST << std::endl;
	delete kitty;
	std::cout<< std::endl;
	std::cout << MAGENTA << "Print kitty_bis Ideas:" << RST << std::endl;
	std::cout << "british_bis idea[0]: " << kitty_bis->getBrain()->getIdea(0) << std::endl;

	std::cout<< std::endl;
	std::cout << MAGENTA << "doberman_bis has differents ideas than doberman." << RST << std::endl;
	doberman_bis->getBrain()->setIdea(0, "sleep");
	doberman_bis->getBrain()->setIdea(1, "sleep");

	std::cout<< std::endl;
	std::cout << MAGENTA << "Print dogs Ideas:" << RST << std::endl;
	for (int i=0; i < 2; i++)
	{
		std::cout << "doberman idea[" << i << "]: " << doberman->getBrain()->getIdea(i) << std::endl;
		std::cout << "doberman_bis idea[" << i << "]: " << doberman_bis->getBrain()->getIdea(i) << std::endl;
	}
	
	std::cout<< std::endl;
	std::cout << MAGENTA << "Destruction" << RST << std::endl;
	delete doberman;
	delete doberman_bis;
	delete kitty_bis;
	return 0;
}