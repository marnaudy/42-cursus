#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main() {
	std::cout << "Size 10" << std::endl;
	Zombie *horde = zombieHorde(10, "Shaun");
	for (int i = 0; i < 10; i++) {
		horde[i].announce();
	}
	delete[] horde;
	std::cout << "Size 1" << std::endl;
	horde = zombieHorde(1, "Shaun");
	for (int i = 0; i < 1; i++) {
		horde[i].announce();
	}
	delete[] horde;
	std::cout << "Size 0" << std::endl;
	horde = zombieHorde(0, "Shaun");
	for (int i = 0; i < 0; i++) {
		horde[i].announce();
	}
	delete[] horde;
	std::cout << "Size -1" << std::endl;
	horde = zombieHorde(-1, "Shaun");
	std::cout << "Horde pointer = " << horde << std::endl;
	for (int i = 0; i < -1; i++) {
		horde[i].announce();
	}
	delete[] horde;
}
