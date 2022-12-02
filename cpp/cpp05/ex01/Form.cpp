#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _isSigned(false), _gradeSign(150),
	_gradeExecute(150), _name("Empty form") {}

Form::Form(int gradeSign, int gradeExecute, std::string name)
	: _isSigned(false), _gradeSign(gradeSign),
	_gradeExecute(gradeExecute), _name(name)
{
	if (gradeSign < 1 || gradeExecute < 1) {
		throw Form::GradeTooHighException();
	}
	if (gradeSign > 150 || gradeExecute > 150) {
		throw Form::GradeTooLowException();
	}
}

Form::Form(const Form &other)
	: _isSigned(false), _gradeSign(other._gradeSign),
	_gradeExecute(other._gradeExecute), _name(other._name) {}

Form &Form::operator=(const Form &rhs) {
	_isSigned = rhs._isSigned;
	const_cast<int&>(_gradeSign) = rhs._gradeSign;
	const_cast<int&>(_gradeExecute) = rhs._gradeExecute;
	const_cast<std::string&>(_name) = rhs._name;
	return (*this);
}

Form::~Form() {}

//Accessors

bool Form::isSigned() const {
	return (_isSigned);
}

int Form::getGradeSign() const {
	return (_gradeSign);
}

int Form::getGradeExecute() const {
	return (_gradeExecute);
}

std::string Form::getName() const {
	return(_name);
}

//Actions

//Form can be signed several times of course, otherwise it isn't a true bureaucracy
void Form::beSigned(const Bureaucrat &b) {
	if (b.getGrade() > _gradeSign) {
		throw Form::GradeTooLowException();
	}
	_isSigned = true;
}

//Exceptions

const char *Form::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}

//Insertion

std::ostream &operator<<(std::ostream &os, const Form &b) {
	os << "Form : " << b.getName();
	os << ", sign grade = " << b.getGradeSign();
	os << ", execute grade = " << b.getGradeExecute();
	if (b.isSigned()) {
		os << " is signed.";
	} else {
		os << " isn't signed.";
	}
	return (os);
}
