#ifndef BRAIN_HPP
#	define BRAIN_HPP

#	include <iostream>
#	include <string>

class Brain {
public:
	Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &rhs);
	~Brain();
	//Actions
	void newIdea(const std::string str);
	void clearBrain();
	void displayIdeas() const;
private:
	std::string _ideas[100];
};

#endif
