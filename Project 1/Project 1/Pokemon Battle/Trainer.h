#pragma once
#include "Monster.h"
#include "Items.h"

class Trainer
{
private:
	string _name;

public:
	Trainer(string _name);
	~Trainer();


	Monster Pokemon = Monster();

	string GetName();

};

