#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const Point &other) {
	*this = other;
}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point &Point::operator=(const Point &other) {
	// _x.setRawBits(other.getX().getRawBits());
	// _y.setRawBits(other.getY().getRawBits());
	(void) other;
	std::cout << "This is impossible" << std::endl;
	return (*this);
}

Point::~Point() {}

const Fixed Point::getX() const {
	return (_x);
}
const Fixed Point::getY() const {
	return (_y);
}
