#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice &other) : AMateria() {
	*this = other;
}

Ice &Ice::operator=(const Ice &rhs)
{
	(void) rhs;
	_type = "ice";
	return (*this);
}

Ice::~Ice() {}

AMateria *Ice::clone() const {
	AMateria *ptr = new Ice;
	return (ptr);
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName();
	std::cout << " *" << std::endl;
}
