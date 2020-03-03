#include <iostream>
using namespace std;

class IProfession abstract
{
protected:
	string name;
	int attack;
	int speed;
	int health;
	int armour;
public:
	IProfession(string n)
	{
		name = n;
	}
	string GetName()
	{
		return name;
	}
	virtual int GetAttack() = 0;
	virtual int GetSpeed() = 0;
	virtual int GetHealth() = 0;
	virtual int GetArmour() = 0;
};
class Human : public IProfession
{
public:
	Human() :IProfession("Human") {};
	int GetAttack() override
	{
		return 20;
	}
	int GetSpeed() override
	{
		return 20;
	}
	int GetHealth() override
	{
		return 150;
	}
	int GetArmour() override
	{
		return 0;
	}
};
class Elf : public IProfession
{
public:
	Elf() :IProfession("Elf") {};
	int GetAttack() override
	{
		return 15;
	}
	int GetSpeed() override
	{
		return 30;
	}
	int GetHealth() override
	{
		return 100;
	}
	int GetArmour() override
	{
		return 0;
	}
};
class ProfessionDecorator abstract : public IProfession
{
protected:
	IProfession* profession;
public:
	ProfessionDecorator(IProfession* profession, string n) : IProfession(n)
	{
		this->profession = profession;
	}
};
class HumanWarrior : public ProfessionDecorator
{
public:
	HumanWarrior(IProfession* ip) :ProfessionDecorator(ip, ip->GetName() + " Warrior") {};
	int GetAttack() override
	{
		return profession->GetAttack() + 20;
	}
	int GetSpeed() override
	{
		return profession->GetSpeed() + 10;
	}
	int GetHealth() override
	{
		return profession->GetHealth() + 50;
	}
	int GetArmour() override
	{
		return profession->GetArmour() + 20;
	}
};
class Swordsman : public ProfessionDecorator
{
public:
	Swordsman(IProfession* ip) :ProfessionDecorator(ip, "Swordsman") {};
	int GetAttack() override
	{
		return profession->GetAttack() + 40;
	}
	int GetSpeed() override
	{
		return profession->GetSpeed() - 10;
	}
	int GetHealth() override
	{
		return profession->GetHealth() + 50;
	}
	int GetArmour() override
	{
		return profession->GetArmour() + 40;
	}
};
class Archer : public ProfessionDecorator
{
public:
	Archer(IProfession* ip) :ProfessionDecorator(ip, "Archer") {};
	int GetAttack() override
	{
		return profession->GetAttack() + 20;
	}
	int GetSpeed() override
	{
		return profession->GetSpeed() + 20;
	}
	int GetHealth() override
	{
		return profession->GetHealth() + 50;
	}
	int GetArmour() override
	{
		return profession->GetArmour() + 10;
	}
};
class Horseman : public ProfessionDecorator
{
public:
	Horseman(IProfession* ip) :ProfessionDecorator(ip, "Horseman") {};
	int GetAttack() override
	{
		return profession->GetAttack() - 10;
	}
	int GetSpeed() override
	{
		return profession->GetSpeed() + 40;
	}
	int GetHealth() override
	{
		return profession->GetHealth() + 200;
	}
	int GetArmour() override
	{
		return profession->GetArmour() + 100;
	}
};
class ElfWarrior : public ProfessionDecorator
{
public:
	ElfWarrior(IProfession* ip) :ProfessionDecorator(ip, "Elf Warrior") {};
	int GetAttack() override
	{
		return profession->GetAttack() + 20;
	}
	int GetSpeed() override
	{
		return profession->GetSpeed() - 10;
	}
	int GetHealth() override
	{
		return profession->GetHealth() + 100;
	}
	int GetArmour() override
	{
		return profession->GetArmour() + 20;
	}
};
class ElfWizard : public ProfessionDecorator
{
public:
	ElfWizard(IProfession* ip) :ProfessionDecorator(ip, "Elf Wizard") {};
	int GetAttack() override
	{
		return profession->GetAttack() + 10;
	}
	int GetSpeed() override
	{
		return profession->GetSpeed() + 10;
	}
	int GetHealth() override
	{
		return profession->GetHealth() - 50;
	}
	int GetArmour() override
	{
		return profession->GetArmour() + 10;
	}
};
class CrossBowMan : public ProfessionDecorator
{
public:
	CrossBowMan(IProfession* ip) :ProfessionDecorator(ip, "Crossbow Man") {};
	int GetAttack() override
	{
		return profession->GetAttack() + 20;
	}
	int GetSpeed() override
	{
		return profession->GetSpeed() + 10;
	}
	int GetHealth() override
	{
		return profession->GetHealth() + 50;
	}
	int GetArmour() override
	{
		return profession->GetArmour() - 10;
	}
};
class EvilWizard : public ProfessionDecorator
{
public:
	EvilWizard(IProfession* ip) :ProfessionDecorator(ip, "Evil Wizard") {};
	int GetAttack() override
	{
		return profession->GetAttack() + 70;
	}
	int GetSpeed() override
	{
		return profession->GetSpeed() + 20;
	}
	int GetHealth() override
	{
		return profession->GetHealth() + 0;
	}
	int GetArmour() override
	{
		return profession->GetArmour() + 0;
	}
};
class GoodWizard : public ProfessionDecorator
{
public:
	GoodWizard(IProfession* ip) :ProfessionDecorator(ip, "Good Wizard") {};
	int GetAttack() override
	{
		return profession->GetAttack() + 50;
	}
	int GetSpeed() override
	{
		return profession->GetSpeed() + 30;
	}
	int GetHealth() override
	{
		return profession->GetHealth() + 100;
	}
	int GetArmour() override
	{
		return profession->GetArmour() + 30;
	}
};

void client(IProfession* ip)
{
	cout << "Name: " << ip->GetName() << endl << "Attack: " << ip->GetAttack() << endl 
		<< "Speed: " << ip->GetSpeed() << endl << "Health: " << ip->GetHealth() << endl 
		<< "Armour: " << ip->GetArmour() << endl;
}

int main()
{
	//IProfession* ip = new Human();
	//client(ip);
	//ip = new HumanWarrior(ip);
	//client(ip);
	//ip = new Swordsman(ip);
	//client(ip);
	//ip = new Horseman(ip);
	//client(ip); /*ip = new Archer(ip); client(ip);*/
	//delete ip;
	IProfession* ip = new Elf();
	client(ip);
	/*ip = new ElfWarrior(ip);
	client(ip);*/
	ip = new ElfWizard(ip);
	client(ip);
	/*ip = new CrossBowMan(ip);
	client(ip);*/
	/*ip = new EvilWizard(ip);
	client(ip);*/
	ip = new GoodWizard(ip);
	client(ip);

	return 0;
}