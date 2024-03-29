#include "Harl.hpp"

Harl::Harl() : filter_level(0) {}

Harl::Harl(std::string filter) {
	std::string tab[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	this->filter_level = -1;
	for (int i = 0; i < 4; i++) {
		if (tab[i] == filter) {
			this->filter_level = i;
		}
	}
}

Harl::~Harl() {}

void Harl::debug() {
	std::cout << "DEBUG : I love having extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info() {
	std::cout << "INFO : I cannot believe adding extra bacon costs more money. ";
	std::cout << "You didn't put enough bacon in my burger! ";
	std::cout << "If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning() {
	std::cout << "WARNING : I think I deserve to have some extra bacon for free. ";
	std::cout << "I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error() {
	std::cout << "ERROR : This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::quiet() {}

void Harl::gibberish() {
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

Harl::whine_f Harl::get_whine_function(std::string level) {
	std::string tab[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int level_n = 3;
	for (int i = 0; i < 4; i++) {
		if (tab[i] == level) {
			level_n = i;
		}
	}
	if (this->filter_level < 0 && level_n == 3) {
		return (&Harl::gibberish);
	}
	if (this->filter_level > level_n || this->filter_level < 0) {
		return (&Harl::quiet);
	}
	switch (level_n) {
		case 0:
			return (&Harl::debug);
		case 1:
			return (&Harl::info);
		case 2:
			return (&Harl::warning);
		case 3:
			return (&Harl::error);
	}
	return (&Harl::error);
}

void Harl::complain(std::string level) {
	whine_f action = get_whine_function(level);
	(this->*action)();
}
