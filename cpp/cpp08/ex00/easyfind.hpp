#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

class ElementNotFoundException : public std::exception {
public:
	virtual const char *what() const throw() {
		return ("Element wasn't found");
	}
};

template <typename T>
int &easyfind(T &container, int toFind) {
	typename T::iterator it = std::find(container.begin(), container.end(), toFind);
	if (it == container.end())
		throw ElementNotFoundException();	
	return (*it);
}

#endif
