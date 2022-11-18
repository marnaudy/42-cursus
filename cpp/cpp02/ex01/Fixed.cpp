#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	_rawBits = 0;
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int n) {
	std::cout << "Int constructor called" << std::endl;
	_rawBits = n << _nFbits;
}

Fixed::Fixed(const float x) {
	std::cout << "Float constructor called" << std::endl;
	_rawBits = (int) roundf(x * (1 << _nFbits));
}

std::ostream &operator<<(std::ostream &os, const Fixed &f) {
	os << f.toFloat();
	return (os);
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignement operator called" << std::endl;
	_rawBits = other.getRawBits();
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
	return (_rawBits);
}

void Fixed::setRawBits(int const raw) {
	_rawBits = raw;
}

float Fixed::toFloat() const {
	float f = 1.0 * _rawBits / (1 << _nFbits);
	return (f);
}

int Fixed::toInt() const {
	int n = _rawBits >> _nFbits;
	if (_rawBits & (1 << (_nFbits - 1))) {
		n++;
	}
	return (n);
}
