#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	{
		IMateriaSource* src = new MateriaSource();
		src.learnMateria(new Ice());
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
		me2.unequip(0);
		me2.unequip(1);
		me.use(0, bob);
		me.use(1, bob);
		
		MateriaSource src2 = src;
		src.learnMateria(new Cure());
		tmp = src.createMateria("cure");
		me.equip(tmp);
		me.use(1, bob);

		std::cout << std::endl;
		std::cout << "Filling inventories and templates"		
	}
}
