#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main( void ) {
	const Point a;
	const Point b(0.0f, 1.0f);
	const Point c(1.0f, 0.0f);
	const Point p1(0.1f, 0.1f);
	const Point p2(-0.1f, -0.1f);
	const Point p3(0.0f, 0.0f);
	std::cout << "hi" << std::endl;
	std::cout << bsp(a, b, c, p1) << std::endl;
	std::cout << bsp(a, b, c, p2) << std::endl;
	std::cout << bsp(a, b, c, p3) << std::endl;
}
