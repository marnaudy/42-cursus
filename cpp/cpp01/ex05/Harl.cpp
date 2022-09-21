#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug() {
	std::cout << "I love having extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info() {
	std::cout << "I cannot believe adding extra bacon costs more money. ";
	std::cout << "You didn't put enough bacon in my burger! ";
	std::cout << "If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning() {
	std::cout << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error() {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

Harl::whine_f Harl::get_whine_function(std::string level) {
	std::string tab[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int level_n = -1;
	for (int i = 0; i < 4; i++) {
		if (tab[i] == level) {
			level_n = i;
		}
	}
	switch (level_n) {
		case 0:
			return (&Harl::debug);
		case 1:
			return (&Harl::info);
		case 2:
			return (&Harl::warning);
		default:
			return (&Harl::error);
	}
}

void Harl::complain(std::string level) {
	whine_f action = get_whine_function(level);
	(this->*action)();
}
