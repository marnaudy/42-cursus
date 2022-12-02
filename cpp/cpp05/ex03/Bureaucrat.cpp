#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _grade(150), _name("Bob") {}

Bureaucrat::Bureaucrat(int grade, const std::string name) : _grade(150), _name(name) {
	if (grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	if (grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
	: _grade(other._grade), _name(other._name) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
	_grade = rhs._grade;
	const_cast<std::string&>(_name) = rhs._name;
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

//Accessors

int Bureaucrat::getGrade() const {
	return (_grade);
}

std::string Bureaucrat::getName() const {
	return(_name);
}

//Actions

void Bureaucrat::incrementGrade() {
	if (_grade == 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	_grade--;
}

void Bureaucrat::decrementGrade() {
	if (_grade == 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	_grade++;
}

void Bureaucrat::signForm(AForm &f) const {
	try {
		f.beSigned(*this);
		std::cout << _name << " signed ";
		std::cout << f.getName() << std::endl;
	} catch (const std::exception &e) {
		std::cout << _name << " couldn't sign ";
		std::cout << f.getName() << " because ";
		std::cout << e.what() << "." << std::endl;
	}
}

void Bureaucrat::executeForm(AForm &f) const {
	try {
		f.execute(*this);
		std::cout << _name << " executed ";
		std::cout << f.getName() << std::endl;
	} catch (const std::exception &e) {
		std::cout << _name << " couldn't execute ";
		std::cout << f.getName() << " because ";
		std::cout << e.what() << "." << std::endl;
	}
}

//Exceptions

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}

//Insertion

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b) {
	os << b.getName() << ", bureaucrat grade ";
	os << b.getGrade() << ".";
	return (os);
}
