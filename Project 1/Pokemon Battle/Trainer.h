#pragma once
#include <string>
#include "Monster.h"
using namespace std;

class Trainer
{
private:
	string _name;

public:
	Trainer(string _name);
	~Trainer();
	Monster monster;

	string GetName();
};

