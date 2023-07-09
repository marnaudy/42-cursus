#include "RPN.hpp"

#include <iostream>

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Error" << std::endl;
	}
	RPN rpn;
	try {
		int res = rpn.evaluate(argv[1]);
		std::cout << res << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
