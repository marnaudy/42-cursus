#ifndef WRONGANIMAL_HPP
#	define WRONGANIMAL_HPP

#	include <iostream>
#	include <string>

class WrongAnimal {
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &other);
	WrongAnimal &operator=(const WrongAnimal &rhs);
	virtual ~WrongAnimal();
	//Accessors
	const std::string &getType() const;
	//Actions
	void makeSound() const;
protected:
	std::string _type;
};

#endif
