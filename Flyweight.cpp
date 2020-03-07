#include <iostream>
#include <map>
using namespace std;

/* Flyweight */
class Troop abstract
{
protected:
	int speed;
	int power;
public:
	virtual void Show(double longitude, double latitude) = 0;
};
 /* Concrete flyweight */
class Infantry :public Troop
{
public:
	Infantry()
	{
		speed = 20;
		power = 10;
	}
	void Show(double longitude, double latitude) override
	{
		char buffer[100];
		sprintf_s(buffer, "Infantry; \ncoordinates: %f - latitude   %f - longitude", latitude, longitude);
		cout << buffer << endl;
	}
};
class TransportVehicles :public Troop
{
public:
	TransportVehicles()
	{
		speed = 70;
		power = 0;
	}
	void Show(double longitude, double latitude) override
	{
		char buffer[100];
		sprintf_s(buffer, "Transport Vehicles; \ncoordinates: %f - latitude   %f - longitude", 
			latitude, longitude);
		cout << buffer << endl;
	}
};
class HeavyGroundMilitaryEquipment :public Troop
{
public:
	HeavyGroundMilitaryEquipment()
	{
		speed = 15;
		power = 150;
	}
	void Show(double longitude, double latitude) override
	{
		char buffer[100];
		sprintf_s(buffer, "Heavy Ground Military Equipment; \ncoordinates: %f - latitude   %f - longitude",
			latitude, longitude);
		cout << buffer << endl;
	}
};
class LightGroundCombatEquipment :public Troop
{
public:
	LightGroundCombatEquipment()
	{
		speed = 15;
		power = 150;
	}
	void Show(double longitude, double latitude) override
	{
		char buffer[100];
		sprintf_s(buffer, "Light ground combat equipment; \ncoordinates: %f - latitude   %f - longitude",
			latitude, longitude);
		cout << buffer << endl;
	}
};
class Aircraft :public Troop
{
public:
	Aircraft()
	{
		speed = 15;
		power = 150;
	}
	void Show(double longitude, double latitude) override
	{
		char buffer[100];
		sprintf_s(buffer, "Aircraft; \ncoordinates: %f - latitude   %f - longitude",
			latitude, longitude);
		cout << buffer << endl;
	}
};

class TroopFactory
{
	map<string, Troop*> troops;
public:
	TroopFactory()
	{
		troops["Infantry"] = new Infantry();
		troops["Transport Vehicles"] = new TransportVehicles();
		troops["Heavy Ground Military Equipment"] = new HeavyGroundMilitaryEquipment();
		troops["Light Ground Combat Equipment"] = new LightGroundCombatEquipment();
		troops["Aircraft"] = new Aircraft();
	}
	~TroopFactory()
	{
		delete troops["Infantry"];
		delete troops["Transport Vehicles"];
		delete troops["Heavy Ground Military Equipment"];
		delete troops["Light Ground Combat Equipment"];
		delete troops["Aircraft"];
		troops.clear();
	}
	Troop* GetTroop(string key)
	{
		if (troops[key] != nullptr)
			return troops[key];
		else
			return nullptr;
	}
};

int main()
{
	double longitude = 37.61;
	double latitude = 55.74;

	TroopFactory* troopFactory = new TroopFactory();

	for (int i = 0; i < 5; i++)
	{
		Troop* Infantry = troopFactory->GetTroop("Infantry");
		if (Infantry != nullptr)
			Infantry->Show(longitude, latitude);
		longitude += 0.1;
		latitude += 0.1;
	}
	for (int i = 0; i < 5; i++)
	{
		Troop* TransportVehicles = troopFactory->GetTroop("Transport Vehicles");
		if (TransportVehicles != nullptr)
			TransportVehicles->Show(longitude, latitude);
		longitude += 0.1;
		latitude += 0.1;
	}
	for (int i = 0; i < 5; i++)
	{
		Troop* HeavyGroundMilitaryEquipment = troopFactory->GetTroop("Heavy Ground Military Equipment");
		if (HeavyGroundMilitaryEquipment != nullptr)
			HeavyGroundMilitaryEquipment->Show(longitude, latitude);
		longitude += 0.1;
		latitude += 0.1;
	}
	for (int i = 0; i < 5; i++)
	{
		Troop* LightGroundCombatEquipment = troopFactory->GetTroop("Light Ground Combat Equipment");
		if (LightGroundCombatEquipment != nullptr)
			LightGroundCombatEquipment->Show(longitude, latitude);
		longitude += 0.1;
		latitude += 0.1;
	}
	for (int i = 0; i < 5; i++)
	{
		Troop* Aircraft = troopFactory->GetTroop("Aircraft");
		if (Aircraft != nullptr)
			Aircraft->Show(longitude, latitude);
		longitude += 0.1;
		latitude += 0.1;
	}
	delete troopFactory;

	return 0;
}