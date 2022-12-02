#ifndef PRESIDENTIALPARDONFORM_HPP
#	define PRESIDENTIALPARDONFORM_HPP

#	include <string>
#	include <iostream>
#	include "AForm.hpp"

class PresidentialPardonForm : public AForm{
private:
	const std::string _target;
	virtual void action() const;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
	virtual ~PresidentialPardonForm();
};

#endif
