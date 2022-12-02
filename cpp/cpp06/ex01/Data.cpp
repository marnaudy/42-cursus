#include "Data.hpp"

Data::Data() : _a(42) {}

Data::Data(const Data &other) : _a(other._a) {}

Data &Data::operator=(const Data &rhs) {
	_a = rhs._a;
	return (*this);
}

Data::~Data() {}
