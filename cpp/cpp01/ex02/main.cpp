#include <iostream>
#include <string>

int main() {
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;
	std::cout << "String address : " << &str << std::endl;
	std::cout << "Address in pointer : " << stringPTR << std::endl;
	std::cout << "Address in reference : " << &stringREF << std::endl;
	std::cout << "String value : " << str << std::endl;
	std::cout << "Value in pointer : " << *stringPTR << std::endl;
	std::cout << "Value in reference : " << stringREF << std::endl;
}
