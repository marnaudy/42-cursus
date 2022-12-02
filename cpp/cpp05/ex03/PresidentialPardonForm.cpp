#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm(25, 5, "presidential pardon") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
	: AForm(25, 5, "presidential pardon"), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	: AForm(other.getGradeSign(), other.getGradeExecute(), other.getName()),
		_target(other._target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
	const_cast<std::string&>(_target) = rhs._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::action() const {
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox.";
	std::cout << std::endl;
}
