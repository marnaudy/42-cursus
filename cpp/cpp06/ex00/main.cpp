#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Wrong number of arguments (1 expected)" << std::endl;
		return (1);
	}
	ScalarConverter conv(argv[1]);
	conv.print();
}
