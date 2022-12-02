#include "Data.hpp"
#include <stdint.h>
#include <iostream>

uintptr_t serialize(Data *ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data*>(raw));
}

int main() {
	Data d;
	uintptr_t raw = serialize(&d);
	Data *newPTR = deserialize(raw);
	std::cout << "Address of d = " << &d << std::endl;
	std::cout << "Value of raw = " << raw << std::endl;
	std::cout << "Value of raw in hex = " << std::hex << raw << std::endl;
	std::cout << "Address in new pointer = " << newPTR << std::endl;
}
