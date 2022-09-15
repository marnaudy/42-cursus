#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

void add_contact(PhoneBook book) {
	std::string	first, last, nick, phone, secret;

	if (std::cin.eof())
		return;
	std::cout << "Enter first name" << std::endl;
	std::cin >> first;
	if (std::cin.eof())
		return;
	std::cout << "Enter last name" << std::endl;
	std::cin >> last;
	if (std::cin.eof())
		return;
	std::cout << "Enter nickname" << std::endl;
	std::cin >> nick;
	if (std::cin.eof())
		return;
	std::cout << "Enter phone number" << std::endl;
	std::cin >> phone;
	if (std::cin.eof())
		return;
	std::cout << "Enter darkest secret" << std::endl;
	std::cin >> secret;
	book.add_contact(first, last, nick, phone, secret);
	std::cout << book.get_nb_contacts() << std::endl;
}

int main() {
	PhoneBook	book;
	std::string	input;

	while (1) {
		if (std::cin.eof())
			break;
		std::cout << book.get_nb_contacts() << std::endl;
		std::cout << "Main menu : choose ADD, SEARCH, or EXIT" << std::endl;
		std::cin >> input;
		if (!input.compare("EXIT") || std::cin.eof())
			break;
		if (!input.compare("ADD"))
			add_contact(book);
		if (!input.compare("SEARCH")) {
			book.display_phonebook();
		}
	}
}
