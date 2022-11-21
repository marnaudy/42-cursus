#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
	{
		std::cout << "Testing Bob the ScavTrap"<< std::endl;
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
	std::cout << std::endl;
	std::cout << std::endl;
	{
		std::cout << "Testing Billy the FragTrap"<< std::endl;
		FragTrap billy("Billy");
		billy.takeDamage(5);
		billy.attack("a fly");
		billy.beRepaired(2);
		billy.highFivesGuys();
		billy.setEnergyPoints(0);
		billy.attack("a fly");
		billy.beRepaired(2);

		std::cout << std::endl;
		std::cout << "Creating copy"<< std::endl;
		FragTrap billy2(billy);
		billy2.setName("Billy2");
		billy2.takeDamage(100);
		billy2.takeDamage(100);
		billy2.beRepaired(1);
		billy2.attack("a fly");
		billy2.highFivesGuys();
		billy2 = billy;
		billy2.setName("Billy2");
	}
}
