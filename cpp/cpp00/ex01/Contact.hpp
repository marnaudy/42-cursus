#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact {
	public:
		Contact();
		Contact(std::string first, std::string last, std::string nick,
			std::string phone, std::string secret);
		~Contact();
		std::string get_first_name();
		std::string get_last_name();
		std::string get_nickname();
		void display();
		void set_info(std::string first, std::string last, std::string nick,
			std::string phone, std::string secret);
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	secret;
};


#endif
