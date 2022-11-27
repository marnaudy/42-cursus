#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &other) {
	*this = other;
}

Brain &Brain::operator=(const Brain &rhs) {
	for (int i = 0; i < 100; i++) {
		_ideas[i] = rhs._ideas[i];
	}
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

//Actions

void Brain::newIdea(const std::string str) {
	int i = 0;
	while (i < 100 && _ideas[i].length() == 0) {
		i++;
	}
	if (i == 100) {
		std::cout << "Brain is full" << std::endl;
	} else {
		_ideas[i] = str;
	}
}

void Brain::clearBrain() {
	for (int i = 0; i < 100; i++) {
		_ideas[i] = "";
	}
}
