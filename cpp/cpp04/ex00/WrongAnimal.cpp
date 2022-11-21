#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	*this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs) {
	_type = rhs.getType();
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

//Accessors

const std::string &WrongAnimal::getType() const {
	return (_type);
}

//Actions

void WrongAnimal::makeSound() const {
	std::cout << "Generic (probably incorrect) animal noises" << std::endl;
}
