#include "Character.hpp"

Character::Character() : _name("Default") {
	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
}

Character::Character(const std::string &name) : _name(name) {
	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
}

Character::Character(const Character &other) {
	*this = other;
}

Character &Character::operator=(const Character &rhs) {
	_name = rhs._name;
	for (int i = 0; i < 4; i++) {
		delete _inventory[i];
		if (rhs._inventory[i] == NULL) {
			_inventory[i] = NULL;
		} else {
			_inventory[i] = rhs._inventory[i]->clone();
		}
	}
	return (*this);
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		delete _inventory[i];
	}
}

const std::string &Character::getName() const {
	return (_name);
}

void Character::equip(AMateria *m) {
	for (int i = 0; i < 4; i++)	{
		if (_inventory[i] == NULL) {
			_inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx) {
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
	if (_inventory[idx] != NULL) {
		_inventory[idx]->use(target);
	}
}
