#include "Span.hpp"
#include <iostream>
#include <deque>

int main() {
	Span spEmpty;
	Span sp(25);

	try {
		spEmpty.addNumber(6);
		spEmpty.addNumber(5);
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << spEmpty.shortestSpan() << std::endl;
		std::cout << spEmpty.longestSpan() << std::endl;
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl << "Testing small span" << std::endl;
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << std::endl;
	std::vector<int> vec(10, 42);
	sp.addNumber(vec.begin(), vec.end());
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << std::endl;
	std::deque<int> deq(10, -42);
	sp.addNumber(deq.begin(), deq.end());
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << std::endl << "Testing big span" << std::endl;
	Span spBig(100000);
	std::deque<int> deqBig(99998, 42);
	spBig.addNumber(0);
	spBig.addNumber(deqBig.begin(), deqBig.end());
	spBig.addNumber(3);
	std::cout << spBig.shortestSpan() << std::endl;
	std::cout << spBig.longestSpan() << std::endl;
}
