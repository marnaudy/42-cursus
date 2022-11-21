#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
	{
		std::cout << "Testing Bob the ScavTrap"<< std::endl;
		ScavTrap bob("Bob");
		bob.takeDamage(5);
		bob.attack("a fly");
		bob.beRepaired(2);
		bob.guardGate();
		bob.spendEnergy(100);
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
		billy.spendEnergy(100);
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
	std::cout << std::endl;
	std::cout << std::endl;
	{
		std::cout << "Testing Brandon the DiamondTrap"<< std::endl;
		DiamondTrap brandon("Brandon");
		brandon.takeDamage(5);
		brandon.attack("a fly");
		brandon.beRepaired(2);
		brandon.guardGate();
		brandon.highFivesGuys();
		brandon.spendEnergy(100);
		brandon.attack("a fly");
		brandon.beRepaired(2);

		std::cout << std::endl;
		std::cout << "Creating copy"<< std::endl;
		DiamondTrap brandon2(brandon);
		brandon2.setName("Brandon2");
		brandon2.takeDamage(100);
		brandon2.takeDamage(100);
		brandon2.beRepaired(1);
		brandon2.attack("a fly");
		brandon2.guardGate();
		brandon2.highFivesGuys();
		brandon2 = brandon;
		brandon2.setName("Brandon2");
	}
}
