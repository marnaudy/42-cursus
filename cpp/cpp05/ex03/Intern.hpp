#ifndef INTERN_HPP
#	define INTERN_HPP

#	include <string>
#	include "ShrubberyCreationForm.hpp"
#	include "RobotomyRequestForm.hpp"
#	include "PresidentialPardonForm.hpp"

class Intern {
public:
	Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &rhs);
	~Intern();

	//Actions
	AForm *makeForm(std::string name, std::string target) const;
};

#endif
