#ifndef FIXED_HPP
#	define FIXED_HPP

#	include <iostream>
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
private:
	int _rawBits;
	static const int _nFbits = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &f);


#endif
