#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &other) {
	*this = other;
}

Animal &Animal::operator=(const Animal &rhs) {
	_type = rhs.getType();
	return (*this);
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

//Accessors

const std::string &Animal::getType() const {
	return (_type);
}

//Actions

void Animal::makeSound() const {
	std::cout << "Generic animal noises" << std::endl;
}
