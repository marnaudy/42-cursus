#ifndef BUREAUCRAT_HPP
#	define BUREAUCRAT_HPP

#	include <string>
#	include <iostream>
#	include "Form.hpp"

class Bureaucrat {
private:
	int _grade;
	const std::string _name;
public:
	Bureaucrat();
	Bureaucrat(int grade, const std::string name);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &rhs);
	~Bureaucrat();

	//Accessors
	int getGrade() const;
	std::string getName() const;

	//Actions
	void incrementGrade();
	void decrementGrade();
	void signForm(Form &f) const;

	//Exceptions
	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif
