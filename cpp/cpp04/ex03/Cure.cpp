#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure &other) : AMateria() {
	*this = other;
}

Cure &Cure::operator=(const Cure &rhs)
{
	(void) rhs;
	_type = "cure";
	return (*this);
}

Cure::~Cure() {}

AMateria *Cure::clone() const {
	AMateria *ptr = new Cure;
	return (ptr);
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName();
	std::cout << "'s wounds *" << std::endl;
}
