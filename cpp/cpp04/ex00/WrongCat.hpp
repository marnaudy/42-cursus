#ifndef WRONGCAT_HPP
#	define WRONGCAT_HPP

#	include <iostream>
#	include <string>
#	include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
public:
	WrongCat();
	WrongCat(const WrongCat &other);
	WrongCat &operator=(const WrongCat &rhs);
	~WrongCat();
	//Actions
	virtual void makeSound() const;
};

#endif
