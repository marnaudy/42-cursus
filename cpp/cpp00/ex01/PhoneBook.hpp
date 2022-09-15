#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		void display_phonebook();
		void add_contact(std::string first, std::string last, std::string nick,
			std::string phone, std::string secret);
		int get_nb_contacts();
	private:
		Contact contacts[8];
		int nb_contacts;
};

#endif
