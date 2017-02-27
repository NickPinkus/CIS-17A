#pragma once
#include "Monster.h"
#include "Items.h"

class Trainer
{
private:
	string _name;

public:
	Trainer(string _name, int monsterID);
	~Trainer();

	int monsterID;

	Monster Pokemon = Monster(monsterID);

	string GetName();

};

