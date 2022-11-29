#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++) {
		_templates[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &other) {
	*this = other;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs) {
	for (int i = 0; i < 4; i++) {
		delete _templates[i];
		if (rhs._templates[i] == NULL) {
			_templates[i] = NULL;
		} else {
			_templates[i] = rhs._templates[i]->clone();
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		delete _templates[i];
	}
}

void MateriaSource::learnMateria(AMateria *m) {
	for (int i = 0; i < 4; i++) {
		if (_templates[i] == NULL) {
			_templates[i] = m;
			return;
		}
	}
}

AMateria *MateriaSource::createMateria(const std::string &type) {
	for (int i = 0; i < 4; i++) {
		if (_templates[i] != NULL && _templates[i]->getType() == type) {
			return (_templates[i]->clone());
		}
	}
	return (NULL);
}
