#ifndef CAT_HPP
#	define CAT_HPP

#	include <iostream>
#	include <string>
#	include "Animal.hpp"

class Cat : public Animal{
public:
	Cat();
	Cat(const Cat &other);
	Cat &operator=(const Cat &rhs);
	virtual ~Cat();
	//Actions
	virtual void makeSound() const;
};

#endif
