#include "PhoneBook.hpp"
#include <iostream>
#include <sstream>

PhoneBook::PhoneBook() {
	this->nb_contacts = 0;
}

PhoneBook::~PhoneBook() {}

void display_header() {
	std::cout << "|     Index|First name| Last name|  Nickname|" << std::endl;
}

void print_max_10(std::string str)
{
	int len = str.length();
	if (len <= 10) {
		for (int i = 0; i < 10 - len; i++) {
			std::cout << " ";
		}
		std::cout << str;
		return;
	}
	std::cout << str.substr(0, 9) << ".";
}

void print_max_10(int n) {
	std::stringstream ss;
	ss << n;
	std::string str = ss.str();
	print_max_10(str);
}

void PhoneBook::display_phonebook() {
	display_header();
	for (int i = 0; i < 8; i++) {
		if (i >= this->nb_contacts) {
			std::cout << "|          |          |          |          |" << std::endl;
			continue;
		}
		std::cout << "|";
		print_max_10(i);
		std::cout << "|";
		print_max_10(contacts[i].get_first_name());
		std::cout << "|";
		print_max_10(contacts[i].get_last_name());
		std::cout << "|";
		print_max_10(contacts[i].get_nickname());
		std::cout << "|" << std::endl;
	}
}

void PhoneBook::search() {
	int n;
	std::string str;

	if (std::cin.eof()) {
		return;
	}
	display_phonebook();
	std::cout << "Choose an index" << std::endl;
	std::getline(std::cin, str);
	if (str.length() > 0)
		std::istringstream(str) >> n;
	else
		n = -1;
	if (n < this->nb_contacts && n >= 0 && n < 8) {
		this->contacts[n].display();
	}
}

std::string getNonEmptyLine() {
	std::string str;
	std::getline(std::cin, str);
	while (!std::cin.eof() && str.length() == 0) {
		std::getline(std::cin, str);
	}
	return (str);
}

void PhoneBook::add_contact() {
	std::string	first, last, nick, phone, secret;

	if (std::cin.eof())
		return;
	std::cout << "Enter first name" << std::endl;
	first = getNonEmptyLine();
	if (std::cin.eof())
		return;
	std::cout << "Enter last name" << std::endl;
	last = getNonEmptyLine();
	if (std::cin.eof())
		return;
	std::cout << "Enter nickname" << std::endl;
	nick = getNonEmptyLine();
	if (std::cin.eof())
		return;
	std::cout << "Enter phone number" << std::endl;
	phone = getNonEmptyLine();
	if (std::cin.eof())
		return;
	std::cout << "Enter darkest secret" << std::endl;
	secret = getNonEmptyLine();
	contacts[nb_contacts % 8].set_info(first, last, nick, phone, secret);
	nb_contacts++;
}

int PhoneBook::get_nb_contacts() {
	return (nb_contacts);
}
