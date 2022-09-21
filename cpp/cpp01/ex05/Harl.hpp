#ifndef HARL_HPP
#	define HARL_HPP

#	include <iostream>
#	include <string>

class Harl {
public:
typedef void(Harl::*whine_f)();
	Harl();
	~Harl();
	void complain(std::string level);
private:
	void debug();
	void info();
	void warning();
	void error();
	Harl::whine_f get_whine_function(std::string level);
};


#endif
