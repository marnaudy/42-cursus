#ifndef DOG_HPP
#	define DOG_HPP

#	include <iostream>
#	include <string>
#	include "Animal.hpp"

class Dog : public Animal{
public:
	Dog();
	Dog(const Dog &other);
	Dog &operator=(const Dog &rhs);
	virtual ~Dog();
	//Actions
	virtual void makeSound() const;
};

#endif
