#include "ScavTrap.hpp"

int main() {
	ScavTrap bob("Bob");
	bob.takeDamage(5);
	bob.attack("a fly");
	bob.beRepaired(2);
	bob.guardGate();
	bob.setEnergyPoints(0);
	bob.attack("a fly");
	bob.beRepaired(2);

	std::cout << std::endl;
	std::cout << "Creating copy"<< std::endl;
	ScavTrap bob2(bob);
	bob2.setName("Bob2");
	bob2.takeDamage(100);
	bob2.takeDamage(100);
	bob2.beRepaired(1);
	bob2.attack("a fly");
	bob2.guardGate();
	bob2 = bob;
	bob2.setName("Bob2");
}
