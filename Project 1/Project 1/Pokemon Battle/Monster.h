#pragma once
#include "Attacks.h"
#include <string>
using namespace std;

class Monster
{
private:
	string _name,
		type;
	int health,
		attack,
		defense;
public:
	Monster(int ID);
	~Monster();

	int ID;

	string GetName();
};

