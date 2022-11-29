#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog default constructor called" << std::endl;
	_type = "Dog";
	_brain = new Brain;
}

Dog::Dog(const Dog &other) : Animal() {
	_brain = new Brain;
	*this = other;
}

Dog &Dog::operator=(const Dog &rhs) {
	_type = rhs.getType();
	*_brain = *(rhs._brain);
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

//Actions

void Dog::makeSound() const {
	std::cout << "Woof" << std::endl;
}

void Dog::newIdea(const std::string str) {
	_brain->newIdea(str);
}

void Dog::clearBrain() {
	_brain->clearBrain();
}

void Dog::displayIdeas() const{
	_brain->displayIdeas();
}
