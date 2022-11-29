#include "AAnimal.hpp"

AAnimal::AAnimal() {
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) {
	*this = other;
}

AAnimal &AAnimal::operator=(const AAnimal &rhs) {
	_type = rhs.getType();
	return (*this);
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called" << std::endl;
}

//Accessors

const std::string &AAnimal::getType() const {
	return (_type);
}
