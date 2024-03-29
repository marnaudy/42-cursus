#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		me->use(5, *bob);
		me->unequip(5);
		
		delete bob;
		delete me;
		delete src;
	}
	{
		std::cout << std::endl;
		std::cout << "Testing character copy" << std::endl;
		MateriaSource src = MateriaSource();
		src.learnMateria(new Ice());
		Character me = Character("me");
		AMateria* tmp;
		tmp = src.createMateria("ice");
		me.equip(tmp);
		tmp = src.createMateria("cure");
		me.equip(tmp);
		Character bob = Character("bob");
		me.use(0, bob);
		me.use(1, bob);

		Character me2 = Character(me);
		tmp = src.createMateria("ice");
		me2.equip(tmp);
		me.use(0, bob);
		me.use(1, bob);
		me2.unequip(1);
		delete tmp;
		
		MateriaSource src2 = src;
		src.learnMateria(new Cure());
		tmp = src.createMateria("cure");
		me.equip(tmp);
		me.use(1, bob);

		std::cout << std::endl;
		std::cout << "Filling inventories and templates" << std::endl;
		tmp = src.createMateria("cure");
		me.equip(tmp);
		tmp = src.createMateria("cure");
		me.equip(tmp);
		tmp = src.createMateria("cure");
		me.equip(tmp);
		delete tmp;

	}
}
