#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other) {
	_stack = other._stack;
}

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &rhs) {
	_stack = rhs._stack;
	return(*this);
}

int RPN::evaluate(char *str) {
	unsigned int i = 0;
	while (str[i]) {
		if (isOperator(str[i])) {
			if (_stack.size() < 2) {
				throw RpnException("Error");
			}
			switch (str[i]) {
			case '+':
				add();
				break;
			case '-':
				subtract();
				break;
			case '*':
				multiply();
				break;
			case '/':
				divide();
				break;
			}
		} else if (isdigit(str[i])) {
			_stack.push(str[i] - '0');
			if (isdigit(str[i + 1])) {
				throw RpnException("Error");
			}
		} else {
			throw RpnException("Error");
		}
		i++;
		if (isspace(str[i])) {
			i++;
		}
	}
	if (_stack.size() > 1) {
		throw RpnException("Error");
	}
	return (_stack.top());
}

bool RPN::isOperator(char c) {
	std::string operators("+-*/");
	return (operators.find(c) != std::string::npos);
}

void RPN::add() {
	int a = _stack.top();
	_stack.pop();
	int b = _stack.top();
	_stack.pop();
	_stack.push(a + b);
}

void RPN::subtract() {
	int a = _stack.top();
	_stack.pop();
	int b = _stack.top();
	_stack.pop();
	_stack.push(b - a);
}

void RPN::multiply() {
	int a = _stack.top();
	_stack.pop();
	int b = _stack.top();
	_stack.pop();
	_stack.push(a * b);
}

void RPN::divide() {
	int a = _stack.top();
	_stack.pop();
	int b = _stack.top();
	_stack.pop();
	_stack.push(b / a);
}

//Exception
RPN::RpnException::RpnException(std::string message) : _message(message) {}

RPN::RpnException::~RpnException() throw() {}

const char *RPN::RpnException::what() const throw() {
	return (_message.c_str());
}
