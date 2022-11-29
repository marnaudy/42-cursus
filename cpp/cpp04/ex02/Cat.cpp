#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat default constructor called" << std::endl;
	_type = "Cat";
	_brain = new Brain;
}

Cat::Cat(const Cat &other) : AAnimal() {
	_brain = new Brain;
	*this = other;
}

Cat &Cat::operator=(const Cat &rhs) {
	_type = rhs.getType();
	*_brain = *(rhs._brain);
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
}

//Actions

void Cat::makeSound() const {
	std::cout << "Meow" << std::endl;
}

void Cat::newIdea(const std::string str) {
	_brain->newIdea(str);
}

void Cat::clearBrain() {
	_brain->clearBrain();
}

void Cat::displayIdeas() const{
	_brain->displayIdeas();
}
