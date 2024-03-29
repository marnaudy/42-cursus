#ifndef CLAPTRAP_HPP
#	define CLAPTRAP_HPP

#	include <iostream>

class ClapTrap {
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &rhs);
	~ClapTrap();
	//Accessors
	std::string getName() const;
	unsigned int getHitPoints() const;
	unsigned int getEnergyPoints() const;
	unsigned int getAttackDamage() const;
	void setName(std::string name);
	void setHitPoints(unsigned int n);
	void setEnergyPoints(unsigned int n);
	void setAttackDamage(unsigned int n);
	//Actions
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
private:
	std::string _name;
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _attackDamage;
	static const int healthInit = 10;
	static const int energyInit = 10;
	static const int attackInit = 0;
};

#endif
