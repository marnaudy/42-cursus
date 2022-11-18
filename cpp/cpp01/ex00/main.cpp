#include "Zombie.hpp"

void randomChump(std::string name);
Zombie *newZombie(std::string name);

int main() {
	std::cout << "Creating zombie on stack" << std::endl;
	randomChump("Stack");
	std::cout << "Creating zombie on heap" << std::endl;
	Zombie *myZombie = newZombie("Heap");
	myZombie->announce();
	std::cout << "Freeing heap memory" << std::endl;
	delete myZombie;
}
