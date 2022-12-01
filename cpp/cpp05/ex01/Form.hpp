#ifndef FORM_HPP
#	define FORM_HPP

#	include <string>
#	include <iostream>

class Bureaucrat;

class Form {
private:
	bool _isSigned;
	const int _gradeSign;
	const int _gradeExecute;
	const std::string _name;
public:
	Form();
	Form(int gradeSign, int gradeExecute, const std::string name);
	Form(const Form &other);
	Form &operator=(const Form &rhs);
	~Form();

	//Accessors
	bool isSigned() const;
	int getGradeSign() const;
	int getGradeExecute() const;
	std::string getName() const;

	//Actions
	void beSigned(const Bureaucrat &b);

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

std::ostream &operator<<(std::ostream &os, const Form &b);

#endif
