#include "Fixed.hpp"

Fixed::Fixed() {
	_rawBits = 0;
}

Fixed::Fixed(const Fixed &other) {
	*this = other;
}

Fixed::Fixed(const int n) {
	_rawBits = n << _nFbits;
}

Fixed::Fixed(const float x) {
	_rawBits = (int) roundf(x * (1 << _nFbits));
}

std::ostream &operator<<(std::ostream &os, const Fixed &f) {
	os << f.toFloat();
	return (os);
}

Fixed &Fixed::operator=(const Fixed &other) {
	_rawBits = other.getRawBits();
	return (*this);
}

Fixed::~Fixed() {}

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

bool Fixed::operator>(const Fixed &rhs) const {
	return (_rawBits > rhs.getRawBits());
}

bool Fixed::operator<(const Fixed &rhs) const {
	return (_rawBits < rhs.getRawBits());
}

bool Fixed::operator>=(const Fixed &rhs) const {
	return (_rawBits >= rhs.getRawBits());
}

bool Fixed::operator<=(const Fixed &rhs) const {
	return (_rawBits <= rhs.getRawBits());
}

bool Fixed::operator==(const Fixed &rhs) const {
	return (_rawBits == rhs.getRawBits());
}

bool Fixed::operator!=(const Fixed &rhs) const {
	return (_rawBits != rhs.getRawBits());
}

Fixed Fixed::operator+(const Fixed &rhs) const {
	Fixed res = *this;
	res.setRawBits(_rawBits + rhs.getRawBits());
	return (res);
}

Fixed Fixed::operator-(const Fixed &rhs) const {
	Fixed res = *this;
	res.setRawBits(_rawBits - rhs.getRawBits());
	return (res);
}

Fixed Fixed::operator*(const Fixed &rhs) const {
	Fixed res;
	long int newRawBits = _rawBits;
	newRawBits *= rhs.getRawBits();
	newRawBits = newRawBits >> _nFbits;
	res.setRawBits(newRawBits);
	return (res);
}

Fixed Fixed::operator/(const Fixed &rhs) const {
	if (rhs.getRawBits() == 0) {
		std::cout << "Division by 0 isn't possible" << std::endl;
		return (Fixed());
	}
	Fixed res;
	long int newRawBits = _rawBits;
	newRawBits = newRawBits << _nFbits;
	newRawBits /= rhs.getRawBits();
	int remainder = (_rawBits << _nFbits) - newRawBits * rhs.getRawBits();
	if (remainder > rhs.getRawBits() / 2 || remainder < rhs.getRawBits() / -2) {
		if (newRawBits >= 0)
			newRawBits++;
		else
			newRawBits--;
	}
	res.setRawBits(newRawBits);
	return (res);
}

Fixed Fixed::operator++() {
	_rawBits++;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	_rawBits++;
	return (temp);
}

Fixed Fixed::operator--() {
	_rawBits--;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	_rawBits--;
	return (temp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	if (a.getRawBits() <= b.getRawBits()) {
		return (a);
	}
	return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	if (a.getRawBits() <= b.getRawBits()) {
		return (a);
	}
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	if (a.getRawBits() >= b.getRawBits()) {
		return (a);
	}
	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	if (a.getRawBits() >= b.getRawBits()) {
		return (a);
	}
	return (b);
}
