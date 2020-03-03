#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

class GraphicCard
{
public:
	void Launch()
	{
		cout << "Graphic Card launched!" << endl;
		Sleep(1000);
	}
	void CheckMonitorSync()
	{
		cout << "Graphic Card is synchronized with monitor!" << endl;
		Sleep(1000);
	}
	void ShowRAMData()
	{
		cout << "RAM Data:" << endl
			<< "DIMM2: Kingston 99U5471-054.A00LF" << endl 
			<< "DIMM3: Kingston 99U5471-054.A00LF" << endl;
		Sleep(1000);
	}
	void ShowHDDData()
	{
		cout << "HDD Data:" << endl
			<< "Hitachi HDS5C3020ALA632 (1863 GB)" << endl;
		Sleep(1000);
	}
	void CloseMessage()
	{
		cout << "Goodbye! See you soon!" << endl;
		Sleep(1000);
	}
};
class RAM
{
public:
	void LaunchDevices()
	{
		cout << "Devices are launched" << endl;
		Sleep(1000);
	}
	void MemoryAnalysis()
	{
		cout << "Memory Analysis is done!" << endl;
		Sleep(1000);
	}
	void ClearMemory()
	{
		cout << "Memory is cleaned!" << endl;
		Sleep(1000);
	}
};
class HDD
{
public:
	void Launch()
	{
		cout << "HDD is launched!" << endl;
		Sleep(1000);
	}
	void BootSectorCheck()
	{
		cout << "Boot sector is checked!" << endl;
		Sleep(1000);
	}
	void StopDevice()
	{
		cout << "HDD is stopped!" << endl;
		Sleep(1000);
	}
};
class Power
{
public:
	void PowerUp()
	{
		cout << "Powered up!" << endl;
		Sleep(1000);
	}
	void PowerUpGraphicCard()
	{
		cout << "Graphic Card is powered up!" << endl;
		Sleep(1000);
	}
	void PowerUpRAM()
	{
		cout << "RAM is powered up!" << endl;
		Sleep(1000);
	}
	void PowerUpHDD()
	{
		cout << "HDD is powered up!" << endl;
		Sleep(1000);
	}
	void StopGraphicCard()
	{
		cout << "Graphic Card is stopped!" << endl;
		Sleep(1000);
	}
	void StopRAM()
	{
		cout << "RAM is stopped!" << endl;
		Sleep(1000);
	}
	void StopHDD()
	{
		cout << "HDD is stopped!" << endl;
		Sleep(1000);
	}
	void PowerDown()
	{
		cout << "Powered down!" << endl;
		Sleep(1000);
	}
};
class Sensors
{
public:
	void CheckVoltage()
	{
		cout << "Voltage is checked!" << endl;
		Sleep(1000);
	}
	void CheckTemperatureOnPowerSupply()
	{
		cout << "Temperature on Power Supply is checked!" << endl;
		Sleep(1000);
	}
	void CheckTemperatureOnGraphicCard()
	{
		cout << "Temperature on Graphic Card is checked!" << endl;
		Sleep(1000);
	}
	void CheckTemperatureOnRAM()
	{
		cout << "Temperature on RAM is checked!" << endl;
		Sleep(1000);
	}
	void CheckWholeTemperature()
	{
		cout << "Whole system temperature is checked!" << endl;
		Sleep(1000);
	}
};

class Facade
{
	GraphicCard graphicCard;
	RAM ram;
	HDD hdd;
	Power power;
	Sensors sensors;
public:
	void BeginWork()
	{
		cout << "Beginning work..." << endl;
		Sleep(2000);
		power.PowerUp();
		sensors.CheckVoltage();
		sensors.CheckTemperatureOnPowerSupply();
		sensors.CheckTemperatureOnGraphicCard();
		power.PowerUpGraphicCard();
		graphicCard.Launch();
		graphicCard.CheckMonitorSync();
		sensors.CheckTemperatureOnRAM();
		power.PowerUpRAM();
		ram.LaunchDevices();
		ram.MemoryAnalysis();
		graphicCard.ShowRAMData();
		power.PowerUpHDD();
		hdd.Launch();
		hdd.BootSectorCheck();
		graphicCard.ShowHDDData();
		sensors.CheckWholeTemperature();
	}
	void EndWork() 
	{
		cout << "Ending work..." << endl;
		Sleep(2000);
		hdd.StopDevice();
		ram.ClearMemory();
		ram.MemoryAnalysis();
		graphicCard.CloseMessage();
		power.StopGraphicCard();
		power.StopRAM();
		power.StopHDD();
		sensors.CheckVoltage();
		power.PowerDown();
	}
};

int choice()
{
	cout << "1. Begin work" << endl << "2. End work" << endl;
	int choice;
	cin >> choice;
	return choice;
}

int main()
{
	Facade computer;
	cout << "To start press any button..." << endl;
	while (_getch() != 27)
	{		
		switch (choice())
		{
		case 1:
			computer.BeginWork();
			break;
		case 2:
			computer.EndWork();
			break;
		default:
			cout << "Error!" << endl;
			break;
		}
	}

	return 0;
}