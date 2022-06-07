#include "PhoneBook.hpp"
#include <iostream>
#include <sstream>

PhoneBook::PhoneBook()
{
	this->nb_contacts = 0;
}

void display_header()
{
	std::cout << "|     Index|First name| Last name|  Nickname|" << std::endl;
}

void print_max_10(std::string str)
{
	int len = str.length();
	if (len <= 10)
	{
		for (int i = 0; i < 10 - len; i++) {
			std::cout << " ";
		}
		std::cout << str;
	}
	std::cout << str.substr(0, 9) << ".";
}

void print_max_10(int n)
{
	std::stringstream ss;
	ss << n;
	std::string str = ss.str();
	print_max_10(str);
}

void PhoneBook::display_phonebook()
{
	display_header();
	for (int i = 0; i < 8; i++) {
		if (i >= nb_contacts) {
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
