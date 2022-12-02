#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	//AForm form(); this fails now that AForm is abstract

	Bureaucrat alice(1, "Alice");
	Bureaucrat bob(45, "Bob");
	Bureaucrat charlie(140, "Charlie");
	AForm *shrubbery = new ShrubberyCreationForm("garden");
	AForm *robotomy = new RobotomyRequestForm("Charlie");
	AForm *pardon = new PresidentialPardonForm("Bob");
	std::cout << alice << std::endl;
	std::cout << bob << std::endl;
	std::cout << charlie << std::endl;
	std::cout << *shrubbery << std::endl;
	std::cout << *robotomy << std::endl;
	std::cout << *pardon << std::endl;

	std::cout << std::endl << "Testing execution before signing" << std::endl;
	alice.executeForm(*shrubbery);
	alice.executeForm(*robotomy);
	alice.executeForm(*pardon);

	std::cout << std::endl << "Testing signing" << std::endl;
	charlie.signForm(*shrubbery);
	charlie.signForm(*robotomy);
	charlie.signForm(*pardon);
	bob.signForm(*shrubbery);
	bob.signForm(*robotomy);
	bob.signForm(*pardon);
	alice.signForm(*shrubbery);
	alice.signForm(*robotomy);
	alice.signForm(*pardon);

	std::cout << std::endl << "Testing execution" << std::endl;
	charlie.executeForm(*shrubbery);
	charlie.executeForm(*robotomy);
	charlie.executeForm(*pardon);
	bob.executeForm(*shrubbery);
	bob.executeForm(*robotomy);
	bob.executeForm(*pardon);
	alice.executeForm(*shrubbery);
	alice.executeForm(*robotomy);
	alice.executeForm(*pardon);

	delete shrubbery;
	delete robotomy;
	delete pardon;
}
