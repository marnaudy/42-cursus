#ifndef CAT_HPP
#	define CAT_HPP

#	include <iostream>
#	include <string>
#	include "Animal.hpp"
#	include "Brain.hpp"

class Cat : public Animal{
public:
	Cat();
	Cat(const Cat &other);
	Cat &operator=(const Cat &rhs);
	virtual ~Cat();
	//Actions
	virtual void makeSound() const;
	void newIdea(const std::string str);
	void clearBrain();
	void displayIdeas() const;
private:
	Brain *_brain;
};

#endif
