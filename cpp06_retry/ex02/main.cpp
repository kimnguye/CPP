#include "Base.hpp"

int main()
{
	//initialise le generateur de nombres aleatoires
	srand(time(0));

	Base *p1 = Base::generate();
	Base *p2 = Base::generate();
	Base *p3 = Base::generate();
	Base *p4 = Base::generate();

	std::cout << "pointeurs: " << std::endl;
	std::cout << "p1: "; Base::identify(p1);
	std::cout << "p2: "; Base::identify(p2);
	std::cout << "p3: "; Base::identify(p3);
	std::cout << "p4: "; Base::identify(p4);

	std::cout << "references: " << std::endl;
	std::cout << "p1: "; Base::identify(*p1);
	std::cout << "p2: "; Base::identify(*p2);
	std::cout << "p3: "; Base::identify(*p3);
	std::cout << "p4: "; Base::identify(*p4);

	delete p1;
	delete p2;
	delete p3;
	delete p4;
	return 0;
}
