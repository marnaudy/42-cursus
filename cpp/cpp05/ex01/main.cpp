#include "Bureaucrat.hpp"

int main() {
	try	{
		std::cout << "Trying grade 0" << std::endl;
		Form form(0, 0, "Billybob");
		std::cout << form << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try	{
		std::cout << "Trying grade 151" << std::endl;
		Form form(151, 151, "Billybob");
		std::cout << form << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	Bureaucrat alice(1, "Alice");
	Bureaucrat bob(150, "Bob");
	Form easyForm(150, 150, "easy");
	Form hardForm(1, 1, "hard");
	std::cout << alice << std::endl;
	std::cout << bob << std::endl;
	std::cout << easyForm << std::endl;
	std::cout << hardForm << std::endl;
	bob.signForm(easyForm);
	bob.signForm(hardForm);
	alice.signForm(easyForm);
	alice.signForm(hardForm);
}
