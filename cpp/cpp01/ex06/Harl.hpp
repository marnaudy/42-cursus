#ifndef HARL_HPP
#	define HARL_HPP

#	include <iostream>
#	include <string>

class Harl {
public:
	typedef void(Harl::*whine_f)();
	Harl();
	Harl(std::string filter);
	~Harl();
	void complain(std::string level);
private:
	int filter_level;
	void debug();
	void info();
	void warning();
	void error();
	void quiet();
	void gibberish();
	Harl::whine_f get_whine_function(std::string level);
};


#endif
