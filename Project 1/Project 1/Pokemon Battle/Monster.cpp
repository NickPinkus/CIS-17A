#include "Monster.h"
#include <iostream>
using namespace std;


string Monster::GetName()
{
	return _name;
}

void Monster::SetInfo()
{
	health = 10;
	attack = 10;
	defense = 5;

	switch (monsterID)
	{
	case 0:
		_name = "Bulbasaur";
		break;
	case 1:
		_name = "Charmander";
		break;
	case 2:
		_name = "Squirtle";
		break;
	case 3:
		_name = "Pikachu";
		break;
	case 4:
		_name = "Eevee";
		break;
	default:
		_name = "DEFAULT";
	}

	maxHealth = health;
}

int Monster::GetHealth()
{

	return health;
}

int Monster::GetMaxHealth()
{
	return maxHealth;
}

Monster::Monster()
{
}


Monster::~Monster()
{
}

void Monster::SetIDNum(int InputID)
{
	monsterID = InputID;
}
