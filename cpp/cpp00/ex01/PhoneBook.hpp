#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		void add_contact();
		void display_phonebook();
	private:
		Contact contacts[8];
		int nb_contacts;
};

#endif
