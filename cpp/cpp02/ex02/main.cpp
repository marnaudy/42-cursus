#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << std::endl;
	std::cout << "Fixed : 1 000 000 + 1 / 64 - 1 000 000 = ";
	std::cout << Fixed(1000000) + Fixed(1) / Fixed(64) - Fixed(1000000) << std::endl;
	std::cout << "Float : 1 000 000 + 1 / 64 - 1 000 000 = ";
	std::cout << 1000000.0f + 1.0f / 64.0f - 1000000.0f << std::endl;

	std::cout << std::endl;
	std::cout << "Fixed : 1 000 * 8 000 = ";
	std::cout << Fixed(1000) * Fixed(8000) << std::endl;
	std::cout << "Float : 1 000 * 8 000 = ";
	std::cout << 1000.0f * 8000.0f << std::endl;

	std::cout << std::endl;
	std::cout << "Fixed : 10 001 / 100 = ";
	std::cout << Fixed(10001) / Fixed(100) << std::endl;
	std::cout << "Float : 10 001 / 100 = ";
	std::cout << 10001.0f / 100.0f << std::endl;

	std::cout << std::endl;
	std::cout << "Fixed : 10 000 / -67 = ";
	std::cout << Fixed(10000) / Fixed(-67) << std::endl;
	std::cout << "Fixed : -10 000 / -67 = ";
	std::cout << Fixed(-10000) / Fixed(67) << std::endl;
	std::cout << "Fixed : 10 000 / 67 = ";
	std::cout << Fixed(10000) / Fixed(67) << std::endl;
	std::cout << "Fixed : -10 000 / -67 = ";
	std::cout << Fixed(-10000) / Fixed(-67) << std::endl;
	std::cout << "Float : 10 000 / 67 = ";
	std::cout << 10000.0f / 67.0f << std::endl;

	std::cout << std::endl;
	std::cout << "7 < 7 = " << (Fixed(8) < Fixed(7)) << std::endl;
	std::cout << "7 <= 7 = " << (Fixed(7) <= Fixed(7)) << std::endl;
	std::cout << "8 > 7 = " << (Fixed(8) > Fixed(7)) << std::endl;
	std::cout << "7 >= 7 = " << (Fixed(7) >= Fixed(7)) << std::endl;
	std::cout << "8 == 7 = " << (Fixed(8) == Fixed(7)) << std::endl;
	std::cout << "7 == 7 = " << (Fixed(7) == Fixed(7)) << std::endl;
	std::cout << "7 != 7 = " << (Fixed(7) != Fixed(7)) << std::endl;
	std::cout << "8 != 7 = " << (Fixed(8) != Fixed(7)) << std::endl;
	std::cout << "min(7,8) = " << Fixed::min(Fixed(7), Fixed(8)) << std::endl;
	std::cout << "max(7,8) = " << Fixed::max(Fixed(7), Fixed(8)) << std::endl;
}
