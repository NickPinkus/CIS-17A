#pragma once
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
	string SetName();
	string GetName();
	Monster();
	~Monster();
	int ID;
};

