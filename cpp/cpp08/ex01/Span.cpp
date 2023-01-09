#include "Span.hpp"

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(const Span &other) : _maxSize(other._maxSize), _vec(other._vec) {}

Span::~Span() {}

//Operations

Span &Span::operator=(const Span &rhs) {
	_maxSize = rhs._maxSize;
	_vec = rhs._vec;
	return (*this);
}

void Span::addNumber(int toAdd) {
	if (_vec.size() == _maxSize)
		throw Span::SpanNoRoomException();
	_vec.push_back(toAdd);
}

unsigned int Span::shortestSpan() const {
	if (_vec.size() < 2)
		throw Span::SpanTooSmallException();
	return (0);
}

unsigned int Span::longestSpan() const {
	if (_vec.size() < 2)
		throw Span::SpanTooSmallException();
	int min = *std::min_element(_vec.begin(), _vec.end());
	int max = *std::max_element(_vec.begin(), _vec.end());
	return (max - min);
}

//Exceptions

const char *Span::SpanNoRoomException::what() const throw() {
	return ("No room to add number(s) to span");
}

const char *Span::SpanTooSmallException::what() const throw() {
	return ("Span contains too few values");
}
