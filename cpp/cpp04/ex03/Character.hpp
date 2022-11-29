#ifndef CHARACTER_HPP
#	define CHARACTER_HPP

#	include <string>
#	include "AMateria.hpp"
#	include "ICharacter.hpp"

class Character : public ICharacter {
private:
	AMateria *_inventory[4];
	std::string _name;
public:
	Character();
	Character(const std::string &name);
	Character(const Character &other);
	Character &operator=(const Character &rhs);
	virtual ~Character();

	virtual std::string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
};

#endif
