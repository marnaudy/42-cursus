#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat bob(1, "Bob");
		std::cout << bob << std::endl;
		Bureaucrat bob2 = bob;
		std::cout << bob2 << std::endl;
		bob2.decrementGrade();
		std::cout << bob2 << std::endl;
		bob.incrementGrade();
	}
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat bill(150, "Bill");
		std::cout << bill << std::endl;
		Bureaucrat bill2 = bill;
		std::cout << bill2 << std::endl;
		bill2.incrementGrade();
		std::cout << bill2 << std::endl;
		bill.decrementGrade();
	}
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try	{
		std::cout << "Trying grade 0" << std::endl;
		Bureaucrat billybob(0, "Billybob");
		std::cout << billybob << std::endl;
	}
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try	{
		std::cout << "Trying grade 151" << std::endl;
		Bureaucrat billybob(151, "Billybob");
		std::cout << billybob << std::endl;
	}
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "Testing name overwrite" << std::endl;
	const std::string name = "Alice the third, haver of long name";
	Bureaucrat alice(1, name);
	Bureaucrat bob(1, "Bob");
	bob = alice;
	std::cout << bob << std::endl;
}
