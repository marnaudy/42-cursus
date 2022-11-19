#include "Point.hpp"

//Checks if point and c are on the same side of and not on (AB)
bool checkLine(Point const a, Point const b, Point const c, Point const point) {
	std::cout << "hello1" << std::endl;
	Point::side pointSide = point.sideOfLine(a, b);
	if (pointSide == Point::on) {
		return (false);
	}
	std::cout << "hello2" << std::endl;
	Point::side cSide = c.sideOfLine(a, b);
	return (pointSide == cSide);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	std::cout << "hello0" << std::endl;
	return (checkLine(a, b, c, point)
		&& checkLine(a, c, b, point)
		&& checkLine(b, c, a, point));
}
