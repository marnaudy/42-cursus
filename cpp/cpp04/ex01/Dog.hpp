#ifndef DOG_HPP
#	define DOG_HPP

#	include <iostream>
#	include <string>
#	include "Animal.hpp"
#	include "Brain.hpp"

class Dog : public Animal{
public:
	Dog();
	Dog(const Dog &other);
	Dog &operator=(const Dog &rhs);
	virtual ~Dog();
	//Actions
	virtual void makeSound() const;
	void newIdea(const std::string str);
	void clearBrain();
	void displayIdeas() const;
private:
	Brain *_brain;
};

#endif
