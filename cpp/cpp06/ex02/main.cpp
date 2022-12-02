#include <ctime>
#include <cstdlib>
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate() {
	int r = rand() % 3;
	switch (r) {
	case 0:
		std::cout << "Created A" << std::endl;
		return (new A);
	case 1:
		std::cout << "Created B" << std::endl;
		return (new B);
	case 2:
		std::cout << "Created C" << std::endl;
		return (new C);
	}
	return (NULL);
}

void identify(Base *p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "Type identified as A from pointer" << std::endl;
	}
	if (dynamic_cast<B*>(p)) {
		std::cout << "Type identified as B from pointer" << std::endl;
	}
	if (dynamic_cast<C*>(p)) {
		std::cout << "Type identified as C from pointer" << std::endl;
	}
}

void identify(Base &p) {
	try {
		A &a = dynamic_cast<A&>(p);
		(void) a;
		std::cout << "Type identified as A from reference" << std::endl;
	} catch (const std::exception &e) {
		(void) e;
		try {
			B &b = dynamic_cast<B&>(p);
			(void) b;
			std::cout << "Type identified as B from reference" << std::endl;
		} catch (const std::exception &e) {
			(void) e;
			try {
				C &c = dynamic_cast<C&>(p);
				(void) c;
				std::cout << "Type identified as C from reference" << std::endl;
			} catch (const std::exception &e) {
				(void) e;
				std::cout << "Couldn't identify type from reference" << std::endl;			
			}
		}
	}
	
}

int main() {
	srand(time(NULL));
	for (int i = 0; i < 3; i++) {
		std::cout << "Test #" << i << std::endl;
		Base *ptr = generate();
		identify(ptr);
		identify(*ptr);
		delete ptr;
		std::cout << std::endl;
	}
}
