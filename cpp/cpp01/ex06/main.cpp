#include "Harl.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Wrong number of arguments" << std::endl;
		return (1);
	}
	std::string filter(argv[1]);
	Harl myHarl(filter);
	myHarl.complain("DEBUG");
	myHarl.complain("INFO");
	myHarl.complain("WARNING");
	myHarl.complain("ERROR");
	myHarl.complain("UNKNOWN");
}
