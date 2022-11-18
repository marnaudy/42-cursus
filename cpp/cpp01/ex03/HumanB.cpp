#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL) {}

HumanB::~HumanB() {}

void HumanB::attack() {
	if (this->weapon != NULL) {
		std::cout << this->name << " attacks with their ";
		std::cout << this->weapon->getType() << std::endl;
	}
}

void HumanB::setWeapon(Weapon &newWeapon) {
	this->weapon = &newWeapon;
}
