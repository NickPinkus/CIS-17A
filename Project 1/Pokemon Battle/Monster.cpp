#include "Monster.h"
#include <iostream>
using namespace std;



string Monster::SetName()
{
	switch (ID)
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
