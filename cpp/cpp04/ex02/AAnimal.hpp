#ifndef AANIMAL_HPP
#	define AANIMAL_HPP

#	include <iostream>
#	include <string>

class AAnimal {
public:
	AAnimal();
	AAnimal(const AAnimal &other);
	AAnimal &operator=(const AAnimal &rhs);
	virtual ~AAnimal();
	//Accessors
	const std::string &getType() const;
	//Actions
	virtual void makeSound() const = 0;
protected:
	std::string _type;
};

#endif
