#include <iostream>
using namespace std;

/* Implementation */
class Implementor abstract
{
public:
	virtual void Show() = 0;
};
/* Concrete implementation 1 */
class ConsoleOutput : public Implementor
{
	void Show() override
	{
		cout << "Console output of device: " << endl;
	}
};

/* Abstraction */
class IDevice abstract
{
protected:
	string name;
	string characteristics;
	Implementor* implementor;
public:
	virtual string GetName() { return name; }
	virtual void SetName() = 0;
	virtual string GetCharacteristics() { return characteristics; }
	virtual void SetCharacteristics() = 0;
	virtual void Show()
	{
		cout << "Name: " << name << endl;
		cout << "Characteristics: " << characteristics << endl;
	}
};
class VGA : public IDevice
{
public:
	void SetName()
	{
		name.append("NVIDIA");
	}
	void SetCharacteristics()
	{
		characteristics.append("GeForce GTX 1070");
	}
};
class CPU : public IDevice
{
public:
	void SetName()
	{
		name.append("Intel");
	}
	void SetCharacteristics()
	{
		characteristics.append("Core i7-4770K 3.50 GHz");
	}
};
class HDD : public IDevice
{
public:
	void SetName()
	{
		name.append("Hitachi");
	}
	void SetCharacteristics()
	{
		characteristics.append("2000 Gb");
	}
};
class RAM : public IDevice
{
public:
	void SetName()
	{
		name.append("RAM");
	}
	void SetCharacteristics()
	{
		characteristics.append("16 GB");
	}
};

/* client */
void Show(Implementor* i, IDevice* d)
{
	d->Show();
}


int main()
{
	IDevice* device = new VGA;
	device->SetName();
	device->SetCharacteristics();
	Implementor* implementor = new ConsoleOutput;
	Show(implementor, device);
	delete device;
	device = new CPU;
	device->SetName();
	device->SetCharacteristics();
	Show(implementor, device);
	delete device;
	device = new HDD;
	device->SetName();
	device->SetCharacteristics();
	Show(implementor, device);
	delete device;
	device = new RAM;
	device->SetName();
	device->SetCharacteristics();
	Show(implementor, device);
	delete device;
	delete implementor;

	return 0;
}