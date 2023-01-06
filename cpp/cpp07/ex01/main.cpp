#include "iter.hpp"
#include <iostream>

template <typename T>
void print(T &t) {
	std::cout << t << " ";
}

template <typename T>
void increment(T &t) {
	t += 1;
}

void incrementPrintDouble(double &d) {
	d += 1;
	std::cout << d << " ";
}

int main() {
	int intArray[] = {0, 1, 2, 3};
	iter<int>(intArray, 4, &print<int>);
	std::cout << std::endl;
	iter<int>(intArray, 4, &increment<int>);
	iter<int>(intArray, 4, &print<int>);
	std::cout << std::endl;

	double doubleArray[] = {0.0, 1.0, 2.0, 3.0};
	iter<double>(doubleArray, 4, &print<double>);
	std::cout << std::endl;
	iter<double>(doubleArray, 4, &incrementPrintDouble);
	std::cout << std::endl;
}
