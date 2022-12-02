#ifndef SHRUBBERYCREATIONFORM_HPP
#	define SHRUBBERYCREATIONFORM_HPP

#	include <string>
#	include <fstream>
#	include <iostream>
#	include "AForm.hpp"

class ShrubberyCreationForm : public AForm{
private:
	const std::string _target;
	virtual void action() const;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
	virtual ~ShrubberyCreationForm();
};

#endif
