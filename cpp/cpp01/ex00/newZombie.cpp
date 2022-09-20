#include "Zombie.hpp"

Zombie *newZombie(std::string name) {
	Zombie *myZombie = new Zombie(name);
	myZombie->announce();
	return (myZombie);
}
