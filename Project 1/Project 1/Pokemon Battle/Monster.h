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
		maxHealth,
		attack,
		defense,
		monsterID;
public:
	Monster();
	~Monster();

	void SetIDNum(int InputID);

	string GetName();
	void SetInfo();
	int GetHealth();
	int GetMaxHealth();
};

