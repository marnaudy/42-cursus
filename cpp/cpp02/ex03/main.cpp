#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main( void ) {
	const Point a;
	const Point b(0.0f, 1.0f);
	const Point c(1.0f, 0.0f);
	const Point d(0.0f, -1.0f);
	const Point e(-1.0f, 0.0f);
	const Point p1(0.1f, 0.1f);
	const Point p2(-0.1f, -0.1f);
	const Point p3(0.0f, 0.0f);
	const Point p4(0.9f, 0.01f);
	std::cout << "P1 is in ABC : " << bsp(a, b, c, p1) << std::endl;
	std::cout << "P2 is in ABC : " << bsp(a, b, c, p2) << std::endl;
	std::cout << "P3 is in ABC : " << bsp(a, b, c, p3) << std::endl;
	std::cout << "P4 is in ABC : " << bsp(a, b, c, p4) << std::endl;
	std::cout << "P1 is in ADE : " << bsp(a, d, e, p1) << std::endl;
	std::cout << "P2 is in ADE : " << bsp(a, d, e, p2) << std::endl;
	std::cout << "P3 is in ADE : " << bsp(a, d, e, p3) << std::endl;
}
