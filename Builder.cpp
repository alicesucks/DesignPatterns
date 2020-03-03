#include <iostream>
using namespace std;

class Auto
{
	string name;
	string corpus;
	float engine;
	int wheels;
	string transmission;
public:
	string GetName()
	{
		return name;
	}
	void SetName(string name)
	{
		this->name = name;
	}
	string GetCorpus()
	{
		return corpus;
	}
	void SetCorpus(string corpus)
	{
		this->corpus = corpus;
	}
	float GetEngine()
	{
		return engine;
	}
	void SetEngine(float engine)
	{
		this->engine = engine;
	}
	int GetWheels()
	{
		return wheels;
	}
	void SetWheels(int wheels)
	{
		this->wheels = wheels;
	}
	string GetTransmission()
	{
		return transmission;
	}
	void SetTransmission(string transmission)
	{
		this->transmission = transmission;
	}
	void ShowAuto()
	{
		cout << "Name: " << name << endl << "Corpus: " << corpus << endl
			<< "Engine: " << engine << " l" << endl << "Wheels: " << wheels << " r" << endl
			<< "Transmission: " << transmission << endl << endl;
	}
};

class AutoBuilder abstract
{
protected:
	Auto automobile;
public:
	Auto GetAuto()
	{
		return automobile;
	}
	virtual void BuildName() = 0;
	virtual void BuildCorpus() = 0;
	virtual void BuildEngine() = 0;
	virtual void BuildWheels() = 0;
	virtual void BuildTransmission() = 0;
};

class DaewooLanosBuilder :public AutoBuilder
{
public:
	void BuildName() override
	{
		automobile.SetName("Daewoo Lanos");
	}
	void BuildCorpus () override
	{
		automobile.SetCorpus("Sedan");
	}
	void BuildEngine() override
	{
		automobile.SetEngine(98);
	}
	void BuildWheels() override
	{
		automobile.SetWheels(13);
	}
	void BuildTransmission() override
	{
		automobile.SetTransmission("5 Manual");
	}
};

class FordProbeBuilder :public AutoBuilder
{
	void BuildName() override
	{
		automobile.SetName("Ford Probe");
	}
	void BuildCorpus() override
	{
		automobile.SetCorpus("Coupe");
	}
	void BuildEngine() override
	{
		automobile.SetEngine(160);
	}
	void BuildWheels() override
	{
		automobile.SetWheels(14);
	}
	void BuildTransmission() override
	{
		automobile.SetTransmission("4 Auto");
	}
};

class UAZPatriotBuilder :public AutoBuilder
{
	void BuildName() override
	{
		automobile.SetName("UAZ Patriot");
	}
	void BuildCorpus() override
	{
		automobile.SetCorpus("Universal");
	}
	void BuildEngine() override
	{
		automobile.SetEngine(120);
	}
	void BuildWheels() override
	{
		automobile.SetWheels(16);
	}
	void BuildTransmission() override
	{
		automobile.SetTransmission("4 Manual");
	}
};

class HyundaiGetzBuilder :public AutoBuilder
{
	void BuildName() override
	{
		automobile.SetName("Hyundai Getz");
	}
	void BuildCorpus() override
	{
		automobile.SetCorpus("Hatchback");
	}
	void BuildEngine() override
	{
		automobile.SetEngine(66);
	}
	void BuildWheels() override
	{
		automobile.SetWheels(13);
	}
	void BuildTransmission() override
	{
		automobile.SetTransmission("4 Auto");
	}
};

class Shop
{
	AutoBuilder* autobuilder;
public:
	void SetAutoBuilder(AutoBuilder* ab)
	{
		autobuilder = ab;
	}
	Auto GetAuto()
	{
		return autobuilder->GetAuto();
	}
	void ConstructAuto()
	{
		autobuilder->BuildName();
		autobuilder->BuildCorpus();
		autobuilder->BuildEngine();
		autobuilder->BuildWheels();
		autobuilder->BuildTransmission();
	}
};

void client(AutoBuilder* builder)
{
	Shop shop;
	shop.SetAutoBuilder(builder);
	shop.ConstructAuto();
	Auto automobile = shop.GetAuto();
	automobile.ShowAuto();
}

int main()
{
	AutoBuilder* builder = new DaewooLanosBuilder;
	client(builder);
	delete builder;
	builder = new FordProbeBuilder;
	client(builder);
	delete builder;
	builder = new UAZPatriotBuilder;
	client(builder);
	delete builder;
	builder = new HyundaiGetzBuilder;
	client(builder);
	delete builder;

	return 0;
}