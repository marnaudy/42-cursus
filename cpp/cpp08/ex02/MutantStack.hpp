#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
public:
	MutantStack<T>() : std::stack<T>() {}
	MutantStack<T>(const MutantStack &other) : std::stack<T>(other) {}
	~MutantStack<T>() {}
	MutantStack<T> &operator=(const MutantStack<T> &rhs) {
		std::stack<T>::c = rhs.c;
	}
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	iterator begin() {
		return (std::stack<T>::c.begin());
	}
	const_iterator begin() const{
		return (std::stack<T>::c.begin());
	}
	iterator end() {
		return (std::stack<T>::c.end());
	}
	const_iterator end() const{
		return (std::stack<T>::c.end());
	}
};

#endif
