#include "Monster.h"
#include <iostream>
using namespace std;



string Monster::SetInfo()
{
	switch (ID)
	{
	case 0:
		_name = "Bulbasaur";
		attack = 5;
		defense = 5;
		health = 5;
		break;
	case 1:
		_name = "Charmander";
		attack = 5;
		defense = 5;
		health = 5;
		break;
	case 2:
		_name = "Squirtle";
		attack = 5;
		defense = 5;
		health = 5;
		break;
	case 3:
		_name = "Pikachu";
		attack = 5;
		defense = 5;
		health = 5;
		break;
	case 4:
		_name = "Eevee";
		attack = 5;
		defense = 5;
		health = 5;
		break;
	default:
		_name = "MISSINGNO.";
		attack = 0;
		defense = 0;
		health = 0;
	}
	return _name;
}

string Monster::GetName()
{
	return _name;
}

Monster::Monster()
{
	health = 10;
	attack = 5;
	defense = 5;
}


Monster::~Monster()
{
}
