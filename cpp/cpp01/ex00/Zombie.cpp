#include "Zombie.hpp"

Zombie::Zombie() : name("Shaun") {}

Zombie::Zombie(std::string name) : name(name) {}

Zombie::~Zombie() {
	std::cout << this->name << ": *dies*" << std::endl;
}

void Zombie::set_name(std::string name) {
	this->name = name;
}

std::string Zombie::get_name() {
	return (this->name);
}

void Zombie::announce() {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
