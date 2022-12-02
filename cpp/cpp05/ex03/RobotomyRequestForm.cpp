#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm(72, 45, "robotomy request")
{
	srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
	: AForm(72, 45, "robotomy request"), _target(target)
{
	srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other.getGradeSign(), other.getGradeExecute(), other.getName()),
		_target(other._target)
{
	srand(time(NULL));
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
	const_cast<std::string&>(_target) = rhs._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::action() const {
	std::cout << "*Bzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz* ";
	if (rand() % 2) {
		std::cout << _target << " has been robotomised." << std::endl;
	} else {
		std::cout << "robotomisation has failed, " << _target;
		std::cout << " is unchanged." << std::endl;
	}
}
