 #include "Zombie.hpp"

 Zombie* zombieHorde(int N, std::string name) {
	Zombie *zombieArray = new Zombie[N];
	for (int i = 0; i < N; i++) {
		zombieArray[i].set_name(name);
	}
	return (zombieArray);
 }
