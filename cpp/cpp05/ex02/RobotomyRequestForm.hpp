#ifndef ROBOTOMYREQUESTFORM_HPP
#	define ROBOTOMYREQUESTFORM_HPP

#	include <string>
#	include <iostream>
#	include <cstdlib>
#	include <ctime>
#	include "AForm.hpp"

class RobotomyRequestForm : public AForm{
private:
	const std::string _target;
	virtual void action() const;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);
	virtual ~RobotomyRequestForm();
};

#endif
