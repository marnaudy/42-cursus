#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :
	_name("Bob"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default constructor called, ";
	std::cout << _name << " is born." << std::endl;
}

ClapTrap::ClapTrap(std::string name) :
	_name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Named constructor called, ";
	std::cout << _name << " is born." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &other) {
	*this = other;
	std::cout << "Copy constructor called, ";
	std::cout << _name << " is born." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs) {
	_name = rhs.getName();
	_hitPoints = rhs.getHitPoints();
	_energyPoints = rhs.getEnergyPoints();
	_attackDamage = rhs.getAttackDamage();
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called, ";
	std::cout << _name << " is no more." << std::endl;
}

//Accessors

std::string ClapTrap::getName() const {
	return (_name);
}

unsigned int ClapTrap::getHitPoints() const {
	return (_hitPoints);
}

unsigned int ClapTrap::getEnergyPoints() const {
	return (_energyPoints);
}

unsigned int ClapTrap::getAttackDamage() const {
	return (_attackDamage);
}

void ClapTrap::setName(std::string name) {
	_name = name;
}

void ClapTrap::setHitPoints(unsigned int n) {
	_hitPoints = n;
}

void ClapTrap::setEnergyPoints(unsigned int n) {
	_energyPoints = n;
}

void ClapTrap::setAttackDamage(unsigned int n) {
	_attackDamage = n;
}

//Actions

void ClapTrap::attack(const std::string &target) {
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name;
		std::cout << " can't attack, it is dead" << std::endl;
		return;
	}
	if (_energyPoints == 0) {
		std::cout << "ClapTrap " << _name;
		std::cout << " doesn't have any energy to attack ";
		std::cout << target << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name;
	std::cout << " attacks " << target;
	std::cout << ", causing " << _attackDamage;
	std::cout << " points of damage !" << std::endl;
	_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name;
		std::cout << " can't take damage, it is already dead" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name;
	std::cout << " takes " << amount << " points of damage" << std::endl;
	if (amount > _hitPoints) {
		std::cout << "ClapTrap " << _name;
		std::cout << " has died" << std::endl;
		_hitPoints = 0;
	} else {
		_hitPoints -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name;
		std::cout << " can't repair itself, it is dead" << std::endl;
		return;
	}
	if (_energyPoints == 0) {
		std::cout << "ClapTrap " << _name;
		std::cout << " doesn't have any energy to repair itself" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name;
	std::cout << " repairs " << amount;
	std::cout << " hitpoints" << std::endl;
	_hitPoints += amount;
	_energyPoints--;
}

