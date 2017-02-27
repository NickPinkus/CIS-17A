#pragma once
#include "Monster.h"

class Trainer
{
private:
	string _name;
	Monster trainerMonster;

public:
	Trainer(string _name);
	~Trainer();

	void monsterSetID(int ID);
	string monsterGetName();
	string GetName();
};

