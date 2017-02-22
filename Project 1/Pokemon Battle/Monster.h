#pragma once
#include <string>
using namespace std;

class Monster
{
private:
	string _name,
		type,
		attack,
		defense;
public:
	string GetName();
	Monster();
	~Monster();
	int ID;
};

