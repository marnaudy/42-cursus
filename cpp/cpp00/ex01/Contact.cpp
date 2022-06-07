#include "Contact.hpp"
#include <iostream>

Contact::Contact(std::string first, std::string last, std::string nick,
	std::string phone, std::string secret)
	: first_name(first), last_name(last), nickname(nick), phone_number(phone), secret(secret) {}

void Contact::display_contact()
{
	std::cout << "First name: " << this->first_name << std::endl;
	std::cout << "Last name: " << this->last_name << std::endl;
	std::cout << "Nickname: " << this->nickname << std::endl;
	std::cout << "Phone number: " << this->phone_number << std::endl;
	std::cout << "Darkest secret: " << this->secret << std::endl;
}
std::string Contact::get_first_name()
{
	return (this->first_name);
}

std::string Contact::get_last_name()
{
	return (this->last_name);
}

std::string Contact::get_nickname()
{
	return (this->nickname);
}

void Contact::set_info(std::string first, std::string last, std::string nick,
	std::string phone, std::string secret)
{
	this->first_name = first;
	this->last_name = last;
	this->nickname = nickname;
	this->phone_number = phone;
	this->secret = secret;
}
