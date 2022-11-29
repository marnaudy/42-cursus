#ifndef CURE_HPP
#	define CURE_HPP

#	include "AMateria.hpp"

class Cure : public AMateria {
public:
	Cure();
	Cure(const Cure &other);
	virtual Cure &operator=(const Cure &rhs);
	virtual ~Cure();

	virtual AMateria* clone() const;
	virtual void use(ICharacter &target);
};

#endif
