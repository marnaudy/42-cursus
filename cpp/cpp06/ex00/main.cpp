#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Wrong number of arguments (1 expected)" << std::endl;
		return (1);
	}
	std::cout << std::atof(argv[1]) << std::endl;
	std::cout << static_cast<int>(std::atof(argv[1])) << std::endl;
	std::cout << static_cast<char>(std::atof(argv[1])) << std::endl;
	std::cout << static_cast<float>(std::atof(argv[1])) << std::endl;
	std::cout << std::endl;

	ScalarConverter conv(argv[1]);
	std::cout << conv;
}
