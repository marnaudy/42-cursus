#ifndef ANIMAL_HPP
#	define ANIMAL_HPP

#	include <iostream>
#	include <string>

class Animal {
public:
	Animal();
	Animal(const Animal &other);
	Animal &operator=(const Animal &rhs);
	~Animal();
	//Accessors
	const std::string &getType() const;
	//Actions
	virtual void makeSound() const;
protected:
	std::string _type;
};

#endif
