#ifndef ZOMBIE_HPP
#	define ZOMBIE_HPP
#	include <string>
#	include <iostream>

class Zombie {
public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void set_name(std::string);
	std::string get_name();
	void announce();
private:
	std::string name;
};


#endif
