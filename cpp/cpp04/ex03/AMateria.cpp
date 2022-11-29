#include "AMateria.hpp"

AMateria::AMateria() : _type("unknown") {}

AMateria::AMateria(std::string const &type) : _type(type) {}

AMateria::AMateria( const AMateria &other) {
	*this = other;
}

AMateria &AMateria::operator=(const AMateria &rhs) {
	(void) rhs;
	_type = "";
	return (*this);
}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const {
	return (_type);
}

void AMateria::use(ICharacter &target) {
	(void) target;
	std::cout << "* Weird unknown materia things *" << std::endl;
}
