#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cstdlib>
#include <string>
#include <iostream>

enum type_e {
	char_type,
	int_type,
	float_type,
	double_type,
	unknown_type
};

class ScalarConverter {
public:
	ScalarConverter();
	ScalarConverter(const std::string &str);
	ScalarConverter(const ScalarConverter &other);
	~ScalarConverter();
	ScalarConverter &operator=(const ScalarConverter &rhs);
	bool isChar() const;
	bool isInt() const;
	bool isFloat() const;
	bool isDouble() const;
	const std::string &getStr() const;
	enum type_e getType() const;
private:
	std::string _str;
};

std::ostream &operator<<(std::ostream &os, const ScalarConverter &conv);

#endif
