#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base* Base::generate(void)
{
	int random = rand() % 3;

	if (random == 0)
		return new A();
	if (random == 1)
		return new B();
	return new C();
}

/*dynamic cast retourne 0 si le cast est impossible*/

// pointeur
void Base::identify(Base *p)
{
	if (p == NULL)
		return;
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

// reference
void Base::identify(Base &p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (std::exception& e)
	{
		try
		{
			B& b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "B" << std::endl;
		}
		catch (std::exception& e)
		{
			try
			{
				C& c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "C" << std::endl;
			}
			catch (std::exception& e)
			{
				std::cout << "Unknown type" << std::endl;
			}
		}
	}
}
