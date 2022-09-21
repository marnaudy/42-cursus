#include <iostream>
#include <string>

int	main(int argc, char **argv) {
	if (argc <= 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	std::string str;
	for (int i = 1; argv[i]; i++) {
		str = std::string(argv[i]);
		for (unsigned int j = 0; j < str.length(); j++){
			str[j] = toupper(str[j]);
		}
		std::cout << str;
	}
	std::cout << std::endl;
}
