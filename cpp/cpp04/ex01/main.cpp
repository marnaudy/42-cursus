#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	{
		std::cout << "Testing make sound method and virtual destructors";
		std::cout << std::endl;
		Animal *array[4];
		array[0] = new Cat;
		array[1] = new Dog;
		array[2] = new Cat;
		array[3] = new Dog;

		for (int i = 0; i < 4; i++) {
			array[i]->makeSound();
			delete array[i];
		}
	}
	{
		std::cout << std::endl;
		std::cout << "Testing copies" << std::endl;
		Cat cat1;
		cat1.newIdea("I'm hungry");
		Cat cat2(cat1);
		cat1.clearBrain();
		cat2.displayIdeas();
		Dog dog1;
		dog1.newIdea("I'm hungry");
		dog1.newIdea("Woof");
		Dog dog2(dog1);
		dog1.clearBrain();
		dog2.displayIdeas();
	}
}
