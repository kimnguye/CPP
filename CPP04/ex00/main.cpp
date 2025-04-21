#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main ()
{
	std::cout << MAGENTA << "Construction:" << RST << std::endl;
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	const WrongAnimal* wrong = new WrongAnimal();
	const WrongAnimal*  wrongcat = new WrongCat();

	std::cout<< std::endl;
	std::cout << MAGENTA << "Get Type and Sounds:" << RST << std::endl;
	std::cout << animal->getType() << ": ";
	animal->makeSound();
	std::cout << dog->getType() << ": ";
	dog->makeSound();
	std::cout << cat->getType() << ": ";
	cat->makeSound();
	std::cout << wrong->getType() << ": ";
	wrong->makeSound();
	std::cout << wrongcat->getType() << ": ";
	wrongcat->makeSound();

	std::cout<< std::endl;
	std::cout << MAGENTA << "Destruction" << RST << std::endl;
	delete animal;
	delete dog;
	delete cat;
	delete wrong;
	delete wrongcat;
	return 0;
}