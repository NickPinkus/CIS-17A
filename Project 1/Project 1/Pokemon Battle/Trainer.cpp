#include "Trainer.h"
#include <iostream>
using namespace std;


Trainer::Trainer(string name, int monsterID)
{
	_name = name;
	Pokemon.ID = monsterID;
}


Trainer::~Trainer()
{
}



string Trainer::GetName()
{
	return _name;
}

