#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) {(void) other;}

Intern &Intern::operator=(const Intern &rhs) {
	(void) rhs;
	return (*this);
}

Intern::~Intern() {}

//Actions

AForm *Intern::makeForm(std::string name, std::string target) const {
	std::string knownForms[] = {"shrubbery creation",
		"robotomy request",
		"presidential pardon"};
	int formIndex = -1;
	for (int i = 0; i < 3; i++) {
		if (name == knownForms[i]) {
			formIndex = i;
		}
	}
	if (formIndex >= 0) {
		std::cout << "Intern creates " << name << std::endl;
		switch (formIndex) {
		case 0:
			return (new ShrubberyCreationForm(target));
			break;
		case 1:
			return (new RobotomyRequestForm(target));
			break;
		case 2:
			return (new PresidentialPardonForm(target));
			break;
		}
	}
	std::cout << "Intern couldn't create " << name;
	std::cout << " form, they don't know how." << std::endl;
	return (NULL);
}
