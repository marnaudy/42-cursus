#include "FragTrap.hpp"

FragTrap::FragTrap() :
	ClapTrap("Bob", healthInit, energyInit, attackInit)
{
	std::cout << "Default FragTrap constructor called : ";
	std::cout << ClapTrap::getName() << std::endl;
}

FragTrap::FragTrap(std::string name) :
	ClapTrap(name, healthInit, energyInit, attackInit)
{
	std::cout << "FragTrap named constructor called : ";
	std::cout << ClapTrap::getName() << std::endl;
}

FragTrap::FragTrap(FragTrap &other) : ClapTrap(other) {
	*this = other;
	std::cout << "FragTrap copy constructor called : ";
	std::cout << ClapTrap::getName() << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs) {
	ClapTrap::operator=(rhs);
	return (*this);
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called : ";
	std::cout << ClapTrap::getName() << std::endl;
}

//Actions

void FragTrap::attack(const std::string &target) {
	if (ClapTrap::getHitPoints() == 0) {
		std::cout << "FragTrap " << ClapTrap::getName();
		std::cout << " can't attack, it is dead" << std::endl;
		return;
	}
	if (ClapTrap::getEnergyPoints() == 0) {
		std::cout << "FragTrap " << ClapTrap::getName();
		std::cout << " doesn't have any energy to attack ";
		std::cout << target << std::endl;
		return;
	}
	std::cout << "FragTrap " << ClapTrap::getName();
	std::cout << " aggressively high-fives " << target;
	std::cout << ", causing " << ClapTrap::getAttackDamage();
	std::cout << " points of damage !" << std::endl;
	ClapTrap::setEnergyPoints(ClapTrap::getEnergyPoints() - 1);
}

void FragTrap::highFivesGuys() {
	if (ClapTrap::getHitPoints() == 0) {
		std::cout << "FragTrap " << ClapTrap::getName();
		std::cout << " can't ask for high fives, it is dead" << std::endl;
		return;
	}
	std::cout << "FragTrap " << ClapTrap::getName();
	std::cout << " requests high fives" << std::endl; 
}
