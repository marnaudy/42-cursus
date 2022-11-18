#ifndef FIXED_HPP
#	define FIXED_HPP

#	include <iostream>
#	include <iomanip>
#	include <cmath>

class Fixed {
public:
	Fixed();
	Fixed(const Fixed &other);
	Fixed(const int n);
	Fixed(const float x);
	Fixed &operator=(const Fixed &other);
	~Fixed();
	int getRawBits() const;
	void setRawBits(int const raw);
	float toFloat() const;
	int toInt() const;
	bool operator>(const Fixed &rhs);
	bool operator<(const Fixed &rhs);
	bool operator>=(const Fixed &rhs);
	bool operator<=(const Fixed &rhs);
	bool operator==(const Fixed &rhs);
	bool operator!=(const Fixed &rhs);
	Fixed operator+(const Fixed &rhs);
	Fixed operator-(const Fixed &rhs);
	Fixed operator*(const Fixed &rhs);
	Fixed operator/(const Fixed &rhs);
	Fixed operator++();
	Fixed operator++(int);
	Fixed operator--();
	Fixed operator--(int);
	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);
private:
	int _rawBits;
	static const int _nFbits = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &f);


#endif
