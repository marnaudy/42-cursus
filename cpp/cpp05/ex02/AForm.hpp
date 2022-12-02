#ifndef AFORM_HPP
#	define AFORM_HPP

#	include <string>
#	include <iostream>
#	include "Bureaucrat.hpp"

class AForm {
private:
	bool _isSigned;
	const int _gradeSign;
	const int _gradeExecute;
	const std::string _name;
	virtual void action() const = 0;
public:
	AForm();
	AForm(int gradeSign, int gradeExecute, const std::string name);
	AForm(const AForm &other);
	AForm &operator=(const AForm &rhs);
	virtual ~AForm();

	//Accessors
	bool isSigned() const;
	int getGradeSign() const;
	int getGradeExecute() const;
	std::string getName() const;

	//Actions
	void beSigned(const Bureaucrat &b);
	void execute(const Bureaucrat &executor) const;

	//Exceptions
	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class NotSignedException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const AForm &b);

#endif
