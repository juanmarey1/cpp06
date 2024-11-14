#include "Base.hpp"

#include <cstdlib>
#include <ctime> 

Base	*generate(void)
{
	srand(static_cast<unsigned int>(time(0)));
	int	random  = rand() % 3;

	if (random == 0)
		return (new A());
	else if (random == 1)
		return (new B());
	else
		return (new C());
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p)) //dynamic_cast returns nullptr if the cast fails
		std::cout << "A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void	identify(Base &p)
{
	try {
	A	&a = dynamic_cast<A&>(p);
	(void)a;
	std::cout << "A" << std::endl;
	}
	catch (...) {}
	try {
	B	&b = dynamic_cast<B&>(p);
	(void)b;
	std::cout << "B" << std::endl;
	}
	catch (...) {}
	try {
	C	&c = dynamic_cast<C&>(p);
	(void)c;
	std::cout << "C" << std::endl;
	}
	catch (...) {}
}
