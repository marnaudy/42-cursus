#ifndef FRAGTRAP_HPP
#	define FRAGTRAP_HPP

#	include <iostream>
#	include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(FragTrap &other);
	FragTrap &operator=(const FragTrap &rhs);
	~FragTrap();
	//Actions
	void attack(const std::string &target);
	void highFivesGuys();
private:
	static const int healthInit = 100;
	static const int energyInit = 100;
	static const int attackInit = 30;
};

#endif
