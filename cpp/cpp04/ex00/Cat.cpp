#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat default constructor called" << std::endl;
	_type = "Cat";
}

Cat::Cat(const Cat &other) {
	*this = other;
}

Cat &Cat::operator=(const Cat &rhs) {
	_type = rhs.getType();
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

//Actions

void Cat::makeSound() const {
	std::cout << "Meow" << std::endl;
}
