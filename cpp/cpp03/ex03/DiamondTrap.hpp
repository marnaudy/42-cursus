#ifndef DIAMONDTRAP_HPP
#	define DIAMONDTRAP_HPP

#	include <iostream>
#	include "ScavTrap.hpp"
#	include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(DiamondTrap &other);
	DiamondTrap &operator=(const DiamondTrap &rhs);
	~DiamondTrap();
	//Accessors
	std::string getName() const;
	void setName(std::string name);
	//Actions
	void attack(const std::string &target);
	void whoAmI();
private:
	std::string _name;
};

#endif
