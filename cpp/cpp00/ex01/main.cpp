#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main() {
	PhoneBook	book;
	std::string	input;

	while (1) {
		if (std::cin.eof())
			break;
		std::cout << "Main menu : choose ADD, SEARCH, or EXIT" << std::endl;
		std::cin >> input;
		if (!input.compare("EXIT") || std::cin.eof())
			break;
		if (!input.compare("ADD"))
			book.add_contact();
		if (!input.compare("SEARCH")) {
			book.search();
		}
	}
}
