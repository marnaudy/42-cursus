#ifndef FIXED_HPP
#	define FIXED_HPP

#	include <iostream>

class Fixed {
public:
	Fixed();
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	~Fixed();
	int getRawBits() const;
	void setRawBits(int const raw);
private:
	int _rawBits;
	static const int _nFbits = 8;
};



#endif
