#include <iostream>
using namespace std;

/* product A */
class Herbivore
{
public:
	virtual void EatGrass() = 0;
};

/* concrete product A1 */
class Wildebeest : public Herbivore
{
public:
	void EatGrass()
	{
		cout << "Wildebeest eats grass" << endl;
	}
};

/* concrete product A2 */
class Bison : public Herbivore
{
public:
	void EatGrass()
	{
		cout << "Bison eats grass" << endl;
	}
};

/* product B */
class Carnivore
{
public:
	virtual void Eat() = 0;
};

/* concrete product B1 */
class Lion : public Carnivore
{
public:
	void Eat()
	{
		cout << "Lion eats herbivore" << endl;
	}
};

/* concrete product B2 */
class Wolf : public Carnivore
{
public:
	void Eat()
	{
		cout << "Wolf eats herbivore" << endl;
	}
};

/* interface - abstract factory */
class Continent abstract
{
public:
	virtual Herbivore* CreateHerbivore() = 0;
	virtual Carnivore* CreateCarnivore() = 0;
};

/* concrete factory 1 */
class Africa : public Continent
{
	Herbivore* CreateHerbivore()
	{
		return new Wildebeest;
	}
	Carnivore* CreateCarnivore()
	{
		return new Lion;
	}
};

/* concrete factory 2 */
class NorthAmerica : public Continent
{
	Herbivore* CreateHerbivore()
	{
		return new Bison;
	}
	Carnivore* CreateCarnivore()
	{
		return new Wolf;
	}
};

class Client
{
	Continent* continent;
public:
	void ClientCode(Continent* continent)
	{
		continent->CreateCarnivore()->Eat();
		continent->CreateHerbivore()->EatGrass();
	}
};

int main()
{
	Client cl;
	Continent* cont = new Africa;
	cl.ClientCode(cont);
	/*delete cont;
	Continent* cont = new NorthAmerica;
	cl.ClientCode(cont);*/

	return 0;
}