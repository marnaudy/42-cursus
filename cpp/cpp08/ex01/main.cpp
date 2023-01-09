#include "Span.hpp"
#include <iostream>
#include <deque>

int main() {
	Span sp_empty;
	Span sp(25);

	try {
		sp_empty.addNumber(6);
		sp_empty.addNumber(5);
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
		std::cout << sp_empty.shortestSpan() << std::endl;
		std::cout << sp_empty.longestSpan() << std::endl;
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl;
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

}
