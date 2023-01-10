#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
public:
	class iterator {
	public:
		iterator() {}
		iterator(const iterator &other) {}
		~iterator() {}

		iterator &operator=(const iterator &rhs) {
			return (*this);
		}
		bool operator==(const iterator &rhs) {
			return (true);
		}
		bool operator!=(const iterator &rhs) {

		}
		T &operator*() {
			
		}
		iterator &operator++() {
			
		}
		iterator &operator--() {
			
		}
		iterator operator++(int) {
			
		}
		iterator operator--(int) {

		}
	};
	iterator begin() {

	}
	iterator end() {
		
	}
};

#endif
