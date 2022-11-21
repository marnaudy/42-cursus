#ifndef SCAVTRAP_HPP
#	define SCAVTRAP_HPP

#	include <iostream>
#	include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(ScavTrap &other);
	ScavTrap &operator=(const ScavTrap &rhs);
	~ScavTrap();
	//Actions
	void attack(const std::string &target);
	void guardGate();
protected:
	static const int healthInit = 100;
	static const int energyInit = 50;
	static const int attackInit = 20;
};

#endif
