#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	public:
		PhoneBook();
		~PhoneBook();
		void display_phonebook();
		void search();
		void add_contact();
		int get_nb_contacts();
	private:
		Contact contacts[8];
		int nb_contacts;
};

#endif
