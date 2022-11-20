#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : 
	ClapTrap("Bob", healthInit, energyInit, attackInit)
{
	std::cout << "Default ScavTrap constructor called : ";
	std::cout << ClapTrap::getName() << std::endl;
}

ScavTrap::ScavTrap(std::string name) : 
	ClapTrap(name, healthInit, energyInit, attackInit)
{
	std::cout << "ScavTrap named constructor called : ";
	std::cout << ClapTrap::getName() << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &other) : ClapTrap(other) {
	*this = other;
	std::cout << "ScavTrap copy constructor called : ";
	std::cout << ClapTrap::getName() << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs) {
	ClapTrap::operator=(rhs);
	return (*this);
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called : ";
	std::cout << ClapTrap::getName() << std::endl;
}

//Actions

void ScavTrap::attack(const std::string &target) {
	if (ClapTrap::getHitPoints() == 0) {
		std::cout << "ScavTrap " << ClapTrap::getName();
		std::cout << " can't attack, it is dead" << std::endl;
		return;
	}
	if (ClapTrap::getEnergyPoints() == 0) {
		std::cout << "ScavTrap " << ClapTrap::getName();
		std::cout << " doesn't have any energy to attack ";
		std::cout << target << std::endl;
		return;
	}
	std::cout << "ScavTrap " << ClapTrap::getName();
	std::cout << " deals a huge blow to " << target;
	std::cout << ", causing " << ClapTrap::getAttackDamage();
	std::cout << " points of damage !" << std::endl;
	ClapTrap::spendEnergy(1);
}

void ScavTrap::guardGate() {
	if (ClapTrap::getHitPoints() == 0) {
		std::cout << "ScavTrap " << ClapTrap::getName();
		std::cout << " can't guard the gate, it is dead" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << ClapTrap::getName();
	std::cout << " is in gate keeper mode" << std::endl; 
}
