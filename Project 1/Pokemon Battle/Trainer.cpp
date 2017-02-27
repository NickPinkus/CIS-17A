#include "Trainer.h"
#include <iostream>
using namespace std;


Trainer::Trainer(string name) : _name(name)
{
}


Trainer::~Trainer()
{
}

void Trainer::monsterSetID(int ID)
{
	trainerMonster.ID = ID;
	trainerMonster.SetName();
}

string Trainer::monsterGetName()
{

	return trainerMonster.GetName();
}

string Trainer::GetName()
{
	return _name;
}

