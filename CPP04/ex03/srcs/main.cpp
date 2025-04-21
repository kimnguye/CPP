#include "../header/_Ex03.hpp"

int	mainCustom(void)
{
	printTitle("Other tests");
	printSeperate("Creation of 2 Characters: Kiki and");
	ICharacter	*kiki = new Character("Kiki");
	ICharacter	*mimi = new Character("Mimi");
	std::cout << std::endl;

	printSeperate("Creation of ressources");
	IMateriaSource	*source = new MateriaSource();
	Ice		*ice = new Ice();
	Cure	*cure = new Cure();
	source->learnMateria(ice);
	source->learnMateria(cure);
	std::cout << std::endl;

	printSeperate("Pick up the ressources");
	kiki->equip(source->createMateria("cure"));
	kiki->equip(source->createMateria("ice"));
	mimi->equip(source->createMateria("cure"));
	mimi->equip(source->createMateria("ice"));
	std::cout << std::endl;

	printSeperate("Use the ressources");
	kiki->use(1, *mimi);
	kiki->use(0, *kiki);
	mimi->use(1, *kiki);
	mimi->use(0, *mimi);
	std::cout << std::endl;

	printSeperate("Bad usage of use() - wrong index");
	kiki->use(3, *mimi);
	std::cout << std::endl;

	printSeperate("unequip()");
	AMateria *tmp0 = kiki->getMateria(1);
	kiki->unequip(1);
	AMateria *tmp1 = mimi->getMateria(0);
	mimi->unequip(0);
	std::cout << std::endl;

	printSeperate("unequip() a wrong index");
	kiki->unequip(1);
	mimi->unequip(5);
	std::cout << std::endl;

	delete (tmp0);
	delete (tmp1);
	delete (source);
	delete (mimi);
	delete (kiki);

	return (0);
}

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	mainCustom();
	return 0;
}