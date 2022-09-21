#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int n) {
	std::cout << "Int constructor called" << std::endl;
	_rawBits = n << 8;
}

Fixed::Fixed(const float x) {
	std::cout << "Float constructor called" << std::endl;
	_rawBits = (int) roundf(x * 256);
}

std::ostream &operator<<(std::ostream &os, const Fixed &f) {
	os << f.toFloat();
	return (os);
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignement operator called" << std::endl;
	this->_rawBits = other.getRawBits();
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_rawBits);
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_rawBits = raw;
}

float Fixed::toFloat() const {
	float f = 1.0 * _rawBits / 256;
	return (f);
}

int Fixed::toInt() const {
	int n = _rawBits >> 8;
	if (_rawBits & 128) {
		n++;
	}
	return (n);
}
