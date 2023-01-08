#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() : _str("") {}

ScalarConverter::ScalarConverter(const std::string &str) : _str(str) {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) : _str(other._str) {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) {
	_str = rhs._str;
	return (*this);
}

std::string trimWS(const std::string &str) {
	size_t start = str.find_first_not_of(" \f\t\n\r\v");
	if (start == std::string::npos) {
		return ("");
	}
	size_t end = str.find_last_not_of(" \f\t\n\r\v");
	// std::string trimmed = str.substr(start, end - start + 1);
	// std::cout << '_' << trimmed << '_' << std::endl;
	return (str.substr(start, end - start + 1));
}

bool ScalarConverter::isChar() const {
	return (_str.length() == 1 && !isdigit(_str[0]));
}

bool ScalarConverter::isInt() const {
	if (_str.length() == 0) {
		return (false);
	}
	std::string trimmed = trimWS(_str);
	return (trimmed.length() != 0
		&& trimmed.find_first_not_of("0123456789") == std::string::npos);
}

bool ScalarConverter::isFloat() const {
	if (_str.length() == 0) {
		return (false);
	}
	std::string trimmed = trimWS(_str);
	if (trimmed == "nanf" || trimmed == "inff"
		|| trimmed == "+inff" || trimmed == "-inff") {
		return (true);
	}
	size_t decimalPos = trimmed.find('.');
	return (trimmed.length() != 0
		&& trimmed[trimmed.length() - 1] == 'f'
		&& trimmed.find_first_not_of(".0123456789") == trimmed.length() - 1
		&& decimalPos != std::string::npos
		&& decimalPos != 0
		&& decimalPos != trimmed.length() - 2
		&& trimmed.find('.', decimalPos + 1) == std::string::npos);
}

bool ScalarConverter::isDouble() const {
	if (_str.length() == 0) {
		return (false);
	}
	std::string trimmed = trimWS(_str);
	if (trimmed == "nan" || trimmed == "inf"
		|| trimmed == "+inf" || trimmed == "-inf") {
		return (true);
	}
	size_t decimalPos = trimmed.find('.');
	return (trimmed.length() != 0
		&& trimmed.find_first_not_of(".0123456789") == std::string::npos
		&& decimalPos != std::string::npos
		&& decimalPos != 0
		&& decimalPos != trimmed.length() - 1
		&& trimmed.find('.', decimalPos + 1) == std::string::npos);
}

const std::string &ScalarConverter::getStr() const {
	return (_str);
}

enum type_e ScalarConverter::getType() const {
	if (this->isChar())
		return (char_type);
	if (this->isInt())
		return (int_type);
	if (this->isFloat())
		return (float_type);
	if (this->isDouble())
		return (double_type);
	return (unknown_type);
}

std::ostream &operator<<(std::ostream &os, const ScalarConverter &conv) {
	type_e type = conv.getType();
	os << type << std::endl;
	double value = atof(conv.getStr().c_str());
	os << "char: ";
	if (type == char_type)
		os << conv.getStr() << std::endl;
	if (type == int_type || type == float_type || type == double_type) {
		if (value > 127.0 || value < 0.0)
			os << "impossible" << std::endl;
		else if (value >= 32.0 && value < 127.0)
			os << static_cast<char>(value) << std::endl;
		else
			os << "non displayable" << std::endl;
	}
	if (type == unknown_type)
		os << "impossible" << std::endl;
	return (os);
}
