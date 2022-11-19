#include "ClapTrap.hpp"

int main() {
	ClapTrap bob("Bob");
	bob.takeDamage(5);
	bob.attack("a fly");
	bob.beRepaired(2);
	for (int i = 0; i < 9; i++) {
		bob.attack("a fly");
	}
	bob.beRepaired(1);
	bob.takeDamage(10);
	bob.takeDamage(10);
	bob.beRepaired(1);
	bob.attack("a fly");

	std::cout << std::endl;
	std::cout << "Creating copy"<< std::endl;
	ClapTrap bob2(bob);
	bob2.setName("Bob2");
	bob2.takeDamage(10);
	bob2.beRepaired(1);
	bob2.attack("a fly");
}
