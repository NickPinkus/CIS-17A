#pragma once
#include "Monster.h"

class Trainer
{
private:
	string _name;
	Monster Pokemon;

public:
	Trainer(string _name);
	~Trainer();

	void monsterSetInfo(int ID);
	string monsterGetName();
	string GetName();
};

