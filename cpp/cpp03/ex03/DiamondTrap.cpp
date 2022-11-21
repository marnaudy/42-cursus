#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() :
	ClapTrap("Bob_clap_name",
		FragTrap::healthInit,
		ScavTrap::energyInit,
		FragTrap::attackInit),
	_name("Bob")
{
	std::cout << "Default DiamondTrap constructor called : ";
	std::cout << _name << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) :
	ClapTrap(name + "_clap_name",
		FragTrap::healthInit,
		ScavTrap::energyInit,
		FragTrap::attackInit),
	_name(name)
{
	std::cout << "DiamondTrap named constructor called : ";
	std::cout << _name << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap &other) :
	ClapTrap(other),
	ScavTrap(),
	FragTrap()
{
	*this = other;
	std::cout << "DiamondTrap copy constructor called : ";
	std::cout << _name << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs) {
	ClapTrap::operator=(rhs);
	_name = rhs.getName();
	return (*this);
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called : ";
	std::cout << _name << std::endl;
}

//Accessors

std::string DiamondTrap::getName() const {
	return (_name);
}

void DiamondTrap::setName(std::string name) {
	_name = name;
	ClapTrap::setName(name + "_clap_name");
}

//Actions

void DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	std::cout << "I am DiamondTrap " << _name << std::endl;
	std::cout << "Also know as ClapTrap " << ClapTrap::getName();
	std::cout << std::endl;
}
