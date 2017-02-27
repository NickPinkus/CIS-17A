#include "Trainer.h"
#include <iostream>
using namespace std;


Trainer::Trainer(string name) : _name(name)
{
}


Trainer::~Trainer()
{
}

void Trainer::monsterSetInfo(int ID)
{
	Pokemon.ID = ID;
	Pokemon.SetInfo();
}

string Trainer::monsterGetName()
{

	return Pokemon.GetName();
}

string Trainer::GetName()
{
	return _name;
}

