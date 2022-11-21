#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog default constructor called" << std::endl;
	_type = "Dog";
}

Dog::Dog(const Dog &other) {
	*this = other;
}

Dog &Dog::operator=(const Dog &rhs) {
	_type = rhs.getType();
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

//Actions

void Dog::makeSound() const {
	std::cout << "Woof" << std::endl;
}
