#ifndef POINT_HPP
#	define POINT_HPP

#	include <iostream>
#	include <iomanip>
#	include <cmath>
#	include "Fixed.hpp"

class Point {
public:
	Point();
	Point(const float x, const float y);
	Point(const Point &other);
	Point &operator=(const Point &other);
	~Point();
	const Fixed getX() const;
	const Fixed getY() const;
private:
	const Fixed _x;
	const Fixed _y;
};



#endif
