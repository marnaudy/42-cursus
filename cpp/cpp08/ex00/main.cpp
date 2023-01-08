#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

int main() {
	std::cout << "Testing vector" << std::endl;
	std::vector<int> vec;
	try {
		std::cout << easyfind(vec, 42) << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	for (int i = 0; i < 50; i++) {
		vec.push_back(i);
	}
	try {
		std::cout << easyfind(vec, 42) << std::endl;
		std::cout << easyfind(vec, -1) << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "Testing list" << std::endl;
	std::list<int> lst;
	try {
		std::cout << easyfind(lst, 42) << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	for (int i = 0; i < 50; i++) {
		lst.push_back(i);
	}
	try {
		std::cout << easyfind(lst, 42) << std::endl;
		std::cout << easyfind(lst, -1) << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "Testing deque" << std::endl;
	std::deque<int> deq;
	try {
		std::cout << easyfind(deq, 42) << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	for (int i = 0; i < 50; i++) {
		deq.push_back(i);
	}
	try {
		std::cout << easyfind(deq, 42) << std::endl;
		std::cout << easyfind(deq, -1) << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
