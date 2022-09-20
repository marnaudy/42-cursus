#include "Zombie.hpp"

 Zombie* zombieHorde(int N, std::string name);

int main() {
	Zombie *horde = zombieHorde(10, "Shaun");
	for (int i = 0; i < 10; i++) {
		horde[i].announce();
	}
	delete[] horde;
}
