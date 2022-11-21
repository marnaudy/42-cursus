#include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << "WrongCat default constructor called" << std::endl;
	_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other) {
	*this = other;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs) {
	_type = rhs.getType();
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

//Actions

void WrongCat::makeSound() const {
	std::cout << "Meow" << std::endl;
}
