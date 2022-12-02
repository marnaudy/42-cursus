#include "AForm.hpp"

AForm::AForm() : _isSigned(false), _gradeSign(150),
	_gradeExecute(150), _name("Empty form") {}

AForm::AForm(int gradeSign, int gradeExecute, std::string name)
	: _isSigned(false), _gradeSign(gradeSign),
	_gradeExecute(gradeExecute), _name(name)
{
	if (gradeSign < 1 || gradeExecute < 1) {
		throw AForm::GradeTooHighException();
	}
	if (gradeSign > 150 || gradeExecute > 150) {
		throw AForm::GradeTooLowException();
	}
}

AForm::AForm(const AForm &other)
	: _isSigned(false), _gradeSign(other._gradeSign),
	_gradeExecute(other._gradeExecute), _name(other._name) {}

AForm &AForm::operator=(const AForm &rhs) {
	_isSigned = rhs._isSigned;
	const_cast<int&>(_gradeSign) = rhs._gradeSign;
	const_cast<int&>(_gradeExecute) = rhs._gradeExecute;
	const_cast<std::string&>(_name) = rhs._name;
	return (*this);
}

AForm::~AForm() {}

//Accessors

bool AForm::isSigned() const {
	return (_isSigned);
}

int AForm::getGradeSign() const {
	return (_gradeSign);
}

int AForm::getGradeExecute() const {
	return (_gradeExecute);
}

std::string AForm::getName() const {
	return(_name);
}

//Actions

//AForm can be signed several times of course, otherwise it isn't a true bureaucracy
void AForm::beSigned(const Bureaucrat &b) {
	if (b.getGrade() > _gradeSign) {
		throw AForm::GradeTooLowException();
	}
	_isSigned = true;
}

void AForm::execute(const Bureaucrat &executor) const {
	if (!_isSigned) {
		throw AForm::NotSignedException();
	}
	if (executor.getGrade() > _gradeExecute) {
		throw AForm::GradeTooLowException();
	}
	this->action();
}

//Exceptions

const char *AForm::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}

const char *AForm::NotSignedException::what() const throw() {
	return ("Form isn't signed");
}

//Insertion

std::ostream &operator<<(std::ostream &os, const AForm &b) {
	os << "Form : " << b.getName();
	os << ", sign grade = " << b.getGradeSign();
	os << ", execute grade = " << b.getGradeSign();
	if (b.isSigned()) {
		os << " is signed.";
	} else {
		os << " isn't signed.";
	}
	return (os);
}
